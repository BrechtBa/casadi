import casadi.*
addpath('defs')

x = MX.sym('x');

foo = MyCallback('foo');

y = foo.newcall(x);

f = Function('f',{x},{y});

out = f.newcall(5)

assert(abs(full(out)-25)<1e-12)

%%%%%%%% SVD example

n = 3;
m = 3;
foo = MySVD('foo', n, m, true);

rng(0);

x = rand(n,m);
X = MX.sym('x',n,m);
Y = foo.newcall(X);

