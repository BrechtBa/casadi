from pylab import *
from scipy.linalg import sqrtm

from casadi import *
from casadi.tools import *

# System states
states = struct_symSX(["x","y","dx","dy"])
x,y,dx,dy = states[...]
    
# System controls
controls = struct_symSX(["u","v"])
u,v = controls[...]

# System parameters
parameters = struct_symSX(["k","c","beta"])
k,c,beta = parameters[...]

# Provide some numerical values
parameters_ = parameters()
parameters_["k"] = 10
parameters_["beta"] = 1
parameters_["c"] = 1

vel = vertcat([dx,dy])
p = vertcat([x,y])
q = vertcat([u,v])

# System dynamics
F = -k*(p-q) - beta*v*sqrt(sumAll(vel**2)+c**2)

# System right hand side
rhs = struct_SX(states)
rhs["x"]  = dx
rhs["y"]  = dy
rhs["dx"] = F[0]
rhs["dy"] = F[1]

f = SXFunction(controldaeIn(x=states,p=parameters,u=controls),daeOut(ode=rhs))
f.init()


# Simulation output grid
N = 100
tgrid = linspace(0,10.0,N)

# ControlSimulator will output on each node of the timegrid
csim = ControlSimulator(f,tgrid)
csim.setOption("integrator",CVodesIntegrator)
csim.setOption("integrator_options",{"abstol":1e-10,"reltol":1e-10})
csim.init()

x0 = states(0)

# Create input profile
controls_ = controls.repeated(csim.getInput("u"))
controls_[0,"u"] = 1     # Kick the system with u=1 at the start
controls_[N/2,"v"] = 2   # Kick the system with v=2 at half the simulation time

# Pure simulation
csim.setInput(x0,"x0")
csim.setInput(parameters_,"p")
csim.setInput(controls_,"u")
csim.evaluate()

output = states.repeated(csim.getOutput())

# Plot all states
for k in states.keys():
  plot(tgrid,output[vertcat,:,k])
xlabel("t")
legend(tuple(states.keys()))

print "xf=", output[-1]

# The remainder of this file deals with methods to calculate the state covariance matrix as it propagates through the system dynamics

# === Method 1: integrator sensitivity ===
# PF = d(I)/d(x0) P0 [d(I)/d(x0)]^T
  
P0 = states.squared()
P0[:,:] = 0.01*DMatrix.eye(states.size)
P0["x","dy"] = P0["dy","x"] = 0.002

# Not supported in current revision, cf. #929
# J = csim.jacobian("x0","xf")
# J.init()
# J.setInput(x0,"x0")
# J.setInput(parameters_,"p")
# J.setInput(controls_,"u")
# J.evaluate()

# Jk = states.squared_repeated(J.getOutput())
# F = Jk[-1]

# PF_method1 = mul([F,P0,F.T])

# print "State cov (method 1) = ", PF_method1

# === Method 2: Lyapunov equations ===
#  P' = A.P + P.A^T
states_aug = struct_symSX([
  entry("orig",sym=states),
  entry("P",shapestruct=(states,states))
])

A = jacobian(rhs,states)

rhs_aug = struct_SX(states_aug)
rhs_aug["orig"]  = rhs
rhs_aug["P"]  = mul(A,states_aug["P"]) + mul(states_aug["P"],A.T)

f_aug = SXFunction(controldaeIn(x=states_aug,p=parameters,u=controls),daeOut(ode=rhs_aug))
f_aug.init()

csim_aug = ControlSimulator(f_aug,tgrid)
csim_aug.setOption("integrator",CVodesIntegrator)
csim_aug.init()

states_aug(csim_aug.input("x0"))["orig"] = x0
states_aug(csim_aug.input("x0"))["P"] = P0

csim_aug.setInput(parameters_,"p")
csim_aug.setInput(controls_,"u")
csim_aug.evaluate()

output = states_aug.repeated(csim_aug.getOutput())

PF_method2 = output[-1,"P"]

print "State cov (method 2) = ", PF_method2

# === Method 3:  Unscented propagation ===
# Sample and simulate 2n+1 initial points
n = states.size

W0 = 0
x0 = DMatrix(x0)
W = DMatrix([  W0 ] + [(1.0-W0)/2/n for j in range(2*n)])

sqm = sqrtm(n/(1.0-W0)*DMatrix(P0)).real
sample_x = [ x0 ] + [x0+sqm[:,i] for i in range(n)] + [x0-sqm[:,i] for i in range(n)]

csim.setInput(parameters_,"p")
csim.setInput(controls_,"u")

simulated_x = [] # This can be parallelised
for x0_ in sample_x:
  csim.setInput(x0_,"x0")
  csim.evaluate()
  simulated_x.append(csim.getOutput()[-1,:])
  
simulated_x = vertcat(simulated_x).T

Xf_mean = mul(simulated_x,W)

x_dev = simulated_x-mul(Xf_mean,DMatrix.ones(1,2*n+1))

PF_method3 = mul([x_dev,diag(W),x_dev.T])
print "State cov (method 3) = ", PF_method3

show()