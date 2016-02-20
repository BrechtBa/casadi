/// \cond INTERNAL
/** \class casadi::ClangCompiler
\n
\par
<a name='options'></a><table>
<caption>List of available options</caption>
<tr><th>Id</th><th>Type</th><th>Description</th><th>Used in</th></tr>
<tr><td>flags</td><td>OT_STRINGVECTOR</td><td>Compile flags for the JIT compiler. Default: None</td><td>casadi::ClangCompiler</td></tr>
<tr><td>include_path</td><td>OT_STRING</td><td>Include paths for the JIT compiler. The include directory shipped with CasADi will be automatically appended.</td><td>casadi::ClangCompiler</td></tr>
</table>
*/
/// \endcond
/** \addtogroup plugin_Compiler_clang
\n
\par
<a name='options'></a><table>
<caption>List of available options</caption>
<tr><th>Id</th><th>Type</th><th>Description</th></tr>
<tr><td>flags</td><td>OT_STRINGVECTOR</td><td>Compile flags for the JIT compiler. Default: None</td></tr>
<tr><td>include_path</td><td>OT_STRING</td><td>Include paths for the JIT compiler. The include directory shipped with CasADi will be automatically appended.</td></tr>
</table>
*/
/** \addtogroup general_ClangCompiler
\n
\par
<a name='options'></a><table>
<caption>List of available options</caption>
<tr><th>Id</th><th>Type</th><th>Description</th><th>Used in</th></tr>
<tr><td>flags</td><td>OT_STRINGVECTOR</td><td>Compile flags for the JIT compiler. Default: None</td><td>casadi::ClangCompiler</td></tr>
<tr><td>include_path</td><td>OT_STRING</td><td>Include paths for the JIT compiler. The include directory shipped with CasADi will be automatically appended.</td><td>casadi::ClangCompiler</td></tr>
</table>
*/
/// \cond INTERNAL
/** \class casadi::CollocationIntegrator
\n
\par
<a name='options'></a><table>
<caption>List of available options</caption>
<tr><th>Id</th><th>Type</th><th>Description</th><th>Used in</th></tr>
<tr><td>augmented_options</td><td>OT_DICT</td><td>Options to be passed down to the augmented integrator, if one is constructed.</td><td>casadi::ImplicitFixedStepIntegrator</td></tr>
<tr><td>collocation_scheme</td><td>OT_STRING</td><td>Collocation scheme: radau|legendre</td><td>casadi::CollocationIntegrator</td></tr>
<tr><td>expand</td><td>OT_BOOL</td><td>Replace MX with SX expressions in problem formulation [false]</td><td>casadi::ImplicitFixedStepIntegrator</td></tr>
<tr><td>grid</td><td>OT_DOUBLEVECTOR</td><td>Time grid</td><td>casadi::ImplicitFixedStepIntegrator</td></tr>
<tr><td>interpolation_order</td><td>OT_INT</td><td>Order of the interpolating polynomials</td><td>casadi::CollocationIntegrator</td></tr>
<tr><td>number_of_finite_elements</td><td>OT_INT</td><td>Number of finite elements</td><td>casadi::ImplicitFixedStepIntegrator</td></tr>
<tr><td>output_t0</td><td>OT_BOOL</td><td>Output the state at the initial time</td><td>casadi::ImplicitFixedStepIntegrator</td></tr>
<tr><td>print_stats</td><td>OT_BOOL</td><td>Print out statistics after integration</td><td>casadi::ImplicitFixedStepIntegrator</td></tr>
<tr><td>rootfinder</td><td>OT_STRING</td><td>An implicit function solver</td><td>casadi::ImplicitFixedStepIntegrator</td></tr>
<tr><td>rootfinder_options</td><td>OT_DICT</td><td>Options to be passed to the NLP Solver</td><td>casadi::ImplicitFixedStepIntegrator</td></tr>
<tr><td>t0</td><td>OT_DOUBLE</td><td>Beginning of the time horizon</td><td>casadi::ImplicitFixedStepIntegrator</td></tr>
<tr><td>tf</td><td>OT_DOUBLE</td><td>End of the time horizon</td><td>casadi::ImplicitFixedStepIntegrator</td></tr>
</table>
*/
/// \endcond
/** \addtogroup plugin_Integrator_collocation
\n
\par
<a name='options'></a><table>
<caption>List of available options</caption>
<tr><th>Id</th><th>Type</th><th>Description</th></tr>
<tr><td>augmented_options</td><td>OT_DICT</td><td>Options to be passed down to the augmented integrator, if one is constructed.</td></tr>
<tr><td>collocation_scheme</td><td>OT_STRING</td><td>Collocation scheme: radau|legendre</td></tr>
<tr><td>expand</td><td>OT_BOOL</td><td>Replace MX with SX expressions in problem formulation [false]</td></tr>
<tr><td>grid</td><td>OT_DOUBLEVECTOR</td><td>Time grid</td></tr>
<tr><td>interpolation_order</td><td>OT_INT</td><td>Order of the interpolating polynomials</td></tr>
<tr><td>number_of_finite_elements</td><td>OT_INT</td><td>Number of finite elements</td></tr>
<tr><td>output_t0</td><td>OT_BOOL</td><td>Output the state at the initial time</td></tr>
<tr><td>print_stats</td><td>OT_BOOL</td><td>Print out statistics after integration</td></tr>
<tr><td>rootfinder</td><td>OT_STRING</td><td>An implicit function solver</td></tr>
<tr><td>rootfinder_options</td><td>OT_DICT</td><td>Options to be passed to the NLP Solver</td></tr>
<tr><td>t0</td><td>OT_DOUBLE</td><td>Beginning of the time horizon</td></tr>
<tr><td>tf</td><td>OT_DOUBLE</td><td>End of the time horizon</td></tr>
</table>
*/
/** \addtogroup general_CollocationIntegrator
\n
\par
<a name='options'></a><table>
<caption>List of available options</caption>
<tr><th>Id</th><th>Type</th><th>Description</th><th>Used in</th></tr>
<tr><td>augmented_options</td><td>OT_DICT</td><td>Options to be passed down to the augmented integrator, if one is constructed.</td><td>casadi::ImplicitFixedStepIntegrator</td></tr>
<tr><td>collocation_scheme</td><td>OT_STRING</td><td>Collocation scheme: radau|legendre</td><td>casadi::CollocationIntegrator</td></tr>
<tr><td>expand</td><td>OT_BOOL</td><td>Replace MX with SX expressions in problem formulation [false]</td><td>casadi::ImplicitFixedStepIntegrator</td></tr>
<tr><td>grid</td><td>OT_DOUBLEVECTOR</td><td>Time grid</td><td>casadi::ImplicitFixedStepIntegrator</td></tr>
<tr><td>interpolation_order</td><td>OT_INT</td><td>Order of the interpolating polynomials</td><td>casadi::CollocationIntegrator</td></tr>
<tr><td>number_of_finite_elements</td><td>OT_INT</td><td>Number of finite elements</td><td>casadi::ImplicitFixedStepIntegrator</td></tr>
<tr><td>output_t0</td><td>OT_BOOL</td><td>Output the state at the initial time</td><td>casadi::ImplicitFixedStepIntegrator</td></tr>
<tr><td>print_stats</td><td>OT_BOOL</td><td>Print out statistics after integration</td><td>casadi::ImplicitFixedStepIntegrator</td></tr>
<tr><td>rootfinder</td><td>OT_STRING</td><td>An implicit function solver</td><td>casadi::ImplicitFixedStepIntegrator</td></tr>
<tr><td>rootfinder_options</td><td>OT_DICT</td><td>Options to be passed to the NLP Solver</td><td>casadi::ImplicitFixedStepIntegrator</td></tr>
<tr><td>t0</td><td>OT_DOUBLE</td><td>Beginning of the time horizon</td><td>casadi::ImplicitFixedStepIntegrator</td></tr>
<tr><td>tf</td><td>OT_DOUBLE</td><td>End of the time horizon</td><td>casadi::ImplicitFixedStepIntegrator</td></tr>
</table>
*/
/// \cond INTERNAL
/** \class casadi::CplexInterface
\n
\par
<a name='options'></a><table>
<caption>List of available options</caption>
<tr><th>Id</th><th>Type</th><th>Description</th><th>Used in</th></tr>
<tr><td>cplex</td><td>OT_DICT</td><td>Options to be passed to CPLEX</td><td>casadi::CplexInterface</td></tr>
<tr><td>dep_check</td><td>OT_INT</td><td>Detect redundant constraints.</td><td>casadi::CplexInterface</td></tr>
<tr><td>discrete</td><td>OT_BOOLVECTOR</td><td>Indicates which of the variables are discrete, i.e. integer-valued</td><td>casadi::Qpsol</td></tr>
<tr><td>dump_filename</td><td>OT_STRING</td><td>The filename to dump to.</td><td>casadi::CplexInterface</td></tr>
<tr><td>dump_to_file</td><td>OT_BOOL</td><td>Dumps QP to file in CPLEX format.</td><td>casadi::CplexInterface</td></tr>
<tr><td>qp_method</td><td>OT_INT</td><td>Determines which CPLEX algorithm to use.</td><td>casadi::CplexInterface</td></tr>
<tr><td>tol</td><td>OT_DOUBLE</td><td>Tolerance of solver</td><td>casadi::CplexInterface</td></tr>
<tr><td>warm_start</td><td>OT_BOOL</td><td>Use warm start with simplex methods (affects only the simplex methods).</td><td>casadi::CplexInterface</td></tr>
</table>
*/
/// \endcond
/** \addtogroup plugin_Qpsol_cplex
\n
\par
<a name='options'></a><table>
<caption>List of available options</caption>
<tr><th>Id</th><th>Type</th><th>Description</th></tr>
<tr><td>cplex</td><td>OT_DICT</td><td>Options to be passed to CPLEX</td></tr>
<tr><td>dep_check</td><td>OT_INT</td><td>Detect redundant constraints.</td></tr>
<tr><td>dump_filename</td><td>OT_STRING</td><td>The filename to dump to.</td></tr>
<tr><td>dump_to_file</td><td>OT_BOOL</td><td>Dumps QP to file in CPLEX format.</td></tr>
<tr><td>qp_method</td><td>OT_INT</td><td>Determines which CPLEX algorithm to use.</td></tr>
<tr><td>tol</td><td>OT_DOUBLE</td><td>Tolerance of solver</td></tr>
<tr><td>warm_start</td><td>OT_BOOL</td><td>Use warm start with simplex methods (affects only the simplex methods).</td></tr>
</table>
*/
/** \addtogroup general_CplexInterface
\n
\par
<a name='options'></a><table>
<caption>List of available options</caption>
<tr><th>Id</th><th>Type</th><th>Description</th><th>Used in</th></tr>
<tr><td>cplex</td><td>OT_DICT</td><td>Options to be passed to CPLEX</td><td>casadi::CplexInterface</td></tr>
<tr><td>dep_check</td><td>OT_INT</td><td>Detect redundant constraints.</td><td>casadi::CplexInterface</td></tr>
<tr><td>discrete</td><td>OT_BOOLVECTOR</td><td>Indicates which of the variables are discrete, i.e. integer-valued</td><td>casadi::Qpsol</td></tr>
<tr><td>dump_filename</td><td>OT_STRING</td><td>The filename to dump to.</td><td>casadi::CplexInterface</td></tr>
<tr><td>dump_to_file</td><td>OT_BOOL</td><td>Dumps QP to file in CPLEX format.</td><td>casadi::CplexInterface</td></tr>
<tr><td>qp_method</td><td>OT_INT</td><td>Determines which CPLEX algorithm to use.</td><td>casadi::CplexInterface</td></tr>
<tr><td>tol</td><td>OT_DOUBLE</td><td>Tolerance of solver</td><td>casadi::CplexInterface</td></tr>
<tr><td>warm_start</td><td>OT_BOOL</td><td>Use warm start with simplex methods (affects only the simplex methods).</td><td>casadi::CplexInterface</td></tr>
</table>
*/
/// \cond INTERNAL
/** \class casadi::CvodesInterface
\n
\par
<a name='options'></a><table>
<caption>List of available options</caption>
<tr><th>Id</th><th>Type</th><th>Description</th><th>Used in</th></tr>
<tr><td>abstol</td><td>OT_DOUBLE</td><td>Absolute tolerence  for the IVP solution</td><td>casadi::SundialsInterface</td></tr>
<tr><td>abstolB</td><td>OT_DOUBLE</td><td>Absolute tolerence for the adjoint sensitivity solution [default: equal to abstol]</td><td>casadi::SundialsInterface</td></tr>
<tr><td>disable_internal_warnings</td><td>OT_BOOL</td><td>Disable SUNDIALS internal warning messages</td><td>casadi::SundialsInterface</td></tr>
<tr><td>exact_jacobian</td><td>OT_BOOL</td><td>Use exact Jacobian information for the forward integration</td><td>casadi::SundialsInterface</td></tr>
<tr><td>exact_jacobianB</td><td>OT_BOOL</td><td>Use exact Jacobian information for the backward integration [default: equal to exact_jacobian]</td><td>casadi::SundialsInterface</td></tr>
<tr><td>finite_difference_fsens</td><td>OT_BOOL</td><td>Use finite differences to approximate the forward sensitivity equations (if AD is not available)</td><td>casadi::SundialsInterface</td></tr>
<tr><td>fsens_abstol</td><td>OT_DOUBLE</td><td>Absolute tolerence for the forward sensitivity solution [default: equal to abstol]</td><td>casadi::SundialsInterface</td></tr>
<tr><td>fsens_all_at_once</td><td>OT_BOOL</td><td>Calculate all right hand sides of the sensitivity equations at once</td><td>casadi::CvodesInterface</td></tr>
<tr><td>fsens_err_con</td><td>OT_BOOL</td><td>include the forward sensitivities in all error controls</td><td>casadi::SundialsInterface</td></tr>
<tr><td>fsens_reltol</td><td>OT_DOUBLE</td><td>Relative tolerence for the forward sensitivity solution [default: equal to reltol]</td><td>casadi::SundialsInterface</td></tr>
<tr><td>fsens_scaling_factors</td><td>OT_DOUBLEVECTOR</td><td>Scaling factor for the components if finite differences is used</td><td>casadi::SundialsInterface</td></tr>
<tr><td>fsens_sensitiviy_parameters</td><td>OT_INTVECTOR</td><td>Specifies which components will be used when estimating the sensitivity equations</td><td>casadi::SundialsInterface</td></tr>
<tr><td>interpolation_type</td><td>OT_STRING</td><td>Type of interpolation for the adjoint sensitivities</td><td>casadi::SundialsInterface</td></tr>
<tr><td>iterative_solver</td><td>OT_STRING</td><td>Iterative solver: GMRES|bcgstab|tfqmr</td><td>casadi::SundialsInterface</td></tr>
<tr><td>iterative_solverB</td><td>OT_STRING</td><td>Iterative solver for backward integration</td><td>casadi::SundialsInterface</td></tr>
<tr><td>linear_multistep_method</td><td>OT_STRING</td><td>Integrator scheme: BDF|adams</td><td>casadi::CvodesInterface</td></tr>
<tr><td>linear_solver</td><td>OT_STRING</td><td>A custom linear solver creator function</td><td>casadi::SundialsInterface</td></tr>
<tr><td>linear_solverB</td><td>OT_STRING</td><td>A custom linear solver creator function for backwards integration [default: equal to linear_solver]</td><td>casadi::SundialsInterface</td></tr>
<tr><td>linear_solver_options</td><td>OT_DICT</td><td>Options to be passed to the linear solver</td><td>casadi::SundialsInterface</td></tr>
<tr><td>linear_solver_optionsB</td><td>OT_DICT</td><td>Options to be passed to the linear solver for backwards integration [default: equal to linear_solver_options]</td><td>casadi::SundialsInterface</td></tr>
<tr><td>linear_solver_type</td><td>OT_STRING</td><td>Type of iterative solver: user_defined|DENSE|banded|iterative</td><td>casadi::SundialsInterface</td></tr>
<tr><td>linear_solver_typeB</td><td>OT_STRING</td><td>Linear solver for backward integration</td><td>casadi::SundialsInterface</td></tr>
<tr><td>lower_bandwidth</td><td>OT_INT</td><td>Lower band-width of banded Jacobian (estimations)</td><td>casadi::SundialsInterface</td></tr>
<tr><td>lower_bandwidthB</td><td>OT_INT</td><td>lower band-width of banded jacobians for backward integration [default: equal to lower_bandwidth]</td><td>casadi::SundialsInterface</td></tr>
<tr><td>max_krylov</td><td>OT_INT</td><td>Maximum Krylov subspace size</td><td>casadi::SundialsInterface</td></tr>
<tr><td>max_krylovB</td><td>OT_INT</td><td>Maximum krylov subspace size for backward integration</td><td>casadi::SundialsInterface</td></tr>
<tr><td>max_multistep_order</td><td>OT_INT</td><td>Maximum order for the (variable-order) multistep method</td><td>casadi::SundialsInterface</td></tr>
<tr><td>max_num_steps</td><td>OT_INT</td><td>Maximum number of integrator steps</td><td>casadi::SundialsInterface</td></tr>
<tr><td>nonlinear_solver_iteration</td><td>OT_STRING</td><td>Nonlinear solver type: NEWTON|functional</td><td>casadi::CvodesInterface</td></tr>
<tr><td>pretype</td><td>OT_STRING</td><td>Type of preconditioning: NONE|left|right|both</td><td>casadi::SundialsInterface</td></tr>
<tr><td>pretypeB</td><td>OT_STRING</td><td>Preconditioner for backward integration</td><td>casadi::SundialsInterface</td></tr>
<tr><td>quad_err_con</td><td>OT_BOOL</td><td>Should the quadratures affect the step size control</td><td>casadi::SundialsInterface</td></tr>
<tr><td>reltol</td><td>OT_DOUBLE</td><td>Relative tolerence for the IVP solution</td><td>casadi::SundialsInterface</td></tr>
<tr><td>reltolB</td><td>OT_DOUBLE</td><td>Relative tolerence for the adjoint sensitivity solution [default: equal to reltol]</td><td>casadi::SundialsInterface</td></tr>
<tr><td>sensitivity_method</td><td>OT_STRING</td><td>Sensitivity method: SIMULTANEOUS|staggered</td><td>casadi::SundialsInterface</td></tr>
<tr><td>steps_per_checkpoint</td><td>OT_INT</td><td>Number of steps between two consecutive checkpoints</td><td>casadi::SundialsInterface</td></tr>
<tr><td>stop_at_end</td><td>OT_BOOL</td><td>Stop the integrator at the end of the interval</td><td>casadi::SundialsInterface</td></tr>
<tr><td>upper_bandwidth</td><td>OT_INT</td><td>Upper band-width of banded Jacobian (estimations)</td><td>casadi::SundialsInterface</td></tr>
<tr><td>upper_bandwidthB</td><td>OT_INT</td><td>Upper band-width of banded jacobians for backward integration [default: equal to upper_bandwidth]</td><td>casadi::SundialsInterface</td></tr>
<tr><td>use_preconditioner</td><td>OT_BOOL</td><td>Precondition an iterative solver</td><td>casadi::SundialsInterface</td></tr>
<tr><td>use_preconditionerB</td><td>OT_BOOL</td><td>Precondition an iterative solver for the backwards problem [default: equal to use_preconditioner]</td><td>casadi::SundialsInterface</td></tr>
</table>
*/
/// \endcond
/** \addtogroup plugin_Integrator_cvodes
\n
\par
<a name='options'></a><table>
<caption>List of available options</caption>
<tr><th>Id</th><th>Type</th><th>Description</th></tr>
<tr><td>abstol</td><td>OT_DOUBLE</td><td>Absolute tolerence  for the IVP solution</td></tr>
<tr><td>abstolB</td><td>OT_DOUBLE</td><td>Absolute tolerence for the adjoint sensitivity solution [default: equal to abstol]</td></tr>
<tr><td>disable_internal_warnings</td><td>OT_BOOL</td><td>Disable SUNDIALS internal warning messages</td></tr>
<tr><td>exact_jacobian</td><td>OT_BOOL</td><td>Use exact Jacobian information for the forward integration</td></tr>
<tr><td>exact_jacobianB</td><td>OT_BOOL</td><td>Use exact Jacobian information for the backward integration [default: equal to exact_jacobian]</td></tr>
<tr><td>finite_difference_fsens</td><td>OT_BOOL</td><td>Use finite differences to approximate the forward sensitivity equations (if AD is not available)</td></tr>
<tr><td>fsens_abstol</td><td>OT_DOUBLE</td><td>Absolute tolerence for the forward sensitivity solution [default: equal to abstol]</td></tr>
<tr><td>fsens_all_at_once</td><td>OT_BOOL</td><td>Calculate all right hand sides of the sensitivity equations at once</td></tr>
<tr><td>fsens_err_con</td><td>OT_BOOL</td><td>include the forward sensitivities in all error controls</td></tr>
<tr><td>fsens_reltol</td><td>OT_DOUBLE</td><td>Relative tolerence for the forward sensitivity solution [default: equal to reltol]</td></tr>
<tr><td>fsens_scaling_factors</td><td>OT_DOUBLEVECTOR</td><td>Scaling factor for the components if finite differences is used</td></tr>
<tr><td>fsens_sensitiviy_parameters</td><td>OT_INTVECTOR</td><td>Specifies which components will be used when estimating the sensitivity equations</td></tr>
<tr><td>interpolation_type</td><td>OT_STRING</td><td>Type of interpolation for the adjoint sensitivities</td></tr>
<tr><td>iterative_solver</td><td>OT_STRING</td><td>Iterative solver: GMRES|bcgstab|tfqmr</td></tr>
<tr><td>iterative_solverB</td><td>OT_STRING</td><td>Iterative solver for backward integration</td></tr>
<tr><td>linear_multistep_method</td><td>OT_STRING</td><td>Integrator scheme: BDF|adams</td></tr>
<tr><td>linear_solver</td><td>OT_STRING</td><td>A custom linear solver creator function</td></tr>
<tr><td>linear_solverB</td><td>OT_STRING</td><td>A custom linear solver creator function for backwards integration [default: equal to linear_solver]</td></tr>
<tr><td>linear_solver_options</td><td>OT_DICT</td><td>Options to be passed to the linear solver</td></tr>
<tr><td>linear_solver_optionsB</td><td>OT_DICT</td><td>Options to be passed to the linear solver for backwards integration [default: equal to linear_solver_options]</td></tr>
<tr><td>linear_solver_type</td><td>OT_STRING</td><td>Type of iterative solver: user_defined|DENSE|banded|iterative</td></tr>
<tr><td>linear_solver_typeB</td><td>OT_STRING</td><td>Linear solver for backward integration</td></tr>
<tr><td>lower_bandwidth</td><td>OT_INT</td><td>Lower band-width of banded Jacobian (estimations)</td></tr>
<tr><td>lower_bandwidthB</td><td>OT_INT</td><td>lower band-width of banded jacobians for backward integration [default: equal to lower_bandwidth]</td></tr>
<tr><td>max_krylov</td><td>OT_INT</td><td>Maximum Krylov subspace size</td></tr>
<tr><td>max_krylovB</td><td>OT_INT</td><td>Maximum krylov subspace size for backward integration</td></tr>
<tr><td>max_multistep_order</td><td>OT_INT</td><td>Maximum order for the (variable-order) multistep method</td></tr>
<tr><td>max_num_steps</td><td>OT_INT</td><td>Maximum number of integrator steps</td></tr>
<tr><td>nonlinear_solver_iteration</td><td>OT_STRING</td><td>Nonlinear solver type: NEWTON|functional</td></tr>
<tr><td>pretype</td><td>OT_STRING</td><td>Type of preconditioning: NONE|left|right|both</td></tr>
<tr><td>pretypeB</td><td>OT_STRING</td><td>Preconditioner for backward integration</td></tr>
<tr><td>quad_err_con</td><td>OT_BOOL</td><td>Should the quadratures affect the step size control</td></tr>
<tr><td>reltol</td><td>OT_DOUBLE</td><td>Relative tolerence for the IVP solution</td></tr>
<tr><td>reltolB</td><td>OT_DOUBLE</td><td>Relative tolerence for the adjoint sensitivity solution [default: equal to reltol]</td></tr>
<tr><td>sensitivity_method</td><td>OT_STRING</td><td>Sensitivity method: SIMULTANEOUS|staggered</td></tr>
<tr><td>steps_per_checkpoint</td><td>OT_INT</td><td>Number of steps between two consecutive checkpoints</td></tr>
<tr><td>stop_at_end</td><td>OT_BOOL</td><td>Stop the integrator at the end of the interval</td></tr>
<tr><td>upper_bandwidth</td><td>OT_INT</td><td>Upper band-width of banded Jacobian (estimations)</td></tr>
<tr><td>upper_bandwidthB</td><td>OT_INT</td><td>Upper band-width of banded jacobians for backward integration [default: equal to upper_bandwidth]</td></tr>
<tr><td>use_preconditioner</td><td>OT_BOOL</td><td>Precondition an iterative solver</td></tr>
<tr><td>use_preconditionerB</td><td>OT_BOOL</td><td>Precondition an iterative solver for the backwards problem [default: equal to use_preconditioner]</td></tr>
</table>
*/
/** \addtogroup general_CvodesInterface
\n
\par
<a name='options'></a><table>
<caption>List of available options</caption>
<tr><th>Id</th><th>Type</th><th>Description</th><th>Used in</th></tr>
<tr><td>abstol</td><td>OT_DOUBLE</td><td>Absolute tolerence  for the IVP solution</td><td>casadi::SundialsInterface</td></tr>
<tr><td>abstolB</td><td>OT_DOUBLE</td><td>Absolute tolerence for the adjoint sensitivity solution [default: equal to abstol]</td><td>casadi::SundialsInterface</td></tr>
<tr><td>disable_internal_warnings</td><td>OT_BOOL</td><td>Disable SUNDIALS internal warning messages</td><td>casadi::SundialsInterface</td></tr>
<tr><td>exact_jacobian</td><td>OT_BOOL</td><td>Use exact Jacobian information for the forward integration</td><td>casadi::SundialsInterface</td></tr>
<tr><td>exact_jacobianB</td><td>OT_BOOL</td><td>Use exact Jacobian information for the backward integration [default: equal to exact_jacobian]</td><td>casadi::SundialsInterface</td></tr>
<tr><td>finite_difference_fsens</td><td>OT_BOOL</td><td>Use finite differences to approximate the forward sensitivity equations (if AD is not available)</td><td>casadi::SundialsInterface</td></tr>
<tr><td>fsens_abstol</td><td>OT_DOUBLE</td><td>Absolute tolerence for the forward sensitivity solution [default: equal to abstol]</td><td>casadi::SundialsInterface</td></tr>
<tr><td>fsens_all_at_once</td><td>OT_BOOL</td><td>Calculate all right hand sides of the sensitivity equations at once</td><td>casadi::CvodesInterface</td></tr>
<tr><td>fsens_err_con</td><td>OT_BOOL</td><td>include the forward sensitivities in all error controls</td><td>casadi::SundialsInterface</td></tr>
<tr><td>fsens_reltol</td><td>OT_DOUBLE</td><td>Relative tolerence for the forward sensitivity solution [default: equal to reltol]</td><td>casadi::SundialsInterface</td></tr>
<tr><td>fsens_scaling_factors</td><td>OT_DOUBLEVECTOR</td><td>Scaling factor for the components if finite differences is used</td><td>casadi::SundialsInterface</td></tr>
<tr><td>fsens_sensitiviy_parameters</td><td>OT_INTVECTOR</td><td>Specifies which components will be used when estimating the sensitivity equations</td><td>casadi::SundialsInterface</td></tr>
<tr><td>interpolation_type</td><td>OT_STRING</td><td>Type of interpolation for the adjoint sensitivities</td><td>casadi::SundialsInterface</td></tr>
<tr><td>iterative_solver</td><td>OT_STRING</td><td>Iterative solver: GMRES|bcgstab|tfqmr</td><td>casadi::SundialsInterface</td></tr>
<tr><td>iterative_solverB</td><td>OT_STRING</td><td>Iterative solver for backward integration</td><td>casadi::SundialsInterface</td></tr>
<tr><td>linear_multistep_method</td><td>OT_STRING</td><td>Integrator scheme: BDF|adams</td><td>casadi::CvodesInterface</td></tr>
<tr><td>linear_solver</td><td>OT_STRING</td><td>A custom linear solver creator function</td><td>casadi::SundialsInterface</td></tr>
<tr><td>linear_solverB</td><td>OT_STRING</td><td>A custom linear solver creator function for backwards integration [default: equal to linear_solver]</td><td>casadi::SundialsInterface</td></tr>
<tr><td>linear_solver_options</td><td>OT_DICT</td><td>Options to be passed to the linear solver</td><td>casadi::SundialsInterface</td></tr>
<tr><td>linear_solver_optionsB</td><td>OT_DICT</td><td>Options to be passed to the linear solver for backwards integration [default: equal to linear_solver_options]</td><td>casadi::SundialsInterface</td></tr>
<tr><td>linear_solver_type</td><td>OT_STRING</td><td>Type of iterative solver: user_defined|DENSE|banded|iterative</td><td>casadi::SundialsInterface</td></tr>
<tr><td>linear_solver_typeB</td><td>OT_STRING</td><td>Linear solver for backward integration</td><td>casadi::SundialsInterface</td></tr>
<tr><td>lower_bandwidth</td><td>OT_INT</td><td>Lower band-width of banded Jacobian (estimations)</td><td>casadi::SundialsInterface</td></tr>
<tr><td>lower_bandwidthB</td><td>OT_INT</td><td>lower band-width of banded jacobians for backward integration [default: equal to lower_bandwidth]</td><td>casadi::SundialsInterface</td></tr>
<tr><td>max_krylov</td><td>OT_INT</td><td>Maximum Krylov subspace size</td><td>casadi::SundialsInterface</td></tr>
<tr><td>max_krylovB</td><td>OT_INT</td><td>Maximum krylov subspace size for backward integration</td><td>casadi::SundialsInterface</td></tr>
<tr><td>max_multistep_order</td><td>OT_INT</td><td>Maximum order for the (variable-order) multistep method</td><td>casadi::SundialsInterface</td></tr>
<tr><td>max_num_steps</td><td>OT_INT</td><td>Maximum number of integrator steps</td><td>casadi::SundialsInterface</td></tr>
<tr><td>nonlinear_solver_iteration</td><td>OT_STRING</td><td>Nonlinear solver type: NEWTON|functional</td><td>casadi::CvodesInterface</td></tr>
<tr><td>pretype</td><td>OT_STRING</td><td>Type of preconditioning: NONE|left|right|both</td><td>casadi::SundialsInterface</td></tr>
<tr><td>pretypeB</td><td>OT_STRING</td><td>Preconditioner for backward integration</td><td>casadi::SundialsInterface</td></tr>
<tr><td>quad_err_con</td><td>OT_BOOL</td><td>Should the quadratures affect the step size control</td><td>casadi::SundialsInterface</td></tr>
<tr><td>reltol</td><td>OT_DOUBLE</td><td>Relative tolerence for the IVP solution</td><td>casadi::SundialsInterface</td></tr>
<tr><td>reltolB</td><td>OT_DOUBLE</td><td>Relative tolerence for the adjoint sensitivity solution [default: equal to reltol]</td><td>casadi::SundialsInterface</td></tr>
<tr><td>sensitivity_method</td><td>OT_STRING</td><td>Sensitivity method: SIMULTANEOUS|staggered</td><td>casadi::SundialsInterface</td></tr>
<tr><td>steps_per_checkpoint</td><td>OT_INT</td><td>Number of steps between two consecutive checkpoints</td><td>casadi::SundialsInterface</td></tr>
<tr><td>stop_at_end</td><td>OT_BOOL</td><td>Stop the integrator at the end of the interval</td><td>casadi::SundialsInterface</td></tr>
<tr><td>upper_bandwidth</td><td>OT_INT</td><td>Upper band-width of banded Jacobian (estimations)</td><td>casadi::SundialsInterface</td></tr>
<tr><td>upper_bandwidthB</td><td>OT_INT</td><td>Upper band-width of banded jacobians for backward integration [default: equal to upper_bandwidth]</td><td>casadi::SundialsInterface</td></tr>
<tr><td>use_preconditioner</td><td>OT_BOOL</td><td>Precondition an iterative solver</td><td>casadi::SundialsInterface</td></tr>
<tr><td>use_preconditionerB</td><td>OT_BOOL</td><td>Precondition an iterative solver for the backwards problem [default: equal to use_preconditioner]</td><td>casadi::SundialsInterface</td></tr>
</table>
*/
/// \cond INTERNAL
/** \class casadi::External
\n
\par
<a name='options'></a><table>
<caption>List of available options</caption>
<tr><th>Id</th><th>Type</th><th>Description</th><th>Used in</th></tr>
<tr><td>ad_weight</td><td>OT_DOUBLE</td><td>Weighting factor for derivative calculation.When there is an option of either using forward or reverse mode directional derivatives, the condition ad_weight*nf&lt;=(1-ad_weight)*na is used where nf and na are estimates of the number of forward/reverse mode directional derivatives needed. By default, ad_weight is calculated automatically, but this can be overridden by setting this option. In particular, 0 means forcing forward mode and 1 forcing reverse mode. Leave unset for (class specific) heuristics.</td><td>casadi::FunctionInternal</td></tr>
<tr><td>ad_weight_sp</td><td>OT_DOUBLE</td><td>Weighting factor for sparsity pattern calculation calculation.Overrides default behavior. Set to 0 and 1 to force forward and reverse mode respectively. Cf. option \"ad_weight\".</td><td>casadi::FunctionInternal</td></tr>
<tr><td>compiler</td><td>OT_STRING</td><td>Just-in-time compiler plugin to be used.</td><td>casadi::FunctionInternal</td></tr>
<tr><td>gather_stats</td><td>OT_BOOL</td><td>Flag to indicate whether statistics must be gathered</td><td>casadi::FunctionInternal</td></tr>
<tr><td>input_scheme</td><td>OT_STRINGVECTOR</td><td>Custom input scheme</td><td>casadi::FunctionInternal</td></tr>
<tr><td>inputs_check</td><td>OT_BOOL</td><td>Throw exceptions when the numerical values of the inputs don't make sense</td><td>casadi::FunctionInternal</td></tr>
<tr><td>int_data</td><td>OT_INTVECTOR</td><td>Integer data vector to be passed to the external function</td><td>casadi::External</td></tr>
<tr><td>jac_penalty</td><td>OT_DOUBLE</td><td>When requested for a number of forward/reverse directions,   it may be cheaper to compute first the full jacobian and then multiply with seeds, rather than obtain the requested directions in a straightforward manner. Casadi uses a heuristic to decide which is cheaper. A high value of 'jac_penalty' makes it less likely for the heurstic to chose the full Jacobian strategy. The special value -1 indicates never to use the full Jacobian strategy</td><td>casadi::FunctionInternal</td></tr>
<tr><td>jit</td><td>OT_BOOL</td><td>Use just-in-time compiler to speed up the evaluation</td><td>casadi::FunctionInternal</td></tr>
<tr><td>jit_options</td><td>OT_DICT</td><td>Options to be passed to the jit compiler.</td><td>casadi::FunctionInternal</td></tr>
<tr><td>monitor</td><td>OT_STRINGVECTOR</td><td>Monitors to be activated</td><td>casadi::FunctionInternal</td></tr>
<tr><td>output_scheme</td><td>OT_STRINGVECTOR</td><td>Custom output scheme</td><td>casadi::FunctionInternal</td></tr>
<tr><td>real_data</td><td>OT_DOUBLEVECTOR</td><td>Real data vector to be passed to the external function</td><td>casadi::External</td></tr>
<tr><td>regularity_check</td><td>OT_BOOL</td><td>Throw exceptions when NaN or Inf appears during evaluation</td><td>casadi::FunctionInternal</td></tr>
<tr><td>user_data</td><td>OT_VOIDPTR</td><td>A user-defined field that can be used to identify the function or pass additional information</td><td>casadi::FunctionInternal</td></tr>
<tr><td>verbose</td><td>OT_BOOL</td><td>Verbose evaluation -- for debugging</td><td>casadi::FunctionInternal</td></tr>
</table>
*/
/// \endcond
/// \cond INTERNAL
/** \class casadi::FixedStepIntegrator
\n
\par
<a name='options'></a><table>
<caption>List of available options</caption>
<tr><th>Id</th><th>Type</th><th>Description</th><th>Used in</th></tr>
<tr><td>ad_weight</td><td>OT_DOUBLE</td><td>Weighting factor for derivative calculation.When there is an option of either using forward or reverse mode directional derivatives, the condition ad_weight*nf&lt;=(1-ad_weight)*na is used where nf and na are estimates of the number of forward/reverse mode directional derivatives needed. By default, ad_weight is calculated automatically, but this can be overridden by setting this option. In particular, 0 means forcing forward mode and 1 forcing reverse mode. Leave unset for (class specific) heuristics.</td><td>casadi::FunctionInternal</td></tr>
<tr><td>ad_weight_sp</td><td>OT_DOUBLE</td><td>Weighting factor for sparsity pattern calculation calculation.Overrides default behavior. Set to 0 and 1 to force forward and reverse mode respectively. Cf. option \"ad_weight\".</td><td>casadi::FunctionInternal</td></tr>
<tr><td>augmented_options</td><td>OT_DICT</td><td>Options to be passed down to the augmented integrator, if one is constructed.</td><td>casadi::FixedStepIntegrator</td></tr>
<tr><td>compiler</td><td>OT_STRING</td><td>Just-in-time compiler plugin to be used.</td><td>casadi::FunctionInternal</td></tr>
<tr><td>expand</td><td>OT_BOOL</td><td>Replace MX with SX expressions in problem formulation [false]</td><td>casadi::FixedStepIntegrator</td></tr>
<tr><td>gather_stats</td><td>OT_BOOL</td><td>Flag to indicate whether statistics must be gathered</td><td>casadi::FunctionInternal</td></tr>
<tr><td>grid</td><td>OT_DOUBLEVECTOR</td><td>Time grid</td><td>casadi::FixedStepIntegrator</td></tr>
<tr><td>input_scheme</td><td>OT_STRINGVECTOR</td><td>Custom input scheme</td><td>casadi::FunctionInternal</td></tr>
<tr><td>inputs_check</td><td>OT_BOOL</td><td>Throw exceptions when the numerical values of the inputs don't make sense</td><td>casadi::FunctionInternal</td></tr>
<tr><td>jac_penalty</td><td>OT_DOUBLE</td><td>When requested for a number of forward/reverse directions,   it may be cheaper to compute first the full jacobian and then multiply with seeds, rather than obtain the requested directions in a straightforward manner. Casadi uses a heuristic to decide which is cheaper. A high value of 'jac_penalty' makes it less likely for the heurstic to chose the full Jacobian strategy. The special value -1 indicates never to use the full Jacobian strategy</td><td>casadi::FunctionInternal</td></tr>
<tr><td>jit</td><td>OT_BOOL</td><td>Use just-in-time compiler to speed up the evaluation</td><td>casadi::FunctionInternal</td></tr>
<tr><td>jit_options</td><td>OT_DICT</td><td>Options to be passed to the jit compiler.</td><td>casadi::FunctionInternal</td></tr>
<tr><td>monitor</td><td>OT_STRINGVECTOR</td><td>Monitors to be activated</td><td>casadi::FunctionInternal</td></tr>
<tr><td>number_of_finite_elements</td><td>OT_INT</td><td>Number of finite elements</td><td>casadi::FixedStepIntegrator</td></tr>
<tr><td>output_scheme</td><td>OT_STRINGVECTOR</td><td>Custom output scheme</td><td>casadi::FunctionInternal</td></tr>
<tr><td>output_t0</td><td>OT_BOOL</td><td>Output the state at the initial time</td><td>casadi::FixedStepIntegrator</td></tr>
<tr><td>print_stats</td><td>OT_BOOL</td><td>Print out statistics after integration</td><td>casadi::FixedStepIntegrator</td></tr>
<tr><td>regularity_check</td><td>OT_BOOL</td><td>Throw exceptions when NaN or Inf appears during evaluation</td><td>casadi::FunctionInternal</td></tr>
<tr><td>rootfinder</td><td>OT_STRING</td><td>An implicit function solver</td><td>casadi::FixedStepIntegrator</td></tr>
<tr><td>rootfinder_options</td><td>OT_DICT</td><td>Options to be passed to the NLP Solver</td><td>casadi::FixedStepIntegrator</td></tr>
<tr><td>t0</td><td>OT_DOUBLE</td><td>Beginning of the time horizon</td><td>casadi::FixedStepIntegrator</td></tr>
<tr><td>tf</td><td>OT_DOUBLE</td><td>End of the time horizon</td><td>casadi::FixedStepIntegrator</td></tr>
<tr><td>user_data</td><td>OT_VOIDPTR</td><td>A user-defined field that can be used to identify the function or pass additional information</td><td>casadi::FunctionInternal</td></tr>
<tr><td>verbose</td><td>OT_BOOL</td><td>Verbose evaluation -- for debugging</td><td>casadi::FunctionInternal</td></tr>
</table>
*/
/// \endcond
/** \addtogroup general_FixedStepIntegrator
\n
\par
<a name='options'></a><table>
<caption>List of available options</caption>
<tr><th>Id</th><th>Type</th><th>Description</th><th>Used in</th></tr>
<tr><td>ad_weight</td><td>OT_DOUBLE</td><td>Weighting factor for derivative calculation.When there is an option of either using forward or reverse mode directional derivatives, the condition ad_weight*nf&lt;=(1-ad_weight)*na is used where nf and na are estimates of the number of forward/reverse mode directional derivatives needed. By default, ad_weight is calculated automatically, but this can be overridden by setting this option. In particular, 0 means forcing forward mode and 1 forcing reverse mode. Leave unset for (class specific) heuristics.</td><td>casadi::FunctionInternal</td></tr>
<tr><td>ad_weight_sp</td><td>OT_DOUBLE</td><td>Weighting factor for sparsity pattern calculation calculation.Overrides default behavior. Set to 0 and 1 to force forward and reverse mode respectively. Cf. option \"ad_weight\".</td><td>casadi::FunctionInternal</td></tr>
<tr><td>augmented_options</td><td>OT_DICT</td><td>Options to be passed down to the augmented integrator, if one is constructed.</td><td>casadi::FixedStepIntegrator</td></tr>
<tr><td>compiler</td><td>OT_STRING</td><td>Just-in-time compiler plugin to be used.</td><td>casadi::FunctionInternal</td></tr>
<tr><td>expand</td><td>OT_BOOL</td><td>Replace MX with SX expressions in problem formulation [false]</td><td>casadi::FixedStepIntegrator</td></tr>
<tr><td>gather_stats</td><td>OT_BOOL</td><td>Flag to indicate whether statistics must be gathered</td><td>casadi::FunctionInternal</td></tr>
<tr><td>grid</td><td>OT_DOUBLEVECTOR</td><td>Time grid</td><td>casadi::FixedStepIntegrator</td></tr>
<tr><td>input_scheme</td><td>OT_STRINGVECTOR</td><td>Custom input scheme</td><td>casadi::FunctionInternal</td></tr>
<tr><td>inputs_check</td><td>OT_BOOL</td><td>Throw exceptions when the numerical values of the inputs don't make sense</td><td>casadi::FunctionInternal</td></tr>
<tr><td>jac_penalty</td><td>OT_DOUBLE</td><td>When requested for a number of forward/reverse directions,   it may be cheaper to compute first the full jacobian and then multiply with seeds, rather than obtain the requested directions in a straightforward manner. Casadi uses a heuristic to decide which is cheaper. A high value of 'jac_penalty' makes it less likely for the heurstic to chose the full Jacobian strategy. The special value -1 indicates never to use the full Jacobian strategy</td><td>casadi::FunctionInternal</td></tr>
<tr><td>jit</td><td>OT_BOOL</td><td>Use just-in-time compiler to speed up the evaluation</td><td>casadi::FunctionInternal</td></tr>
<tr><td>jit_options</td><td>OT_DICT</td><td>Options to be passed to the jit compiler.</td><td>casadi::FunctionInternal</td></tr>
<tr><td>monitor</td><td>OT_STRINGVECTOR</td><td>Monitors to be activated</td><td>casadi::FunctionInternal</td></tr>
<tr><td>number_of_finite_elements</td><td>OT_INT</td><td>Number of finite elements</td><td>casadi::FixedStepIntegrator</td></tr>
<tr><td>output_scheme</td><td>OT_STRINGVECTOR</td><td>Custom output scheme</td><td>casadi::FunctionInternal</td></tr>
<tr><td>output_t0</td><td>OT_BOOL</td><td>Output the state at the initial time</td><td>casadi::FixedStepIntegrator</td></tr>
<tr><td>print_stats</td><td>OT_BOOL</td><td>Print out statistics after integration</td><td>casadi::FixedStepIntegrator</td></tr>
<tr><td>regularity_check</td><td>OT_BOOL</td><td>Throw exceptions when NaN or Inf appears during evaluation</td><td>casadi::FunctionInternal</td></tr>
<tr><td>rootfinder</td><td>OT_STRING</td><td>An implicit function solver</td><td>casadi::FixedStepIntegrator</td></tr>
<tr><td>rootfinder_options</td><td>OT_DICT</td><td>Options to be passed to the NLP Solver</td><td>casadi::FixedStepIntegrator</td></tr>
<tr><td>t0</td><td>OT_DOUBLE</td><td>Beginning of the time horizon</td><td>casadi::FixedStepIntegrator</td></tr>
<tr><td>tf</td><td>OT_DOUBLE</td><td>End of the time horizon</td><td>casadi::FixedStepIntegrator</td></tr>
<tr><td>user_data</td><td>OT_VOIDPTR</td><td>A user-defined field that can be used to identify the function or pass additional information</td><td>casadi::FunctionInternal</td></tr>
<tr><td>verbose</td><td>OT_BOOL</td><td>Verbose evaluation -- for debugging</td><td>casadi::FunctionInternal</td></tr>
</table>
*/
/// \cond INTERNAL
/** \class casadi::FunctionInternal
\n
\par
<a name='options'></a><table>
<caption>List of available options</caption>
<tr><th>Id</th><th>Type</th><th>Description</th><th>Used in</th></tr>
<tr><td>ad_weight</td><td>OT_DOUBLE</td><td>Weighting factor for derivative calculation.When there is an option of either using forward or reverse mode directional derivatives, the condition ad_weight*nf&lt;=(1-ad_weight)*na is used where nf and na are estimates of the number of forward/reverse mode directional derivatives needed. By default, ad_weight is calculated automatically, but this can be overridden by setting this option. In particular, 0 means forcing forward mode and 1 forcing reverse mode. Leave unset for (class specific) heuristics.</td><td>casadi::FunctionInternal</td></tr>
<tr><td>ad_weight_sp</td><td>OT_DOUBLE</td><td>Weighting factor for sparsity pattern calculation calculation.Overrides default behavior. Set to 0 and 1 to force forward and reverse mode respectively. Cf. option \"ad_weight\".</td><td>casadi::FunctionInternal</td></tr>
<tr><td>compiler</td><td>OT_STRING</td><td>Just-in-time compiler plugin to be used.</td><td>casadi::FunctionInternal</td></tr>
<tr><td>gather_stats</td><td>OT_BOOL</td><td>Flag to indicate whether statistics must be gathered</td><td>casadi::FunctionInternal</td></tr>
<tr><td>input_scheme</td><td>OT_STRINGVECTOR</td><td>Custom input scheme</td><td>casadi::FunctionInternal</td></tr>
<tr><td>inputs_check</td><td>OT_BOOL</td><td>Throw exceptions when the numerical values of the inputs don't make sense</td><td>casadi::FunctionInternal</td></tr>
<tr><td>jac_penalty</td><td>OT_DOUBLE</td><td>When requested for a number of forward/reverse directions,   it may be cheaper to compute first the full jacobian and then multiply with seeds, rather than obtain the requested directions in a straightforward manner. Casadi uses a heuristic to decide which is cheaper. A high value of 'jac_penalty' makes it less likely for the heurstic to chose the full Jacobian strategy. The special value -1 indicates never to use the full Jacobian strategy</td><td>casadi::FunctionInternal</td></tr>
<tr><td>jit</td><td>OT_BOOL</td><td>Use just-in-time compiler to speed up the evaluation</td><td>casadi::FunctionInternal</td></tr>
<tr><td>jit_options</td><td>OT_DICT</td><td>Options to be passed to the jit compiler.</td><td>casadi::FunctionInternal</td></tr>
<tr><td>monitor</td><td>OT_STRINGVECTOR</td><td>Monitors to be activated</td><td>casadi::FunctionInternal</td></tr>
<tr><td>output_scheme</td><td>OT_STRINGVECTOR</td><td>Custom output scheme</td><td>casadi::FunctionInternal</td></tr>
<tr><td>regularity_check</td><td>OT_BOOL</td><td>Throw exceptions when NaN or Inf appears during evaluation</td><td>casadi::FunctionInternal</td></tr>
<tr><td>user_data</td><td>OT_VOIDPTR</td><td>A user-defined field that can be used to identify the function or pass additional information</td><td>casadi::FunctionInternal</td></tr>
<tr><td>verbose</td><td>OT_BOOL</td><td>Verbose evaluation -- for debugging</td><td>casadi::FunctionInternal</td></tr>
</table>
*/
/// \endcond
/// \cond INTERNAL
/** \class casadi::GurobiInterface
\n
\par
<a name='options'></a><table>
<caption>List of available options</caption>
<tr><th>Id</th><th>Type</th><th>Description</th><th>Used in</th></tr>
<tr><td>discrete</td><td>OT_BOOLVECTOR</td><td>Indicates which of the variables are discrete, i.e. integer-valued</td><td>casadi::Qpsol</td></tr>
<tr><td>vtype</td><td>OT_STRINGVECTOR</td><td>Type of variables: [CONTINUOUS|binary|integer|semicont|semiint]</td><td>casadi::GurobiInterface</td></tr>
</table>
*/
/// \endcond
/** \addtogroup plugin_Qpsol_gurobi
\n
\par
<a name='options'></a><table>
<caption>List of available options</caption>
<tr><th>Id</th><th>Type</th><th>Description</th></tr>
<tr><td>vtype</td><td>OT_STRINGVECTOR</td><td>Type of variables: [CONTINUOUS|binary|integer|semicont|semiint]</td></tr>
</table>
*/
/** \addtogroup general_GurobiInterface
\n
\par
<a name='options'></a><table>
<caption>List of available options</caption>
<tr><th>Id</th><th>Type</th><th>Description</th><th>Used in</th></tr>
<tr><td>discrete</td><td>OT_BOOLVECTOR</td><td>Indicates which of the variables are discrete, i.e. integer-valued</td><td>casadi::Qpsol</td></tr>
<tr><td>vtype</td><td>OT_STRINGVECTOR</td><td>Type of variables: [CONTINUOUS|binary|integer|semicont|semiint]</td><td>casadi::GurobiInterface</td></tr>
</table>
*/
/// \cond INTERNAL
/** \class casadi::IdasInterface
\n
\par
<a name='options'></a><table>
<caption>List of available options</caption>
<tr><th>Id</th><th>Type</th><th>Description</th><th>Used in</th></tr>
<tr><td>abstol</td><td>OT_DOUBLE</td><td>Absolute tolerence  for the IVP solution</td><td>casadi::SundialsInterface</td></tr>
<tr><td>abstolB</td><td>OT_DOUBLE</td><td>Absolute tolerence for the adjoint sensitivity solution [default: equal to abstol]</td><td>casadi::SundialsInterface</td></tr>
<tr><td>abstolv</td><td>OT_DOUBLEVECTOR</td><td>Absolute tolerarance for each component</td><td>casadi::IdasInterface</td></tr>
<tr><td>calc_ic</td><td>OT_BOOL</td><td>Use IDACalcIC to get consistent initial conditions.</td><td>casadi::IdasInterface</td></tr>
<tr><td>calc_icB</td><td>OT_BOOL</td><td>Use IDACalcIC to get consistent initial conditions for backwards system [default: equal to calc_ic].</td><td>casadi::IdasInterface</td></tr>
<tr><td>cj_scaling</td><td>OT_BOOL</td><td>IDAS scaling on cj for the user-defined linear solver module</td><td>casadi::IdasInterface</td></tr>
<tr><td>disable_internal_warnings</td><td>OT_BOOL</td><td>Disable SUNDIALS internal warning messages</td><td>casadi::SundialsInterface</td></tr>
<tr><td>exact_jacobian</td><td>OT_BOOL</td><td>Use exact Jacobian information for the forward integration</td><td>casadi::SundialsInterface</td></tr>
<tr><td>exact_jacobianB</td><td>OT_BOOL</td><td>Use exact Jacobian information for the backward integration [default: equal to exact_jacobian]</td><td>casadi::SundialsInterface</td></tr>
<tr><td>extra_fsens_calc_ic</td><td>OT_BOOL</td><td>Call calc ic an extra time, with fsens=0</td><td>casadi::IdasInterface</td></tr>
<tr><td>finite_difference_fsens</td><td>OT_BOOL</td><td>Use finite differences to approximate the forward sensitivity equations (if AD is not available)</td><td>casadi::SundialsInterface</td></tr>
<tr><td>first_time</td><td>OT_DOUBLE</td><td>First requested time as a fraction of the time interval</td><td>casadi::IdasInterface</td></tr>
<tr><td>fsens_abstol</td><td>OT_DOUBLE</td><td>Absolute tolerence for the forward sensitivity solution [default: equal to abstol]</td><td>casadi::SundialsInterface</td></tr>
<tr><td>fsens_abstolv</td><td>OT_DOUBLEVECTOR</td><td>Absolute tolerarance for each component, forward sensitivities</td><td>casadi::IdasInterface</td></tr>
<tr><td>fsens_err_con</td><td>OT_BOOL</td><td>include the forward sensitivities in all error controls</td><td>casadi::SundialsInterface</td></tr>
<tr><td>fsens_reltol</td><td>OT_DOUBLE</td><td>Relative tolerence for the forward sensitivity solution [default: equal to reltol]</td><td>casadi::SundialsInterface</td></tr>
<tr><td>fsens_scaling_factors</td><td>OT_DOUBLEVECTOR</td><td>Scaling factor for the components if finite differences is used</td><td>casadi::SundialsInterface</td></tr>
<tr><td>fsens_sensitiviy_parameters</td><td>OT_INTVECTOR</td><td>Specifies which components will be used when estimating the sensitivity equations</td><td>casadi::SundialsInterface</td></tr>
<tr><td>init_xdot</td><td>OT_DOUBLEVECTOR</td><td>Initial values for the state derivatives</td><td>casadi::IdasInterface</td></tr>
<tr><td>interpolation_type</td><td>OT_STRING</td><td>Type of interpolation for the adjoint sensitivities</td><td>casadi::SundialsInterface</td></tr>
<tr><td>iterative_solver</td><td>OT_STRING</td><td>Iterative solver: GMRES|bcgstab|tfqmr</td><td>casadi::SundialsInterface</td></tr>
<tr><td>iterative_solverB</td><td>OT_STRING</td><td>Iterative solver for backward integration</td><td>casadi::SundialsInterface</td></tr>
<tr><td>linear_solver</td><td>OT_STRING</td><td>A custom linear solver creator function</td><td>casadi::SundialsInterface</td></tr>
<tr><td>linear_solverB</td><td>OT_STRING</td><td>A custom linear solver creator function for backwards integration [default: equal to linear_solver]</td><td>casadi::SundialsInterface</td></tr>
<tr><td>linear_solver_options</td><td>OT_DICT</td><td>Options to be passed to the linear solver</td><td>casadi::SundialsInterface</td></tr>
<tr><td>linear_solver_optionsB</td><td>OT_DICT</td><td>Options to be passed to the linear solver for backwards integration [default: equal to linear_solver_options]</td><td>casadi::SundialsInterface</td></tr>
<tr><td>linear_solver_type</td><td>OT_STRING</td><td>Type of iterative solver: user_defined|DENSE|banded|iterative</td><td>casadi::SundialsInterface</td></tr>
<tr><td>linear_solver_typeB</td><td>OT_STRING</td><td>Linear solver for backward integration</td><td>casadi::SundialsInterface</td></tr>
<tr><td>lower_bandwidth</td><td>OT_INT</td><td>Lower band-width of banded Jacobian (estimations)</td><td>casadi::SundialsInterface</td></tr>
<tr><td>lower_bandwidthB</td><td>OT_INT</td><td>lower band-width of banded jacobians for backward integration [default: equal to lower_bandwidth]</td><td>casadi::SundialsInterface</td></tr>
<tr><td>max_krylov</td><td>OT_INT</td><td>Maximum Krylov subspace size</td><td>casadi::SundialsInterface</td></tr>
<tr><td>max_krylovB</td><td>OT_INT</td><td>Maximum krylov subspace size for backward integration</td><td>casadi::SundialsInterface</td></tr>
<tr><td>max_multistep_order</td><td>OT_INT</td><td>Maximum order for the (variable-order) multistep method</td><td>casadi::SundialsInterface</td></tr>
<tr><td>max_num_steps</td><td>OT_INT</td><td>Maximum number of integrator steps</td><td>casadi::SundialsInterface</td></tr>
<tr><td>max_step_size</td><td>OT_DOUBLE</td><td>Maximim step size</td><td>casadi::IdasInterface</td></tr>
<tr><td>pretype</td><td>OT_STRING</td><td>Type of preconditioning: NONE|left|right|both</td><td>casadi::SundialsInterface</td></tr>
<tr><td>pretypeB</td><td>OT_STRING</td><td>Preconditioner for backward integration</td><td>casadi::SundialsInterface</td></tr>
<tr><td>quad_err_con</td><td>OT_BOOL</td><td>Should the quadratures affect the step size control</td><td>casadi::SundialsInterface</td></tr>
<tr><td>reltol</td><td>OT_DOUBLE</td><td>Relative tolerence for the IVP solution</td><td>casadi::SundialsInterface</td></tr>
<tr><td>reltolB</td><td>OT_DOUBLE</td><td>Relative tolerence for the adjoint sensitivity solution [default: equal to reltol]</td><td>casadi::SundialsInterface</td></tr>
<tr><td>sensitivity_method</td><td>OT_STRING</td><td>Sensitivity method: SIMULTANEOUS|staggered</td><td>casadi::SundialsInterface</td></tr>
<tr><td>steps_per_checkpoint</td><td>OT_INT</td><td>Number of steps between two consecutive checkpoints</td><td>casadi::SundialsInterface</td></tr>
<tr><td>stop_at_end</td><td>OT_BOOL</td><td>Stop the integrator at the end of the interval</td><td>casadi::SundialsInterface</td></tr>
<tr><td>suppress_algebraic</td><td>OT_BOOL</td><td>Suppress algebraic variables in the error testing</td><td>casadi::IdasInterface</td></tr>
<tr><td>upper_bandwidth</td><td>OT_INT</td><td>Upper band-width of banded Jacobian (estimations)</td><td>casadi::SundialsInterface</td></tr>
<tr><td>upper_bandwidthB</td><td>OT_INT</td><td>Upper band-width of banded jacobians for backward integration [default: equal to upper_bandwidth]</td><td>casadi::SundialsInterface</td></tr>
<tr><td>use_preconditioner</td><td>OT_BOOL</td><td>Precondition an iterative solver</td><td>casadi::SundialsInterface</td></tr>
<tr><td>use_preconditionerB</td><td>OT_BOOL</td><td>Precondition an iterative solver for the backwards problem [default: equal to use_preconditioner]</td><td>casadi::SundialsInterface</td></tr>
</table>
*/
/// \endcond
/** \addtogroup plugin_Integrator_idas
\n
\par
<a name='options'></a><table>
<caption>List of available options</caption>
<tr><th>Id</th><th>Type</th><th>Description</th></tr>
<tr><td>abstol</td><td>OT_DOUBLE</td><td>Absolute tolerence  for the IVP solution</td></tr>
<tr><td>abstolB</td><td>OT_DOUBLE</td><td>Absolute tolerence for the adjoint sensitivity solution [default: equal to abstol]</td></tr>
<tr><td>abstolv</td><td>OT_DOUBLEVECTOR</td><td>Absolute tolerarance for each component</td></tr>
<tr><td>calc_ic</td><td>OT_BOOL</td><td>Use IDACalcIC to get consistent initial conditions.</td></tr>
<tr><td>calc_icB</td><td>OT_BOOL</td><td>Use IDACalcIC to get consistent initial conditions for backwards system [default: equal to calc_ic].</td></tr>
<tr><td>cj_scaling</td><td>OT_BOOL</td><td>IDAS scaling on cj for the user-defined linear solver module</td></tr>
<tr><td>disable_internal_warnings</td><td>OT_BOOL</td><td>Disable SUNDIALS internal warning messages</td></tr>
<tr><td>exact_jacobian</td><td>OT_BOOL</td><td>Use exact Jacobian information for the forward integration</td></tr>
<tr><td>exact_jacobianB</td><td>OT_BOOL</td><td>Use exact Jacobian information for the backward integration [default: equal to exact_jacobian]</td></tr>
<tr><td>extra_fsens_calc_ic</td><td>OT_BOOL</td><td>Call calc ic an extra time, with fsens=0</td></tr>
<tr><td>finite_difference_fsens</td><td>OT_BOOL</td><td>Use finite differences to approximate the forward sensitivity equations (if AD is not available)</td></tr>
<tr><td>first_time</td><td>OT_DOUBLE</td><td>First requested time as a fraction of the time interval</td></tr>
<tr><td>fsens_abstol</td><td>OT_DOUBLE</td><td>Absolute tolerence for the forward sensitivity solution [default: equal to abstol]</td></tr>
<tr><td>fsens_abstolv</td><td>OT_DOUBLEVECTOR</td><td>Absolute tolerarance for each component, forward sensitivities</td></tr>
<tr><td>fsens_err_con</td><td>OT_BOOL</td><td>include the forward sensitivities in all error controls</td></tr>
<tr><td>fsens_reltol</td><td>OT_DOUBLE</td><td>Relative tolerence for the forward sensitivity solution [default: equal to reltol]</td></tr>
<tr><td>fsens_scaling_factors</td><td>OT_DOUBLEVECTOR</td><td>Scaling factor for the components if finite differences is used</td></tr>
<tr><td>fsens_sensitiviy_parameters</td><td>OT_INTVECTOR</td><td>Specifies which components will be used when estimating the sensitivity equations</td></tr>
<tr><td>init_xdot</td><td>OT_DOUBLEVECTOR</td><td>Initial values for the state derivatives</td></tr>
<tr><td>interpolation_type</td><td>OT_STRING</td><td>Type of interpolation for the adjoint sensitivities</td></tr>
<tr><td>iterative_solver</td><td>OT_STRING</td><td>Iterative solver: GMRES|bcgstab|tfqmr</td></tr>
<tr><td>iterative_solverB</td><td>OT_STRING</td><td>Iterative solver for backward integration</td></tr>
<tr><td>linear_solver</td><td>OT_STRING</td><td>A custom linear solver creator function</td></tr>
<tr><td>linear_solverB</td><td>OT_STRING</td><td>A custom linear solver creator function for backwards integration [default: equal to linear_solver]</td></tr>
<tr><td>linear_solver_options</td><td>OT_DICT</td><td>Options to be passed to the linear solver</td></tr>
<tr><td>linear_solver_optionsB</td><td>OT_DICT</td><td>Options to be passed to the linear solver for backwards integration [default: equal to linear_solver_options]</td></tr>
<tr><td>linear_solver_type</td><td>OT_STRING</td><td>Type of iterative solver: user_defined|DENSE|banded|iterative</td></tr>
<tr><td>linear_solver_typeB</td><td>OT_STRING</td><td>Linear solver for backward integration</td></tr>
<tr><td>lower_bandwidth</td><td>OT_INT</td><td>Lower band-width of banded Jacobian (estimations)</td></tr>
<tr><td>lower_bandwidthB</td><td>OT_INT</td><td>lower band-width of banded jacobians for backward integration [default: equal to lower_bandwidth]</td></tr>
<tr><td>max_krylov</td><td>OT_INT</td><td>Maximum Krylov subspace size</td></tr>
<tr><td>max_krylovB</td><td>OT_INT</td><td>Maximum krylov subspace size for backward integration</td></tr>
<tr><td>max_multistep_order</td><td>OT_INT</td><td>Maximum order for the (variable-order) multistep method</td></tr>
<tr><td>max_num_steps</td><td>OT_INT</td><td>Maximum number of integrator steps</td></tr>
<tr><td>max_step_size</td><td>OT_DOUBLE</td><td>Maximim step size</td></tr>
<tr><td>pretype</td><td>OT_STRING</td><td>Type of preconditioning: NONE|left|right|both</td></tr>
<tr><td>pretypeB</td><td>OT_STRING</td><td>Preconditioner for backward integration</td></tr>
<tr><td>quad_err_con</td><td>OT_BOOL</td><td>Should the quadratures affect the step size control</td></tr>
<tr><td>reltol</td><td>OT_DOUBLE</td><td>Relative tolerence for the IVP solution</td></tr>
<tr><td>reltolB</td><td>OT_DOUBLE</td><td>Relative tolerence for the adjoint sensitivity solution [default: equal to reltol]</td></tr>
<tr><td>sensitivity_method</td><td>OT_STRING</td><td>Sensitivity method: SIMULTANEOUS|staggered</td></tr>
<tr><td>steps_per_checkpoint</td><td>OT_INT</td><td>Number of steps between two consecutive checkpoints</td></tr>
<tr><td>stop_at_end</td><td>OT_BOOL</td><td>Stop the integrator at the end of the interval</td></tr>
<tr><td>suppress_algebraic</td><td>OT_BOOL</td><td>Suppress algebraic variables in the error testing</td></tr>
<tr><td>upper_bandwidth</td><td>OT_INT</td><td>Upper band-width of banded Jacobian (estimations)</td></tr>
<tr><td>upper_bandwidthB</td><td>OT_INT</td><td>Upper band-width of banded jacobians for backward integration [default: equal to upper_bandwidth]</td></tr>
<tr><td>use_preconditioner</td><td>OT_BOOL</td><td>Precondition an iterative solver</td></tr>
<tr><td>use_preconditionerB</td><td>OT_BOOL</td><td>Precondition an iterative solver for the backwards problem [default: equal to use_preconditioner]</td></tr>
</table>
*/
/** \addtogroup general_IdasInterface
\n
\par
<a name='options'></a><table>
<caption>List of available options</caption>
<tr><th>Id</th><th>Type</th><th>Description</th><th>Used in</th></tr>
<tr><td>abstol</td><td>OT_DOUBLE</td><td>Absolute tolerence  for the IVP solution</td><td>casadi::SundialsInterface</td></tr>
<tr><td>abstolB</td><td>OT_DOUBLE</td><td>Absolute tolerence for the adjoint sensitivity solution [default: equal to abstol]</td><td>casadi::SundialsInterface</td></tr>
<tr><td>abstolv</td><td>OT_DOUBLEVECTOR</td><td>Absolute tolerarance for each component</td><td>casadi::IdasInterface</td></tr>
<tr><td>calc_ic</td><td>OT_BOOL</td><td>Use IDACalcIC to get consistent initial conditions.</td><td>casadi::IdasInterface</td></tr>
<tr><td>calc_icB</td><td>OT_BOOL</td><td>Use IDACalcIC to get consistent initial conditions for backwards system [default: equal to calc_ic].</td><td>casadi::IdasInterface</td></tr>
<tr><td>cj_scaling</td><td>OT_BOOL</td><td>IDAS scaling on cj for the user-defined linear solver module</td><td>casadi::IdasInterface</td></tr>
<tr><td>disable_internal_warnings</td><td>OT_BOOL</td><td>Disable SUNDIALS internal warning messages</td><td>casadi::SundialsInterface</td></tr>
<tr><td>exact_jacobian</td><td>OT_BOOL</td><td>Use exact Jacobian information for the forward integration</td><td>casadi::SundialsInterface</td></tr>
<tr><td>exact_jacobianB</td><td>OT_BOOL</td><td>Use exact Jacobian information for the backward integration [default: equal to exact_jacobian]</td><td>casadi::SundialsInterface</td></tr>
<tr><td>extra_fsens_calc_ic</td><td>OT_BOOL</td><td>Call calc ic an extra time, with fsens=0</td><td>casadi::IdasInterface</td></tr>
<tr><td>finite_difference_fsens</td><td>OT_BOOL</td><td>Use finite differences to approximate the forward sensitivity equations (if AD is not available)</td><td>casadi::SundialsInterface</td></tr>
<tr><td>first_time</td><td>OT_DOUBLE</td><td>First requested time as a fraction of the time interval</td><td>casadi::IdasInterface</td></tr>
<tr><td>fsens_abstol</td><td>OT_DOUBLE</td><td>Absolute tolerence for the forward sensitivity solution [default: equal to abstol]</td><td>casadi::SundialsInterface</td></tr>
<tr><td>fsens_abstolv</td><td>OT_DOUBLEVECTOR</td><td>Absolute tolerarance for each component, forward sensitivities</td><td>casadi::IdasInterface</td></tr>
<tr><td>fsens_err_con</td><td>OT_BOOL</td><td>include the forward sensitivities in all error controls</td><td>casadi::SundialsInterface</td></tr>
<tr><td>fsens_reltol</td><td>OT_DOUBLE</td><td>Relative tolerence for the forward sensitivity solution [default: equal to reltol]</td><td>casadi::SundialsInterface</td></tr>
<tr><td>fsens_scaling_factors</td><td>OT_DOUBLEVECTOR</td><td>Scaling factor for the components if finite differences is used</td><td>casadi::SundialsInterface</td></tr>
<tr><td>fsens_sensitiviy_parameters</td><td>OT_INTVECTOR</td><td>Specifies which components will be used when estimating the sensitivity equations</td><td>casadi::SundialsInterface</td></tr>
<tr><td>init_xdot</td><td>OT_DOUBLEVECTOR</td><td>Initial values for the state derivatives</td><td>casadi::IdasInterface</td></tr>
<tr><td>interpolation_type</td><td>OT_STRING</td><td>Type of interpolation for the adjoint sensitivities</td><td>casadi::SundialsInterface</td></tr>
<tr><td>iterative_solver</td><td>OT_STRING</td><td>Iterative solver: GMRES|bcgstab|tfqmr</td><td>casadi::SundialsInterface</td></tr>
<tr><td>iterative_solverB</td><td>OT_STRING</td><td>Iterative solver for backward integration</td><td>casadi::SundialsInterface</td></tr>
<tr><td>linear_solver</td><td>OT_STRING</td><td>A custom linear solver creator function</td><td>casadi::SundialsInterface</td></tr>
<tr><td>linear_solverB</td><td>OT_STRING</td><td>A custom linear solver creator function for backwards integration [default: equal to linear_solver]</td><td>casadi::SundialsInterface</td></tr>
<tr><td>linear_solver_options</td><td>OT_DICT</td><td>Options to be passed to the linear solver</td><td>casadi::SundialsInterface</td></tr>
<tr><td>linear_solver_optionsB</td><td>OT_DICT</td><td>Options to be passed to the linear solver for backwards integration [default: equal to linear_solver_options]</td><td>casadi::SundialsInterface</td></tr>
<tr><td>linear_solver_type</td><td>OT_STRING</td><td>Type of iterative solver: user_defined|DENSE|banded|iterative</td><td>casadi::SundialsInterface</td></tr>
<tr><td>linear_solver_typeB</td><td>OT_STRING</td><td>Linear solver for backward integration</td><td>casadi::SundialsInterface</td></tr>
<tr><td>lower_bandwidth</td><td>OT_INT</td><td>Lower band-width of banded Jacobian (estimations)</td><td>casadi::SundialsInterface</td></tr>
<tr><td>lower_bandwidthB</td><td>OT_INT</td><td>lower band-width of banded jacobians for backward integration [default: equal to lower_bandwidth]</td><td>casadi::SundialsInterface</td></tr>
<tr><td>max_krylov</td><td>OT_INT</td><td>Maximum Krylov subspace size</td><td>casadi::SundialsInterface</td></tr>
<tr><td>max_krylovB</td><td>OT_INT</td><td>Maximum krylov subspace size for backward integration</td><td>casadi::SundialsInterface</td></tr>
<tr><td>max_multistep_order</td><td>OT_INT</td><td>Maximum order for the (variable-order) multistep method</td><td>casadi::SundialsInterface</td></tr>
<tr><td>max_num_steps</td><td>OT_INT</td><td>Maximum number of integrator steps</td><td>casadi::SundialsInterface</td></tr>
<tr><td>max_step_size</td><td>OT_DOUBLE</td><td>Maximim step size</td><td>casadi::IdasInterface</td></tr>
<tr><td>pretype</td><td>OT_STRING</td><td>Type of preconditioning: NONE|left|right|both</td><td>casadi::SundialsInterface</td></tr>
<tr><td>pretypeB</td><td>OT_STRING</td><td>Preconditioner for backward integration</td><td>casadi::SundialsInterface</td></tr>
<tr><td>quad_err_con</td><td>OT_BOOL</td><td>Should the quadratures affect the step size control</td><td>casadi::SundialsInterface</td></tr>
<tr><td>reltol</td><td>OT_DOUBLE</td><td>Relative tolerence for the IVP solution</td><td>casadi::SundialsInterface</td></tr>
<tr><td>reltolB</td><td>OT_DOUBLE</td><td>Relative tolerence for the adjoint sensitivity solution [default: equal to reltol]</td><td>casadi::SundialsInterface</td></tr>
<tr><td>sensitivity_method</td><td>OT_STRING</td><td>Sensitivity method: SIMULTANEOUS|staggered</td><td>casadi::SundialsInterface</td></tr>
<tr><td>steps_per_checkpoint</td><td>OT_INT</td><td>Number of steps between two consecutive checkpoints</td><td>casadi::SundialsInterface</td></tr>
<tr><td>stop_at_end</td><td>OT_BOOL</td><td>Stop the integrator at the end of the interval</td><td>casadi::SundialsInterface</td></tr>
<tr><td>suppress_algebraic</td><td>OT_BOOL</td><td>Suppress algebraic variables in the error testing</td><td>casadi::IdasInterface</td></tr>
<tr><td>upper_bandwidth</td><td>OT_INT</td><td>Upper band-width of banded Jacobian (estimations)</td><td>casadi::SundialsInterface</td></tr>
<tr><td>upper_bandwidthB</td><td>OT_INT</td><td>Upper band-width of banded jacobians for backward integration [default: equal to upper_bandwidth]</td><td>casadi::SundialsInterface</td></tr>
<tr><td>use_preconditioner</td><td>OT_BOOL</td><td>Precondition an iterative solver</td><td>casadi::SundialsInterface</td></tr>
<tr><td>use_preconditionerB</td><td>OT_BOOL</td><td>Precondition an iterative solver for the backwards problem [default: equal to use_preconditioner]</td><td>casadi::SundialsInterface</td></tr>
</table>
*/
/// \cond INTERNAL
/** \class casadi::ImplicitFixedStepIntegrator
\n
\par
<a name='options'></a><table>
<caption>List of available options</caption>
<tr><th>Id</th><th>Type</th><th>Description</th><th>Used in</th></tr>
<tr><td>ad_weight</td><td>OT_DOUBLE</td><td>Weighting factor for derivative calculation.When there is an option of either using forward or reverse mode directional derivatives, the condition ad_weight*nf&lt;=(1-ad_weight)*na is used where nf and na are estimates of the number of forward/reverse mode directional derivatives needed. By default, ad_weight is calculated automatically, but this can be overridden by setting this option. In particular, 0 means forcing forward mode and 1 forcing reverse mode. Leave unset for (class specific) heuristics.</td><td>casadi::FunctionInternal</td></tr>
<tr><td>ad_weight_sp</td><td>OT_DOUBLE</td><td>Weighting factor for sparsity pattern calculation calculation.Overrides default behavior. Set to 0 and 1 to force forward and reverse mode respectively. Cf. option \"ad_weight\".</td><td>casadi::FunctionInternal</td></tr>
<tr><td>augmented_options</td><td>OT_DICT</td><td>Options to be passed down to the augmented integrator, if one is constructed.</td><td>casadi::ImplicitFixedStepIntegrator</td></tr>
<tr><td>compiler</td><td>OT_STRING</td><td>Just-in-time compiler plugin to be used.</td><td>casadi::FunctionInternal</td></tr>
<tr><td>expand</td><td>OT_BOOL</td><td>Replace MX with SX expressions in problem formulation [false]</td><td>casadi::ImplicitFixedStepIntegrator</td></tr>
<tr><td>gather_stats</td><td>OT_BOOL</td><td>Flag to indicate whether statistics must be gathered</td><td>casadi::FunctionInternal</td></tr>
<tr><td>grid</td><td>OT_DOUBLEVECTOR</td><td>Time grid</td><td>casadi::ImplicitFixedStepIntegrator</td></tr>
<tr><td>input_scheme</td><td>OT_STRINGVECTOR</td><td>Custom input scheme</td><td>casadi::FunctionInternal</td></tr>
<tr><td>inputs_check</td><td>OT_BOOL</td><td>Throw exceptions when the numerical values of the inputs don't make sense</td><td>casadi::FunctionInternal</td></tr>
<tr><td>jac_penalty</td><td>OT_DOUBLE</td><td>When requested for a number of forward/reverse directions,   it may be cheaper to compute first the full jacobian and then multiply with seeds, rather than obtain the requested directions in a straightforward manner. Casadi uses a heuristic to decide which is cheaper. A high value of 'jac_penalty' makes it less likely for the heurstic to chose the full Jacobian strategy. The special value -1 indicates never to use the full Jacobian strategy</td><td>casadi::FunctionInternal</td></tr>
<tr><td>jit</td><td>OT_BOOL</td><td>Use just-in-time compiler to speed up the evaluation</td><td>casadi::FunctionInternal</td></tr>
<tr><td>jit_options</td><td>OT_DICT</td><td>Options to be passed to the jit compiler.</td><td>casadi::FunctionInternal</td></tr>
<tr><td>monitor</td><td>OT_STRINGVECTOR</td><td>Monitors to be activated</td><td>casadi::FunctionInternal</td></tr>
<tr><td>number_of_finite_elements</td><td>OT_INT</td><td>Number of finite elements</td><td>casadi::ImplicitFixedStepIntegrator</td></tr>
<tr><td>output_scheme</td><td>OT_STRINGVECTOR</td><td>Custom output scheme</td><td>casadi::FunctionInternal</td></tr>
<tr><td>output_t0</td><td>OT_BOOL</td><td>Output the state at the initial time</td><td>casadi::ImplicitFixedStepIntegrator</td></tr>
<tr><td>print_stats</td><td>OT_BOOL</td><td>Print out statistics after integration</td><td>casadi::ImplicitFixedStepIntegrator</td></tr>
<tr><td>regularity_check</td><td>OT_BOOL</td><td>Throw exceptions when NaN or Inf appears during evaluation</td><td>casadi::FunctionInternal</td></tr>
<tr><td>rootfinder</td><td>OT_STRING</td><td>An implicit function solver</td><td>casadi::ImplicitFixedStepIntegrator</td></tr>
<tr><td>rootfinder_options</td><td>OT_DICT</td><td>Options to be passed to the NLP Solver</td><td>casadi::ImplicitFixedStepIntegrator</td></tr>
<tr><td>t0</td><td>OT_DOUBLE</td><td>Beginning of the time horizon</td><td>casadi::ImplicitFixedStepIntegrator</td></tr>
<tr><td>tf</td><td>OT_DOUBLE</td><td>End of the time horizon</td><td>casadi::ImplicitFixedStepIntegrator</td></tr>
<tr><td>user_data</td><td>OT_VOIDPTR</td><td>A user-defined field that can be used to identify the function or pass additional information</td><td>casadi::FunctionInternal</td></tr>
<tr><td>verbose</td><td>OT_BOOL</td><td>Verbose evaluation -- for debugging</td><td>casadi::FunctionInternal</td></tr>
</table>
*/
/// \endcond
/** \addtogroup general_ImplicitFixedStepIntegrator
\n
\par
<a name='options'></a><table>
<caption>List of available options</caption>
<tr><th>Id</th><th>Type</th><th>Description</th><th>Used in</th></tr>
<tr><td>ad_weight</td><td>OT_DOUBLE</td><td>Weighting factor for derivative calculation.When there is an option of either using forward or reverse mode directional derivatives, the condition ad_weight*nf&lt;=(1-ad_weight)*na is used where nf and na are estimates of the number of forward/reverse mode directional derivatives needed. By default, ad_weight is calculated automatically, but this can be overridden by setting this option. In particular, 0 means forcing forward mode and 1 forcing reverse mode. Leave unset for (class specific) heuristics.</td><td>casadi::FunctionInternal</td></tr>
<tr><td>ad_weight_sp</td><td>OT_DOUBLE</td><td>Weighting factor for sparsity pattern calculation calculation.Overrides default behavior. Set to 0 and 1 to force forward and reverse mode respectively. Cf. option \"ad_weight\".</td><td>casadi::FunctionInternal</td></tr>
<tr><td>augmented_options</td><td>OT_DICT</td><td>Options to be passed down to the augmented integrator, if one is constructed.</td><td>casadi::ImplicitFixedStepIntegrator</td></tr>
<tr><td>compiler</td><td>OT_STRING</td><td>Just-in-time compiler plugin to be used.</td><td>casadi::FunctionInternal</td></tr>
<tr><td>expand</td><td>OT_BOOL</td><td>Replace MX with SX expressions in problem formulation [false]</td><td>casadi::ImplicitFixedStepIntegrator</td></tr>
<tr><td>gather_stats</td><td>OT_BOOL</td><td>Flag to indicate whether statistics must be gathered</td><td>casadi::FunctionInternal</td></tr>
<tr><td>grid</td><td>OT_DOUBLEVECTOR</td><td>Time grid</td><td>casadi::ImplicitFixedStepIntegrator</td></tr>
<tr><td>input_scheme</td><td>OT_STRINGVECTOR</td><td>Custom input scheme</td><td>casadi::FunctionInternal</td></tr>
<tr><td>inputs_check</td><td>OT_BOOL</td><td>Throw exceptions when the numerical values of the inputs don't make sense</td><td>casadi::FunctionInternal</td></tr>
<tr><td>jac_penalty</td><td>OT_DOUBLE</td><td>When requested for a number of forward/reverse directions,   it may be cheaper to compute first the full jacobian and then multiply with seeds, rather than obtain the requested directions in a straightforward manner. Casadi uses a heuristic to decide which is cheaper. A high value of 'jac_penalty' makes it less likely for the heurstic to chose the full Jacobian strategy. The special value -1 indicates never to use the full Jacobian strategy</td><td>casadi::FunctionInternal</td></tr>
<tr><td>jit</td><td>OT_BOOL</td><td>Use just-in-time compiler to speed up the evaluation</td><td>casadi::FunctionInternal</td></tr>
<tr><td>jit_options</td><td>OT_DICT</td><td>Options to be passed to the jit compiler.</td><td>casadi::FunctionInternal</td></tr>
<tr><td>monitor</td><td>OT_STRINGVECTOR</td><td>Monitors to be activated</td><td>casadi::FunctionInternal</td></tr>
<tr><td>number_of_finite_elements</td><td>OT_INT</td><td>Number of finite elements</td><td>casadi::ImplicitFixedStepIntegrator</td></tr>
<tr><td>output_scheme</td><td>OT_STRINGVECTOR</td><td>Custom output scheme</td><td>casadi::FunctionInternal</td></tr>
<tr><td>output_t0</td><td>OT_BOOL</td><td>Output the state at the initial time</td><td>casadi::ImplicitFixedStepIntegrator</td></tr>
<tr><td>print_stats</td><td>OT_BOOL</td><td>Print out statistics after integration</td><td>casadi::ImplicitFixedStepIntegrator</td></tr>
<tr><td>regularity_check</td><td>OT_BOOL</td><td>Throw exceptions when NaN or Inf appears during evaluation</td><td>casadi::FunctionInternal</td></tr>
<tr><td>rootfinder</td><td>OT_STRING</td><td>An implicit function solver</td><td>casadi::ImplicitFixedStepIntegrator</td></tr>
<tr><td>rootfinder_options</td><td>OT_DICT</td><td>Options to be passed to the NLP Solver</td><td>casadi::ImplicitFixedStepIntegrator</td></tr>
<tr><td>t0</td><td>OT_DOUBLE</td><td>Beginning of the time horizon</td><td>casadi::ImplicitFixedStepIntegrator</td></tr>
<tr><td>tf</td><td>OT_DOUBLE</td><td>End of the time horizon</td><td>casadi::ImplicitFixedStepIntegrator</td></tr>
<tr><td>user_data</td><td>OT_VOIDPTR</td><td>A user-defined field that can be used to identify the function or pass additional information</td><td>casadi::FunctionInternal</td></tr>
<tr><td>verbose</td><td>OT_BOOL</td><td>Verbose evaluation -- for debugging</td><td>casadi::FunctionInternal</td></tr>
</table>
*/
/// \cond INTERNAL
/** \class casadi::ImplicitToNlp
\n
\par
<a name='options'></a><table>
<caption>List of available options</caption>
<tr><th>Id</th><th>Type</th><th>Description</th><th>Used in</th></tr>
<tr><td>constraints</td><td>OT_INTVECTOR</td><td>Constrain the unknowns. 0 (default): no constraint on ui, 1: ui &gt;= 0.0, -1: ui &lt;= 0.0, 2: ui &gt; 0.0, -2: ui &lt; 0.0.</td><td>casadi::Rootfinder</td></tr>
<tr><td>implicit_input</td><td>OT_INT</td><td>Index of the input that corresponds to the actual root-finding</td><td>casadi::Rootfinder</td></tr>
<tr><td>implicit_output</td><td>OT_INT</td><td>Index of the output that corresponds to the actual root-finding</td><td>casadi::Rootfinder</td></tr>
<tr><td>jacobian_function</td><td>OT_FUNCTION</td><td>Function object for calculating the Jacobian (autogenerated by default)</td><td>casadi::Rootfinder</td></tr>
<tr><td>linear_solver</td><td>OT_STRING</td><td>User-defined linear solver class. Needed for sensitivities.</td><td>casadi::Rootfinder</td></tr>
<tr><td>linear_solver_options</td><td>OT_DICT</td><td>Options to be passed to the linear solver.</td><td>casadi::Rootfinder</td></tr>
<tr><td>nlpsol</td><td>OT_STRING</td><td>Name of solver.</td><td>casadi::ImplicitToNlp</td></tr>
<tr><td>nlpsol_options</td><td>OT_DICT</td><td>Options to be passed to solver.</td><td>casadi::ImplicitToNlp</td></tr>
</table>
*/
/// \endcond
/** \addtogroup plugin_Rootfinder_nlp
\n
\par
<a name='options'></a><table>
<caption>List of available options</caption>
<tr><th>Id</th><th>Type</th><th>Description</th></tr>
<tr><td>nlpsol</td><td>OT_STRING</td><td>Name of solver.</td></tr>
<tr><td>nlpsol_options</td><td>OT_DICT</td><td>Options to be passed to solver.</td></tr>
</table>
*/
/** \addtogroup general_ImplicitToNlp
\n
\par
<a name='options'></a><table>
<caption>List of available options</caption>
<tr><th>Id</th><th>Type</th><th>Description</th><th>Used in</th></tr>
<tr><td>constraints</td><td>OT_INTVECTOR</td><td>Constrain the unknowns. 0 (default): no constraint on ui, 1: ui &gt;= 0.0, -1: ui &lt;= 0.0, 2: ui &gt; 0.0, -2: ui &lt; 0.0.</td><td>casadi::Rootfinder</td></tr>
<tr><td>implicit_input</td><td>OT_INT</td><td>Index of the input that corresponds to the actual root-finding</td><td>casadi::Rootfinder</td></tr>
<tr><td>implicit_output</td><td>OT_INT</td><td>Index of the output that corresponds to the actual root-finding</td><td>casadi::Rootfinder</td></tr>
<tr><td>jacobian_function</td><td>OT_FUNCTION</td><td>Function object for calculating the Jacobian (autogenerated by default)</td><td>casadi::Rootfinder</td></tr>
<tr><td>linear_solver</td><td>OT_STRING</td><td>User-defined linear solver class. Needed for sensitivities.</td><td>casadi::Rootfinder</td></tr>
<tr><td>linear_solver_options</td><td>OT_DICT</td><td>Options to be passed to the linear solver.</td><td>casadi::Rootfinder</td></tr>
<tr><td>nlpsol</td><td>OT_STRING</td><td>Name of solver.</td><td>casadi::ImplicitToNlp</td></tr>
<tr><td>nlpsol_options</td><td>OT_DICT</td><td>Options to be passed to solver.</td><td>casadi::ImplicitToNlp</td></tr>
</table>
*/
/// \cond INTERNAL
/** \class casadi::Integrator
\n
\par
<a name='options'></a><table>
<caption>List of available options</caption>
<tr><th>Id</th><th>Type</th><th>Description</th><th>Used in</th></tr>
<tr><td>ad_weight</td><td>OT_DOUBLE</td><td>Weighting factor for derivative calculation.When there is an option of either using forward or reverse mode directional derivatives, the condition ad_weight*nf&lt;=(1-ad_weight)*na is used where nf and na are estimates of the number of forward/reverse mode directional derivatives needed. By default, ad_weight is calculated automatically, but this can be overridden by setting this option. In particular, 0 means forcing forward mode and 1 forcing reverse mode. Leave unset for (class specific) heuristics.</td><td>casadi::FunctionInternal</td></tr>
<tr><td>ad_weight_sp</td><td>OT_DOUBLE</td><td>Weighting factor for sparsity pattern calculation calculation.Overrides default behavior. Set to 0 and 1 to force forward and reverse mode respectively. Cf. option \"ad_weight\".</td><td>casadi::FunctionInternal</td></tr>
<tr><td>augmented_options</td><td>OT_DICT</td><td>Options to be passed down to the augmented integrator, if one is constructed.</td><td>casadi::Integrator</td></tr>
<tr><td>compiler</td><td>OT_STRING</td><td>Just-in-time compiler plugin to be used.</td><td>casadi::FunctionInternal</td></tr>
<tr><td>expand</td><td>OT_BOOL</td><td>Replace MX with SX expressions in problem formulation [false]</td><td>casadi::Integrator</td></tr>
<tr><td>gather_stats</td><td>OT_BOOL</td><td>Flag to indicate whether statistics must be gathered</td><td>casadi::FunctionInternal</td></tr>
<tr><td>grid</td><td>OT_DOUBLEVECTOR</td><td>Time grid</td><td>casadi::Integrator</td></tr>
<tr><td>input_scheme</td><td>OT_STRINGVECTOR</td><td>Custom input scheme</td><td>casadi::FunctionInternal</td></tr>
<tr><td>inputs_check</td><td>OT_BOOL</td><td>Throw exceptions when the numerical values of the inputs don't make sense</td><td>casadi::FunctionInternal</td></tr>
<tr><td>jac_penalty</td><td>OT_DOUBLE</td><td>When requested for a number of forward/reverse directions,   it may be cheaper to compute first the full jacobian and then multiply with seeds, rather than obtain the requested directions in a straightforward manner. Casadi uses a heuristic to decide which is cheaper. A high value of 'jac_penalty' makes it less likely for the heurstic to chose the full Jacobian strategy. The special value -1 indicates never to use the full Jacobian strategy</td><td>casadi::FunctionInternal</td></tr>
<tr><td>jit</td><td>OT_BOOL</td><td>Use just-in-time compiler to speed up the evaluation</td><td>casadi::FunctionInternal</td></tr>
<tr><td>jit_options</td><td>OT_DICT</td><td>Options to be passed to the jit compiler.</td><td>casadi::FunctionInternal</td></tr>
<tr><td>monitor</td><td>OT_STRINGVECTOR</td><td>Monitors to be activated</td><td>casadi::FunctionInternal</td></tr>
<tr><td>number_of_finite_elements</td><td>OT_INT</td><td>Number of finite elements</td><td>casadi::Integrator</td></tr>
<tr><td>output_scheme</td><td>OT_STRINGVECTOR</td><td>Custom output scheme</td><td>casadi::FunctionInternal</td></tr>
<tr><td>output_t0</td><td>OT_BOOL</td><td>Output the state at the initial time</td><td>casadi::Integrator</td></tr>
<tr><td>print_stats</td><td>OT_BOOL</td><td>Print out statistics after integration</td><td>casadi::Integrator</td></tr>
<tr><td>regularity_check</td><td>OT_BOOL</td><td>Throw exceptions when NaN or Inf appears during evaluation</td><td>casadi::FunctionInternal</td></tr>
<tr><td>rootfinder</td><td>OT_STRING</td><td>An implicit function solver</td><td>casadi::Integrator</td></tr>
<tr><td>rootfinder_options</td><td>OT_DICT</td><td>Options to be passed to the NLP Solver</td><td>casadi::Integrator</td></tr>
<tr><td>t0</td><td>OT_DOUBLE</td><td>Beginning of the time horizon</td><td>casadi::Integrator</td></tr>
<tr><td>tf</td><td>OT_DOUBLE</td><td>End of the time horizon</td><td>casadi::Integrator</td></tr>
<tr><td>user_data</td><td>OT_VOIDPTR</td><td>A user-defined field that can be used to identify the function or pass additional information</td><td>casadi::FunctionInternal</td></tr>
<tr><td>verbose</td><td>OT_BOOL</td><td>Verbose evaluation -- for debugging</td><td>casadi::FunctionInternal</td></tr>
</table>
*/
/// \endcond
/** \addtogroup general_Integrator
\n
\par
<a name='options'></a><table>
<caption>List of available options</caption>
<tr><th>Id</th><th>Type</th><th>Description</th><th>Used in</th></tr>
<tr><td>ad_weight</td><td>OT_DOUBLE</td><td>Weighting factor for derivative calculation.When there is an option of either using forward or reverse mode directional derivatives, the condition ad_weight*nf&lt;=(1-ad_weight)*na is used where nf and na are estimates of the number of forward/reverse mode directional derivatives needed. By default, ad_weight is calculated automatically, but this can be overridden by setting this option. In particular, 0 means forcing forward mode and 1 forcing reverse mode. Leave unset for (class specific) heuristics.</td><td>casadi::FunctionInternal</td></tr>
<tr><td>ad_weight_sp</td><td>OT_DOUBLE</td><td>Weighting factor for sparsity pattern calculation calculation.Overrides default behavior. Set to 0 and 1 to force forward and reverse mode respectively. Cf. option \"ad_weight\".</td><td>casadi::FunctionInternal</td></tr>
<tr><td>augmented_options</td><td>OT_DICT</td><td>Options to be passed down to the augmented integrator, if one is constructed.</td><td>casadi::Integrator</td></tr>
<tr><td>compiler</td><td>OT_STRING</td><td>Just-in-time compiler plugin to be used.</td><td>casadi::FunctionInternal</td></tr>
<tr><td>expand</td><td>OT_BOOL</td><td>Replace MX with SX expressions in problem formulation [false]</td><td>casadi::Integrator</td></tr>
<tr><td>gather_stats</td><td>OT_BOOL</td><td>Flag to indicate whether statistics must be gathered</td><td>casadi::FunctionInternal</td></tr>
<tr><td>grid</td><td>OT_DOUBLEVECTOR</td><td>Time grid</td><td>casadi::Integrator</td></tr>
<tr><td>input_scheme</td><td>OT_STRINGVECTOR</td><td>Custom input scheme</td><td>casadi::FunctionInternal</td></tr>
<tr><td>inputs_check</td><td>OT_BOOL</td><td>Throw exceptions when the numerical values of the inputs don't make sense</td><td>casadi::FunctionInternal</td></tr>
<tr><td>jac_penalty</td><td>OT_DOUBLE</td><td>When requested for a number of forward/reverse directions,   it may be cheaper to compute first the full jacobian and then multiply with seeds, rather than obtain the requested directions in a straightforward manner. Casadi uses a heuristic to decide which is cheaper. A high value of 'jac_penalty' makes it less likely for the heurstic to chose the full Jacobian strategy. The special value -1 indicates never to use the full Jacobian strategy</td><td>casadi::FunctionInternal</td></tr>
<tr><td>jit</td><td>OT_BOOL</td><td>Use just-in-time compiler to speed up the evaluation</td><td>casadi::FunctionInternal</td></tr>
<tr><td>jit_options</td><td>OT_DICT</td><td>Options to be passed to the jit compiler.</td><td>casadi::FunctionInternal</td></tr>
<tr><td>monitor</td><td>OT_STRINGVECTOR</td><td>Monitors to be activated</td><td>casadi::FunctionInternal</td></tr>
<tr><td>number_of_finite_elements</td><td>OT_INT</td><td>Number of finite elements</td><td>casadi::Integrator</td></tr>
<tr><td>output_scheme</td><td>OT_STRINGVECTOR</td><td>Custom output scheme</td><td>casadi::FunctionInternal</td></tr>
<tr><td>output_t0</td><td>OT_BOOL</td><td>Output the state at the initial time</td><td>casadi::Integrator</td></tr>
<tr><td>print_stats</td><td>OT_BOOL</td><td>Print out statistics after integration</td><td>casadi::Integrator</td></tr>
<tr><td>regularity_check</td><td>OT_BOOL</td><td>Throw exceptions when NaN or Inf appears during evaluation</td><td>casadi::FunctionInternal</td></tr>
<tr><td>rootfinder</td><td>OT_STRING</td><td>An implicit function solver</td><td>casadi::Integrator</td></tr>
<tr><td>rootfinder_options</td><td>OT_DICT</td><td>Options to be passed to the NLP Solver</td><td>casadi::Integrator</td></tr>
<tr><td>t0</td><td>OT_DOUBLE</td><td>Beginning of the time horizon</td><td>casadi::Integrator</td></tr>
<tr><td>tf</td><td>OT_DOUBLE</td><td>End of the time horizon</td><td>casadi::Integrator</td></tr>
<tr><td>user_data</td><td>OT_VOIDPTR</td><td>A user-defined field that can be used to identify the function or pass additional information</td><td>casadi::FunctionInternal</td></tr>
<tr><td>verbose</td><td>OT_BOOL</td><td>Verbose evaluation -- for debugging</td><td>casadi::FunctionInternal</td></tr>
</table>
*/
/// \cond INTERNAL
/** \class casadi::IpoptInterface
\n
\par
<a name='options'></a><table>
<caption>List of available options</caption>
<tr><th>Id</th><th>Type</th><th>Description</th><th>Used in</th></tr>
<tr><td>con_integer_md</td><td>OT_DICT</td><td>Integer metadata (a dictionary with lists of integers) about constraints to be passed to IPOPT</td><td>casadi::IpoptInterface</td></tr>
<tr><td>con_numeric_md</td><td>OT_DICT</td><td>Numeric metadata (a dictionary with lists of reals) about constraints to be passed to IPOPT</td><td>casadi::IpoptInterface</td></tr>
<tr><td>con_string_md</td><td>OT_DICT</td><td>String metadata (a dictionary with lists of strings) about constraints to be passed to IPOPT</td><td>casadi::IpoptInterface</td></tr>
<tr><td>eval_errors_fatal</td><td>OT_BOOL</td><td>When errors occur during evaluation of f,g,...,stop the iterations</td><td>casadi::Nlpsol</td></tr>
<tr><td>expand</td><td>OT_BOOL</td><td>Replace MX with SX expressions in problem formulation [false]</td><td>casadi::Nlpsol</td></tr>
<tr><td>grad_f</td><td>OT_FUNCTION</td><td>Function for calculating the gradient of the objective (column, autogenerated by default)</td><td>casadi::IpoptInterface</td></tr>
<tr><td>grad_f_options</td><td>OT_DICT</td><td>Options for the autogenerated gradient of the objective.</td><td>casadi::IpoptInterface</td></tr>
<tr><td>hess_lag</td><td>OT_FUNCTION</td><td>Function for calculating the Hessian of the Lagrangian (autogenerated by default)</td><td>casadi::IpoptInterface</td></tr>
<tr><td>hess_lag_options</td><td>OT_DICT</td><td>Options for the autogenerated Hessian of the Lagrangian.</td><td>casadi::IpoptInterface</td></tr>
<tr><td>ignore_check_vec</td><td>OT_BOOL</td><td>If set to true, the input shape of F will not be checked.</td><td>casadi::Nlpsol</td></tr>
<tr><td>ipopt</td><td>OT_DICT</td><td>Options to be passed to IPOPT</td><td>casadi::IpoptInterface</td></tr>
<tr><td>iteration_callback</td><td>OT_FUNCTION</td><td>A function that will be called at each iteration with the solver as input. Check documentation of Callback.</td><td>casadi::Nlpsol</td></tr>
<tr><td>iteration_callback_ignore_errors</td><td>OT_BOOL</td><td>If set to true, errors thrown by iteration_callback will be ignored.</td><td>casadi::Nlpsol</td></tr>
<tr><td>iteration_callback_step</td><td>OT_INT</td><td>Only call the callback function every few iterations.</td><td>casadi::Nlpsol</td></tr>
<tr><td>jac_g</td><td>OT_FUNCTION</td><td>Function for calculating the Jacobian of the constraints (autogenerated by default)</td><td>casadi::IpoptInterface</td></tr>
<tr><td>jac_g_options</td><td>OT_DICT</td><td>Options for the autogenerated Jacobian of the constraints.</td><td>casadi::IpoptInterface</td></tr>
<tr><td>pass_nonlinear_variables</td><td>OT_BOOL</td><td>Pass list of variables entering nonlinearly to IPOPT</td><td>casadi::IpoptInterface</td></tr>
<tr><td>print_time</td><td>OT_BOOL</td><td>print information about execution time</td><td>casadi::IpoptInterface</td></tr>
<tr><td>var_integer_md</td><td>OT_DICT</td><td>Integer metadata (a dictionary with lists of integers) about variables to be passed to IPOPT</td><td>casadi::IpoptInterface</td></tr>
<tr><td>var_numeric_md</td><td>OT_DICT</td><td>Numeric metadata (a dictionary with lists of reals) about variables to be passed to IPOPT</td><td>casadi::IpoptInterface</td></tr>
<tr><td>var_string_md</td><td>OT_DICT</td><td>String metadata (a dictionary with lists of strings) about variables to be passed to IPOPT</td><td>casadi::IpoptInterface</td></tr>
<tr><td>verbose_init</td><td>OT_BOOL</td><td>Print out timing information about the different stages of initialization</td><td>casadi::Nlpsol</td></tr>
<tr><td>warn_initial_bounds</td><td>OT_BOOL</td><td>Warn if the initial guess does not satisfy LBX and UBX</td><td>casadi::Nlpsol</td></tr>
</table>
*/
/// \endcond
/** \addtogroup plugin_Nlpsol_ipopt
\n
\par
<a name='options'></a><table>
<caption>List of available options</caption>
<tr><th>Id</th><th>Type</th><th>Description</th></tr>
<tr><td>con_integer_md</td><td>OT_DICT</td><td>Integer metadata (a dictionary with lists of integers) about constraints to be passed to IPOPT</td></tr>
<tr><td>con_numeric_md</td><td>OT_DICT</td><td>Numeric metadata (a dictionary with lists of reals) about constraints to be passed to IPOPT</td></tr>
<tr><td>con_string_md</td><td>OT_DICT</td><td>String metadata (a dictionary with lists of strings) about constraints to be passed to IPOPT</td></tr>
<tr><td>grad_f</td><td>OT_FUNCTION</td><td>Function for calculating the gradient of the objective (column, autogenerated by default)</td></tr>
<tr><td>grad_f_options</td><td>OT_DICT</td><td>Options for the autogenerated gradient of the objective.</td></tr>
<tr><td>hess_lag</td><td>OT_FUNCTION</td><td>Function for calculating the Hessian of the Lagrangian (autogenerated by default)</td></tr>
<tr><td>hess_lag_options</td><td>OT_DICT</td><td>Options for the autogenerated Hessian of the Lagrangian.</td></tr>
<tr><td>ipopt</td><td>OT_DICT</td><td>Options to be passed to IPOPT</td></tr>
<tr><td>jac_g</td><td>OT_FUNCTION</td><td>Function for calculating the Jacobian of the constraints (autogenerated by default)</td></tr>
<tr><td>jac_g_options</td><td>OT_DICT</td><td>Options for the autogenerated Jacobian of the constraints.</td></tr>
<tr><td>pass_nonlinear_variables</td><td>OT_BOOL</td><td>Pass list of variables entering nonlinearly to IPOPT</td></tr>
<tr><td>print_time</td><td>OT_BOOL</td><td>print information about execution time</td></tr>
<tr><td>var_integer_md</td><td>OT_DICT</td><td>Integer metadata (a dictionary with lists of integers) about variables to be passed to IPOPT</td></tr>
<tr><td>var_numeric_md</td><td>OT_DICT</td><td>Numeric metadata (a dictionary with lists of reals) about variables to be passed to IPOPT</td></tr>
<tr><td>var_string_md</td><td>OT_DICT</td><td>String metadata (a dictionary with lists of strings) about variables to be passed to IPOPT</td></tr>
</table>
*/
/** \addtogroup general_IpoptInterface
\n
\par
<a name='options'></a><table>
<caption>List of available options</caption>
<tr><th>Id</th><th>Type</th><th>Description</th><th>Used in</th></tr>
<tr><td>con_integer_md</td><td>OT_DICT</td><td>Integer metadata (a dictionary with lists of integers) about constraints to be passed to IPOPT</td><td>casadi::IpoptInterface</td></tr>
<tr><td>con_numeric_md</td><td>OT_DICT</td><td>Numeric metadata (a dictionary with lists of reals) about constraints to be passed to IPOPT</td><td>casadi::IpoptInterface</td></tr>
<tr><td>con_string_md</td><td>OT_DICT</td><td>String metadata (a dictionary with lists of strings) about constraints to be passed to IPOPT</td><td>casadi::IpoptInterface</td></tr>
<tr><td>eval_errors_fatal</td><td>OT_BOOL</td><td>When errors occur during evaluation of f,g,...,stop the iterations</td><td>casadi::Nlpsol</td></tr>
<tr><td>expand</td><td>OT_BOOL</td><td>Replace MX with SX expressions in problem formulation [false]</td><td>casadi::Nlpsol</td></tr>
<tr><td>grad_f</td><td>OT_FUNCTION</td><td>Function for calculating the gradient of the objective (column, autogenerated by default)</td><td>casadi::IpoptInterface</td></tr>
<tr><td>grad_f_options</td><td>OT_DICT</td><td>Options for the autogenerated gradient of the objective.</td><td>casadi::IpoptInterface</td></tr>
<tr><td>hess_lag</td><td>OT_FUNCTION</td><td>Function for calculating the Hessian of the Lagrangian (autogenerated by default)</td><td>casadi::IpoptInterface</td></tr>
<tr><td>hess_lag_options</td><td>OT_DICT</td><td>Options for the autogenerated Hessian of the Lagrangian.</td><td>casadi::IpoptInterface</td></tr>
<tr><td>ignore_check_vec</td><td>OT_BOOL</td><td>If set to true, the input shape of F will not be checked.</td><td>casadi::Nlpsol</td></tr>
<tr><td>ipopt</td><td>OT_DICT</td><td>Options to be passed to IPOPT</td><td>casadi::IpoptInterface</td></tr>
<tr><td>iteration_callback</td><td>OT_FUNCTION</td><td>A function that will be called at each iteration with the solver as input. Check documentation of Callback.</td><td>casadi::Nlpsol</td></tr>
<tr><td>iteration_callback_ignore_errors</td><td>OT_BOOL</td><td>If set to true, errors thrown by iteration_callback will be ignored.</td><td>casadi::Nlpsol</td></tr>
<tr><td>iteration_callback_step</td><td>OT_INT</td><td>Only call the callback function every few iterations.</td><td>casadi::Nlpsol</td></tr>
<tr><td>jac_g</td><td>OT_FUNCTION</td><td>Function for calculating the Jacobian of the constraints (autogenerated by default)</td><td>casadi::IpoptInterface</td></tr>
<tr><td>jac_g_options</td><td>OT_DICT</td><td>Options for the autogenerated Jacobian of the constraints.</td><td>casadi::IpoptInterface</td></tr>
<tr><td>pass_nonlinear_variables</td><td>OT_BOOL</td><td>Pass list of variables entering nonlinearly to IPOPT</td><td>casadi::IpoptInterface</td></tr>
<tr><td>print_time</td><td>OT_BOOL</td><td>print information about execution time</td><td>casadi::IpoptInterface</td></tr>
<tr><td>var_integer_md</td><td>OT_DICT</td><td>Integer metadata (a dictionary with lists of integers) about variables to be passed to IPOPT</td><td>casadi::IpoptInterface</td></tr>
<tr><td>var_numeric_md</td><td>OT_DICT</td><td>Numeric metadata (a dictionary with lists of reals) about variables to be passed to IPOPT</td><td>casadi::IpoptInterface</td></tr>
<tr><td>var_string_md</td><td>OT_DICT</td><td>String metadata (a dictionary with lists of strings) about variables to be passed to IPOPT</td><td>casadi::IpoptInterface</td></tr>
<tr><td>verbose_init</td><td>OT_BOOL</td><td>Print out timing information about the different stages of initialization</td><td>casadi::Nlpsol</td></tr>
<tr><td>warn_initial_bounds</td><td>OT_BOOL</td><td>Warn if the initial guess does not satisfy LBX and UBX</td><td>casadi::Nlpsol</td></tr>
</table>
*/
/// \cond INTERNAL
/** \class casadi::Jit
\n
\par
<a name='options'></a><table>
<caption>List of available options</caption>
<tr><th>Id</th><th>Type</th><th>Description</th><th>Used in</th></tr>
<tr><td>ad_weight</td><td>OT_DOUBLE</td><td>Weighting factor for derivative calculation.When there is an option of either using forward or reverse mode directional derivatives, the condition ad_weight*nf&lt;=(1-ad_weight)*na is used where nf and na are estimates of the number of forward/reverse mode directional derivatives needed. By default, ad_weight is calculated automatically, but this can be overridden by setting this option. In particular, 0 means forcing forward mode and 1 forcing reverse mode. Leave unset for (class specific) heuristics.</td><td>casadi::FunctionInternal</td></tr>
<tr><td>ad_weight_sp</td><td>OT_DOUBLE</td><td>Weighting factor for sparsity pattern calculation calculation.Overrides default behavior. Set to 0 and 1 to force forward and reverse mode respectively. Cf. option \"ad_weight\".</td><td>casadi::FunctionInternal</td></tr>
<tr><td>compiler</td><td>OT_STRING</td><td>Just-in-time compiler plugin to be used.</td><td>casadi::FunctionInternal</td></tr>
<tr><td>gather_stats</td><td>OT_BOOL</td><td>Flag to indicate whether statistics must be gathered</td><td>casadi::FunctionInternal</td></tr>
<tr><td>hess</td><td>OT_STRING</td><td>Function body for Hessian</td><td>casadi::Jit</td></tr>
<tr><td>input_scheme</td><td>OT_STRINGVECTOR</td><td>Custom input scheme</td><td>casadi::FunctionInternal</td></tr>
<tr><td>inputs_check</td><td>OT_BOOL</td><td>Throw exceptions when the numerical values of the inputs don't make sense</td><td>casadi::FunctionInternal</td></tr>
<tr><td>jac</td><td>OT_STRING</td><td>Function body for Jacobian</td><td>casadi::Jit</td></tr>
<tr><td>jac_penalty</td><td>OT_DOUBLE</td><td>When requested for a number of forward/reverse directions,   it may be cheaper to compute first the full jacobian and then multiply with seeds, rather than obtain the requested directions in a straightforward manner. Casadi uses a heuristic to decide which is cheaper. A high value of 'jac_penalty' makes it less likely for the heurstic to chose the full Jacobian strategy. The special value -1 indicates never to use the full Jacobian strategy</td><td>casadi::FunctionInternal</td></tr>
<tr><td>jit</td><td>OT_BOOL</td><td>Use just-in-time compiler to speed up the evaluation</td><td>casadi::FunctionInternal</td></tr>
<tr><td>jit_options</td><td>OT_DICT</td><td>Options to be passed to the jit compiler.</td><td>casadi::FunctionInternal</td></tr>
<tr><td>monitor</td><td>OT_STRINGVECTOR</td><td>Monitors to be activated</td><td>casadi::FunctionInternal</td></tr>
<tr><td>output_scheme</td><td>OT_STRINGVECTOR</td><td>Custom output scheme</td><td>casadi::FunctionInternal</td></tr>
<tr><td>regularity_check</td><td>OT_BOOL</td><td>Throw exceptions when NaN or Inf appears during evaluation</td><td>casadi::FunctionInternal</td></tr>
<tr><td>user_data</td><td>OT_VOIDPTR</td><td>A user-defined field that can be used to identify the function or pass additional information</td><td>casadi::FunctionInternal</td></tr>
<tr><td>verbose</td><td>OT_BOOL</td><td>Verbose evaluation -- for debugging</td><td>casadi::FunctionInternal</td></tr>
</table>
*/
/// \endcond
/// \cond INTERNAL
/** \class casadi::KinsolInterface
\n
\par
<a name='options'></a><table>
<caption>List of available options</caption>
<tr><th>Id</th><th>Type</th><th>Description</th><th>Used in</th></tr>
<tr><td>abstol</td><td>OT_DOUBLE</td><td>Stopping criterion tolerance</td><td>casadi::KinsolInterface</td></tr>
<tr><td>constraints</td><td>OT_INTVECTOR</td><td>Constrain the unknowns. 0 (default): no constraint on ui, 1: ui &gt;= 0.0, -1: ui &lt;= 0.0, 2: ui &gt; 0.0, -2: ui &lt; 0.0.</td><td>casadi::Rootfinder</td></tr>
<tr><td>disable_internal_warnings</td><td>OT_BOOL</td><td>Disable KINSOL internal warning messages</td><td>casadi::KinsolInterface</td></tr>
<tr><td>exact_jacobian</td><td>OT_BOOL</td><td>Use exact Jacobian information</td><td>casadi::KinsolInterface</td></tr>
<tr><td>f_scale</td><td>OT_DOUBLEVECTOR</td><td>Equation scaling factors</td><td>casadi::KinsolInterface</td></tr>
<tr><td>implicit_input</td><td>OT_INT</td><td>Index of the input that corresponds to the actual root-finding</td><td>casadi::Rootfinder</td></tr>
<tr><td>implicit_output</td><td>OT_INT</td><td>Index of the output that corresponds to the actual root-finding</td><td>casadi::Rootfinder</td></tr>
<tr><td>iterative_solver</td><td>OT_STRING</td><td>gmres|bcgstab|tfqmr</td><td>casadi::KinsolInterface</td></tr>
<tr><td>jacobian_function</td><td>OT_FUNCTION</td><td>Function object for calculating the Jacobian (autogenerated by default)</td><td>casadi::Rootfinder</td></tr>
<tr><td>linear_solver</td><td>OT_STRING</td><td>User-defined linear solver class. Needed for sensitivities.</td><td>casadi::Rootfinder</td></tr>
<tr><td>linear_solver_options</td><td>OT_DICT</td><td>Options to be passed to the linear solver.</td><td>casadi::Rootfinder</td></tr>
<tr><td>linear_solver_type</td><td>OT_STRING</td><td>dense|banded|iterative|user_defined</td><td>casadi::KinsolInterface</td></tr>
<tr><td>lower_bandwidth</td><td>OT_INT</td><td>Lower bandwidth for banded linear solvers</td><td>casadi::KinsolInterface</td></tr>
<tr><td>max_iter</td><td>OT_INT</td><td>Maximum number of Newton iterations. Putting 0 sets the default value of KinSol.</td><td>casadi::KinsolInterface</td></tr>
<tr><td>max_krylov</td><td>OT_INT</td><td>Maximum Krylov space dimension</td><td>casadi::KinsolInterface</td></tr>
<tr><td>pretype</td><td>OT_STRING</td><td>Type of preconditioner</td><td>casadi::KinsolInterface</td></tr>
<tr><td>strategy</td><td>OT_STRING</td><td>Globalization strategy</td><td>casadi::KinsolInterface</td></tr>
<tr><td>u_scale</td><td>OT_DOUBLEVECTOR</td><td>Variable scaling factors</td><td>casadi::KinsolInterface</td></tr>
<tr><td>upper_bandwidth</td><td>OT_INT</td><td>Upper bandwidth for banded linear solvers</td><td>casadi::KinsolInterface</td></tr>
<tr><td>use_preconditioner</td><td>OT_BOOL</td><td>Precondition an iterative solver</td><td>casadi::KinsolInterface</td></tr>
</table>
*/
/// \endcond
/** \addtogroup plugin_Rootfinder_kinsol
\n
\par
<a name='options'></a><table>
<caption>List of available options</caption>
<tr><th>Id</th><th>Type</th><th>Description</th></tr>
<tr><td>abstol</td><td>OT_DOUBLE</td><td>Stopping criterion tolerance</td></tr>
<tr><td>disable_internal_warnings</td><td>OT_BOOL</td><td>Disable KINSOL internal warning messages</td></tr>
<tr><td>exact_jacobian</td><td>OT_BOOL</td><td>Use exact Jacobian information</td></tr>
<tr><td>f_scale</td><td>OT_DOUBLEVECTOR</td><td>Equation scaling factors</td></tr>
<tr><td>iterative_solver</td><td>OT_STRING</td><td>gmres|bcgstab|tfqmr</td></tr>
<tr><td>linear_solver_type</td><td>OT_STRING</td><td>dense|banded|iterative|user_defined</td></tr>
<tr><td>lower_bandwidth</td><td>OT_INT</td><td>Lower bandwidth for banded linear solvers</td></tr>
<tr><td>max_iter</td><td>OT_INT</td><td>Maximum number of Newton iterations. Putting 0 sets the default value of KinSol.</td></tr>
<tr><td>max_krylov</td><td>OT_INT</td><td>Maximum Krylov space dimension</td></tr>
<tr><td>pretype</td><td>OT_STRING</td><td>Type of preconditioner</td></tr>
<tr><td>strategy</td><td>OT_STRING</td><td>Globalization strategy</td></tr>
<tr><td>u_scale</td><td>OT_DOUBLEVECTOR</td><td>Variable scaling factors</td></tr>
<tr><td>upper_bandwidth</td><td>OT_INT</td><td>Upper bandwidth for banded linear solvers</td></tr>
<tr><td>use_preconditioner</td><td>OT_BOOL</td><td>Precondition an iterative solver</td></tr>
</table>
*/
/** \addtogroup general_KinsolInterface
\n
\par
<a name='options'></a><table>
<caption>List of available options</caption>
<tr><th>Id</th><th>Type</th><th>Description</th><th>Used in</th></tr>
<tr><td>abstol</td><td>OT_DOUBLE</td><td>Stopping criterion tolerance</td><td>casadi::KinsolInterface</td></tr>
<tr><td>constraints</td><td>OT_INTVECTOR</td><td>Constrain the unknowns. 0 (default): no constraint on ui, 1: ui &gt;= 0.0, -1: ui &lt;= 0.0, 2: ui &gt; 0.0, -2: ui &lt; 0.0.</td><td>casadi::Rootfinder</td></tr>
<tr><td>disable_internal_warnings</td><td>OT_BOOL</td><td>Disable KINSOL internal warning messages</td><td>casadi::KinsolInterface</td></tr>
<tr><td>exact_jacobian</td><td>OT_BOOL</td><td>Use exact Jacobian information</td><td>casadi::KinsolInterface</td></tr>
<tr><td>f_scale</td><td>OT_DOUBLEVECTOR</td><td>Equation scaling factors</td><td>casadi::KinsolInterface</td></tr>
<tr><td>implicit_input</td><td>OT_INT</td><td>Index of the input that corresponds to the actual root-finding</td><td>casadi::Rootfinder</td></tr>
<tr><td>implicit_output</td><td>OT_INT</td><td>Index of the output that corresponds to the actual root-finding</td><td>casadi::Rootfinder</td></tr>
<tr><td>iterative_solver</td><td>OT_STRING</td><td>gmres|bcgstab|tfqmr</td><td>casadi::KinsolInterface</td></tr>
<tr><td>jacobian_function</td><td>OT_FUNCTION</td><td>Function object for calculating the Jacobian (autogenerated by default)</td><td>casadi::Rootfinder</td></tr>
<tr><td>linear_solver</td><td>OT_STRING</td><td>User-defined linear solver class. Needed for sensitivities.</td><td>casadi::Rootfinder</td></tr>
<tr><td>linear_solver_options</td><td>OT_DICT</td><td>Options to be passed to the linear solver.</td><td>casadi::Rootfinder</td></tr>
<tr><td>linear_solver_type</td><td>OT_STRING</td><td>dense|banded|iterative|user_defined</td><td>casadi::KinsolInterface</td></tr>
<tr><td>lower_bandwidth</td><td>OT_INT</td><td>Lower bandwidth for banded linear solvers</td><td>casadi::KinsolInterface</td></tr>
<tr><td>max_iter</td><td>OT_INT</td><td>Maximum number of Newton iterations. Putting 0 sets the default value of KinSol.</td><td>casadi::KinsolInterface</td></tr>
<tr><td>max_krylov</td><td>OT_INT</td><td>Maximum Krylov space dimension</td><td>casadi::KinsolInterface</td></tr>
<tr><td>pretype</td><td>OT_STRING</td><td>Type of preconditioner</td><td>casadi::KinsolInterface</td></tr>
<tr><td>strategy</td><td>OT_STRING</td><td>Globalization strategy</td><td>casadi::KinsolInterface</td></tr>
<tr><td>u_scale</td><td>OT_DOUBLEVECTOR</td><td>Variable scaling factors</td><td>casadi::KinsolInterface</td></tr>
<tr><td>upper_bandwidth</td><td>OT_INT</td><td>Upper bandwidth for banded linear solvers</td><td>casadi::KinsolInterface</td></tr>
<tr><td>use_preconditioner</td><td>OT_BOOL</td><td>Precondition an iterative solver</td><td>casadi::KinsolInterface</td></tr>
</table>
*/
/// \cond INTERNAL
/** \class casadi::KnitroInterface
\n
\par
<a name='options'></a><table>
<caption>List of available options</caption>
<tr><th>Id</th><th>Type</th><th>Description</th><th>Used in</th></tr>
<tr><td>contype</td><td>OT_INTVECTOR</td><td>Type of constraint</td><td>casadi::KnitroInterface</td></tr>
<tr><td>eval_errors_fatal</td><td>OT_BOOL</td><td>When errors occur during evaluation of f,g,...,stop the iterations</td><td>casadi::Nlpsol</td></tr>
<tr><td>expand</td><td>OT_BOOL</td><td>Replace MX with SX expressions in problem formulation [false]</td><td>casadi::Nlpsol</td></tr>
<tr><td>ignore_check_vec</td><td>OT_BOOL</td><td>If set to true, the input shape of F will not be checked.</td><td>casadi::Nlpsol</td></tr>
<tr><td>iteration_callback</td><td>OT_FUNCTION</td><td>A function that will be called at each iteration with the solver as input. Check documentation of Callback.</td><td>casadi::Nlpsol</td></tr>
<tr><td>iteration_callback_ignore_errors</td><td>OT_BOOL</td><td>If set to true, errors thrown by iteration_callback will be ignored.</td><td>casadi::Nlpsol</td></tr>
<tr><td>iteration_callback_step</td><td>OT_INT</td><td>Only call the callback function every few iterations.</td><td>casadi::Nlpsol</td></tr>
<tr><td>knitro</td><td>OT_DICT</td><td>Options to be passed to KNITRO</td><td>casadi::KnitroInterface</td></tr>
<tr><td>verbose_init</td><td>OT_BOOL</td><td>Print out timing information about the different stages of initialization</td><td>casadi::Nlpsol</td></tr>
<tr><td>warn_initial_bounds</td><td>OT_BOOL</td><td>Warn if the initial guess does not satisfy LBX and UBX</td><td>casadi::Nlpsol</td></tr>
</table>
*/
/// \endcond
/** \addtogroup plugin_Nlpsol_knitro
\n
\par
<a name='options'></a><table>
<caption>List of available options</caption>
<tr><th>Id</th><th>Type</th><th>Description</th></tr>
<tr><td>contype</td><td>OT_INTVECTOR</td><td>Type of constraint</td></tr>
<tr><td>knitro</td><td>OT_DICT</td><td>Options to be passed to KNITRO</td></tr>
</table>
*/
/** \addtogroup general_KnitroInterface
\n
\par
<a name='options'></a><table>
<caption>List of available options</caption>
<tr><th>Id</th><th>Type</th><th>Description</th><th>Used in</th></tr>
<tr><td>contype</td><td>OT_INTVECTOR</td><td>Type of constraint</td><td>casadi::KnitroInterface</td></tr>
<tr><td>eval_errors_fatal</td><td>OT_BOOL</td><td>When errors occur during evaluation of f,g,...,stop the iterations</td><td>casadi::Nlpsol</td></tr>
<tr><td>expand</td><td>OT_BOOL</td><td>Replace MX with SX expressions in problem formulation [false]</td><td>casadi::Nlpsol</td></tr>
<tr><td>ignore_check_vec</td><td>OT_BOOL</td><td>If set to true, the input shape of F will not be checked.</td><td>casadi::Nlpsol</td></tr>
<tr><td>iteration_callback</td><td>OT_FUNCTION</td><td>A function that will be called at each iteration with the solver as input. Check documentation of Callback.</td><td>casadi::Nlpsol</td></tr>
<tr><td>iteration_callback_ignore_errors</td><td>OT_BOOL</td><td>If set to true, errors thrown by iteration_callback will be ignored.</td><td>casadi::Nlpsol</td></tr>
<tr><td>iteration_callback_step</td><td>OT_INT</td><td>Only call the callback function every few iterations.</td><td>casadi::Nlpsol</td></tr>
<tr><td>knitro</td><td>OT_DICT</td><td>Options to be passed to KNITRO</td><td>casadi::KnitroInterface</td></tr>
<tr><td>verbose_init</td><td>OT_BOOL</td><td>Print out timing information about the different stages of initialization</td><td>casadi::Nlpsol</td></tr>
<tr><td>warn_initial_bounds</td><td>OT_BOOL</td><td>Warn if the initial guess does not satisfy LBX and UBX</td><td>casadi::Nlpsol</td></tr>
</table>
*/
/// \cond INTERNAL
/** \class casadi::LapackLu
\n
\par
<a name='options'></a><table>
<caption>List of available options</caption>
<tr><th>Id</th><th>Type</th><th>Description</th><th>Used in</th></tr>
<tr><td>ad_weight</td><td>OT_DOUBLE</td><td>Weighting factor for derivative calculation.When there is an option of either using forward or reverse mode directional derivatives, the condition ad_weight*nf&lt;=(1-ad_weight)*na is used where nf and na are estimates of the number of forward/reverse mode directional derivatives needed. By default, ad_weight is calculated automatically, but this can be overridden by setting this option. In particular, 0 means forcing forward mode and 1 forcing reverse mode. Leave unset for (class specific) heuristics.</td><td>casadi::FunctionInternal</td></tr>
<tr><td>ad_weight_sp</td><td>OT_DOUBLE</td><td>Weighting factor for sparsity pattern calculation calculation.Overrides default behavior. Set to 0 and 1 to force forward and reverse mode respectively. Cf. option \"ad_weight\".</td><td>casadi::FunctionInternal</td></tr>
<tr><td>allow_equilibration_failure</td><td>OT_BOOL</td><td>Non-fatal error when equilibration fails</td><td>casadi::LapackLu</td></tr>
<tr><td>compiler</td><td>OT_STRING</td><td>Just-in-time compiler plugin to be used.</td><td>casadi::FunctionInternal</td></tr>
<tr><td>equilibration</td><td>OT_BOOL</td><td>Equilibrate the matrix</td><td>casadi::LapackLu</td></tr>
<tr><td>gather_stats</td><td>OT_BOOL</td><td>Flag to indicate whether statistics must be gathered</td><td>casadi::FunctionInternal</td></tr>
<tr><td>input_scheme</td><td>OT_STRINGVECTOR</td><td>Custom input scheme</td><td>casadi::FunctionInternal</td></tr>
<tr><td>inputs_check</td><td>OT_BOOL</td><td>Throw exceptions when the numerical values of the inputs don't make sense</td><td>casadi::FunctionInternal</td></tr>
<tr><td>jac_penalty</td><td>OT_DOUBLE</td><td>When requested for a number of forward/reverse directions,   it may be cheaper to compute first the full jacobian and then multiply with seeds, rather than obtain the requested directions in a straightforward manner. Casadi uses a heuristic to decide which is cheaper. A high value of 'jac_penalty' makes it less likely for the heurstic to chose the full Jacobian strategy. The special value -1 indicates never to use the full Jacobian strategy</td><td>casadi::FunctionInternal</td></tr>
<tr><td>jit</td><td>OT_BOOL</td><td>Use just-in-time compiler to speed up the evaluation</td><td>casadi::FunctionInternal</td></tr>
<tr><td>jit_options</td><td>OT_DICT</td><td>Options to be passed to the jit compiler.</td><td>casadi::FunctionInternal</td></tr>
<tr><td>monitor</td><td>OT_STRINGVECTOR</td><td>Monitors to be activated</td><td>casadi::FunctionInternal</td></tr>
<tr><td>output_scheme</td><td>OT_STRINGVECTOR</td><td>Custom output scheme</td><td>casadi::FunctionInternal</td></tr>
<tr><td>regularity_check</td><td>OT_BOOL</td><td>Throw exceptions when NaN or Inf appears during evaluation</td><td>casadi::FunctionInternal</td></tr>
<tr><td>user_data</td><td>OT_VOIDPTR</td><td>A user-defined field that can be used to identify the function or pass additional information</td><td>casadi::FunctionInternal</td></tr>
<tr><td>verbose</td><td>OT_BOOL</td><td>Verbose evaluation -- for debugging</td><td>casadi::FunctionInternal</td></tr>
</table>
*/
/// \endcond
/** \addtogroup plugin_Linsol_lapacklu
\n
\par
<a name='options'></a><table>
<caption>List of available options</caption>
<tr><th>Id</th><th>Type</th><th>Description</th></tr>
<tr><td>allow_equilibration_failure</td><td>OT_BOOL</td><td>Non-fatal error when equilibration fails</td></tr>
<tr><td>equilibration</td><td>OT_BOOL</td><td>Equilibrate the matrix</td></tr>
</table>
*/
/** \addtogroup general_LapackLu
\n
\par
<a name='options'></a><table>
<caption>List of available options</caption>
<tr><th>Id</th><th>Type</th><th>Description</th><th>Used in</th></tr>
<tr><td>ad_weight</td><td>OT_DOUBLE</td><td>Weighting factor for derivative calculation.When there is an option of either using forward or reverse mode directional derivatives, the condition ad_weight*nf&lt;=(1-ad_weight)*na is used where nf and na are estimates of the number of forward/reverse mode directional derivatives needed. By default, ad_weight is calculated automatically, but this can be overridden by setting this option. In particular, 0 means forcing forward mode and 1 forcing reverse mode. Leave unset for (class specific) heuristics.</td><td>casadi::FunctionInternal</td></tr>
<tr><td>ad_weight_sp</td><td>OT_DOUBLE</td><td>Weighting factor for sparsity pattern calculation calculation.Overrides default behavior. Set to 0 and 1 to force forward and reverse mode respectively. Cf. option \"ad_weight\".</td><td>casadi::FunctionInternal</td></tr>
<tr><td>allow_equilibration_failure</td><td>OT_BOOL</td><td>Non-fatal error when equilibration fails</td><td>casadi::LapackLu</td></tr>
<tr><td>compiler</td><td>OT_STRING</td><td>Just-in-time compiler plugin to be used.</td><td>casadi::FunctionInternal</td></tr>
<tr><td>equilibration</td><td>OT_BOOL</td><td>Equilibrate the matrix</td><td>casadi::LapackLu</td></tr>
<tr><td>gather_stats</td><td>OT_BOOL</td><td>Flag to indicate whether statistics must be gathered</td><td>casadi::FunctionInternal</td></tr>
<tr><td>input_scheme</td><td>OT_STRINGVECTOR</td><td>Custom input scheme</td><td>casadi::FunctionInternal</td></tr>
<tr><td>inputs_check</td><td>OT_BOOL</td><td>Throw exceptions when the numerical values of the inputs don't make sense</td><td>casadi::FunctionInternal</td></tr>
<tr><td>jac_penalty</td><td>OT_DOUBLE</td><td>When requested for a number of forward/reverse directions,   it may be cheaper to compute first the full jacobian and then multiply with seeds, rather than obtain the requested directions in a straightforward manner. Casadi uses a heuristic to decide which is cheaper. A high value of 'jac_penalty' makes it less likely for the heurstic to chose the full Jacobian strategy. The special value -1 indicates never to use the full Jacobian strategy</td><td>casadi::FunctionInternal</td></tr>
<tr><td>jit</td><td>OT_BOOL</td><td>Use just-in-time compiler to speed up the evaluation</td><td>casadi::FunctionInternal</td></tr>
<tr><td>jit_options</td><td>OT_DICT</td><td>Options to be passed to the jit compiler.</td><td>casadi::FunctionInternal</td></tr>
<tr><td>monitor</td><td>OT_STRINGVECTOR</td><td>Monitors to be activated</td><td>casadi::FunctionInternal</td></tr>
<tr><td>output_scheme</td><td>OT_STRINGVECTOR</td><td>Custom output scheme</td><td>casadi::FunctionInternal</td></tr>
<tr><td>regularity_check</td><td>OT_BOOL</td><td>Throw exceptions when NaN or Inf appears during evaluation</td><td>casadi::FunctionInternal</td></tr>
<tr><td>user_data</td><td>OT_VOIDPTR</td><td>A user-defined field that can be used to identify the function or pass additional information</td><td>casadi::FunctionInternal</td></tr>
<tr><td>verbose</td><td>OT_BOOL</td><td>Verbose evaluation -- for debugging</td><td>casadi::FunctionInternal</td></tr>
</table>
*/
/// \cond INTERNAL
/** \class casadi::MXFunction
\n
\par
<a name='options'></a><table>
<caption>List of available options</caption>
<tr><th>Id</th><th>Type</th><th>Description</th><th>Used in</th></tr>
<tr><td>ad_weight</td><td>OT_DOUBLE</td><td>Weighting factor for derivative calculation.When there is an option of either using forward or reverse mode directional derivatives, the condition ad_weight*nf&lt;=(1-ad_weight)*na is used where nf and na are estimates of the number of forward/reverse mode directional derivatives needed. By default, ad_weight is calculated automatically, but this can be overridden by setting this option. In particular, 0 means forcing forward mode and 1 forcing reverse mode. Leave unset for (class specific) heuristics.</td><td>casadi::FunctionInternal</td></tr>
<tr><td>ad_weight_sp</td><td>OT_DOUBLE</td><td>Weighting factor for sparsity pattern calculation calculation.Overrides default behavior. Set to 0 and 1 to force forward and reverse mode respectively. Cf. option \"ad_weight\".</td><td>casadi::FunctionInternal</td></tr>
<tr><td>compiler</td><td>OT_STRING</td><td>Just-in-time compiler plugin to be used.</td><td>casadi::FunctionInternal</td></tr>
<tr><td>default_in</td><td>OT_DOUBLEVECTOR</td><td>Default input values</td><td>casadi::MXFunction</td></tr>
<tr><td>gather_stats</td><td>OT_BOOL</td><td>Flag to indicate whether statistics must be gathered</td><td>casadi::FunctionInternal</td></tr>
<tr><td>input_scheme</td><td>OT_STRINGVECTOR</td><td>Custom input scheme</td><td>casadi::FunctionInternal</td></tr>
<tr><td>inputs_check</td><td>OT_BOOL</td><td>Throw exceptions when the numerical values of the inputs don't make sense</td><td>casadi::FunctionInternal</td></tr>
<tr><td>jac_penalty</td><td>OT_DOUBLE</td><td>When requested for a number of forward/reverse directions,   it may be cheaper to compute first the full jacobian and then multiply with seeds, rather than obtain the requested directions in a straightforward manner. Casadi uses a heuristic to decide which is cheaper. A high value of 'jac_penalty' makes it less likely for the heurstic to chose the full Jacobian strategy. The special value -1 indicates never to use the full Jacobian strategy</td><td>casadi::FunctionInternal</td></tr>
<tr><td>jit</td><td>OT_BOOL</td><td>Use just-in-time compiler to speed up the evaluation</td><td>casadi::FunctionInternal</td></tr>
<tr><td>jit_options</td><td>OT_DICT</td><td>Options to be passed to the jit compiler.</td><td>casadi::FunctionInternal</td></tr>
<tr><td>live_variables</td><td>OT_BOOL</td><td>Reuse variables in the work vector</td><td>casadi::MXFunction</td></tr>
<tr><td>monitor</td><td>OT_STRINGVECTOR</td><td>Monitors to be activated</td><td>casadi::FunctionInternal</td></tr>
<tr><td>output_scheme</td><td>OT_STRINGVECTOR</td><td>Custom output scheme</td><td>casadi::FunctionInternal</td></tr>
<tr><td>regularity_check</td><td>OT_BOOL</td><td>Throw exceptions when NaN or Inf appears during evaluation</td><td>casadi::FunctionInternal</td></tr>
<tr><td>user_data</td><td>OT_VOIDPTR</td><td>A user-defined field that can be used to identify the function or pass additional information</td><td>casadi::FunctionInternal</td></tr>
<tr><td>verbose</td><td>OT_BOOL</td><td>Verbose evaluation -- for debugging</td><td>casadi::FunctionInternal</td></tr>
</table>
*/
/// \endcond
/// \cond INTERNAL
/** \class casadi::MapBase
\n
\par
<a name='options'></a><table>
<caption>List of available options</caption>
<tr><th>Id</th><th>Type</th><th>Description</th><th>Used in</th></tr>
<tr><td>ad_weight</td><td>OT_DOUBLE</td><td>Weighting factor for derivative calculation.When there is an option of either using forward or reverse mode directional derivatives, the condition ad_weight*nf&lt;=(1-ad_weight)*na is used where nf and na are estimates of the number of forward/reverse mode directional derivatives needed. By default, ad_weight is calculated automatically, but this can be overridden by setting this option. In particular, 0 means forcing forward mode and 1 forcing reverse mode. Leave unset for (class specific) heuristics.</td><td>casadi::FunctionInternal</td></tr>
<tr><td>ad_weight_sp</td><td>OT_DOUBLE</td><td>Weighting factor for sparsity pattern calculation calculation.Overrides default behavior. Set to 0 and 1 to force forward and reverse mode respectively. Cf. option \"ad_weight\".</td><td>casadi::FunctionInternal</td></tr>
<tr><td>compiler</td><td>OT_STRING</td><td>Just-in-time compiler plugin to be used.</td><td>casadi::FunctionInternal</td></tr>
<tr><td>gather_stats</td><td>OT_BOOL</td><td>Flag to indicate whether statistics must be gathered</td><td>casadi::FunctionInternal</td></tr>
<tr><td>input_scheme</td><td>OT_STRINGVECTOR</td><td>Custom input scheme</td><td>casadi::FunctionInternal</td></tr>
<tr><td>inputs_check</td><td>OT_BOOL</td><td>Throw exceptions when the numerical values of the inputs don't make sense</td><td>casadi::FunctionInternal</td></tr>
<tr><td>jac_penalty</td><td>OT_DOUBLE</td><td>When requested for a number of forward/reverse directions,   it may be cheaper to compute first the full jacobian and then multiply with seeds, rather than obtain the requested directions in a straightforward manner. Casadi uses a heuristic to decide which is cheaper. A high value of 'jac_penalty' makes it less likely for the heurstic to chose the full Jacobian strategy. The special value -1 indicates never to use the full Jacobian strategy</td><td>casadi::FunctionInternal</td></tr>
<tr><td>jit</td><td>OT_BOOL</td><td>Use just-in-time compiler to speed up the evaluation</td><td>casadi::FunctionInternal</td></tr>
<tr><td>jit_options</td><td>OT_DICT</td><td>Options to be passed to the jit compiler.</td><td>casadi::FunctionInternal</td></tr>
<tr><td>monitor</td><td>OT_STRINGVECTOR</td><td>Monitors to be activated</td><td>casadi::FunctionInternal</td></tr>
<tr><td>output_scheme</td><td>OT_STRINGVECTOR</td><td>Custom output scheme</td><td>casadi::FunctionInternal</td></tr>
<tr><td>parallelization</td><td>OT_STRING</td><td>Computational strategy for parallelization</td><td>casadi::MapBase</td></tr>
<tr><td>reduced_inputs</td><td>OT_INTVECTOR</td><td>Reduction for certain inputs</td><td>casadi::MapBase</td></tr>
<tr><td>reduced_outputs</td><td>OT_INTVECTOR</td><td>Reduction for certain outputs</td><td>casadi::MapBase</td></tr>
<tr><td>regularity_check</td><td>OT_BOOL</td><td>Throw exceptions when NaN or Inf appears during evaluation</td><td>casadi::FunctionInternal</td></tr>
<tr><td>user_data</td><td>OT_VOIDPTR</td><td>A user-defined field that can be used to identify the function or pass additional information</td><td>casadi::FunctionInternal</td></tr>
<tr><td>verbose</td><td>OT_BOOL</td><td>Verbose evaluation -- for debugging</td><td>casadi::FunctionInternal</td></tr>
</table>
*/
/// \endcond
/// \cond INTERNAL
/** \class casadi::MapReduce
\n
\par
<a name='options'></a><table>
<caption>List of available options</caption>
<tr><th>Id</th><th>Type</th><th>Description</th><th>Used in</th></tr>
<tr><td>ad_weight</td><td>OT_DOUBLE</td><td>Weighting factor for derivative calculation.When there is an option of either using forward or reverse mode directional derivatives, the condition ad_weight*nf&lt;=(1-ad_weight)*na is used where nf and na are estimates of the number of forward/reverse mode directional derivatives needed. By default, ad_weight is calculated automatically, but this can be overridden by setting this option. In particular, 0 means forcing forward mode and 1 forcing reverse mode. Leave unset for (class specific) heuristics.</td><td>casadi::FunctionInternal</td></tr>
<tr><td>ad_weight_sp</td><td>OT_DOUBLE</td><td>Weighting factor for sparsity pattern calculation calculation.Overrides default behavior. Set to 0 and 1 to force forward and reverse mode respectively. Cf. option \"ad_weight\".</td><td>casadi::FunctionInternal</td></tr>
<tr><td>compiler</td><td>OT_STRING</td><td>Just-in-time compiler plugin to be used.</td><td>casadi::FunctionInternal</td></tr>
<tr><td>gather_stats</td><td>OT_BOOL</td><td>Flag to indicate whether statistics must be gathered</td><td>casadi::FunctionInternal</td></tr>
<tr><td>input_scheme</td><td>OT_STRINGVECTOR</td><td>Custom input scheme</td><td>casadi::FunctionInternal</td></tr>
<tr><td>inputs_check</td><td>OT_BOOL</td><td>Throw exceptions when the numerical values of the inputs don't make sense</td><td>casadi::FunctionInternal</td></tr>
<tr><td>jac_penalty</td><td>OT_DOUBLE</td><td>When requested for a number of forward/reverse directions,   it may be cheaper to compute first the full jacobian and then multiply with seeds, rather than obtain the requested directions in a straightforward manner. Casadi uses a heuristic to decide which is cheaper. A high value of 'jac_penalty' makes it less likely for the heurstic to chose the full Jacobian strategy. The special value -1 indicates never to use the full Jacobian strategy</td><td>casadi::FunctionInternal</td></tr>
<tr><td>jit</td><td>OT_BOOL</td><td>Use just-in-time compiler to speed up the evaluation</td><td>casadi::FunctionInternal</td></tr>
<tr><td>jit_options</td><td>OT_DICT</td><td>Options to be passed to the jit compiler.</td><td>casadi::FunctionInternal</td></tr>
<tr><td>monitor</td><td>OT_STRINGVECTOR</td><td>Monitors to be activated</td><td>casadi::FunctionInternal</td></tr>
<tr><td>output_scheme</td><td>OT_STRINGVECTOR</td><td>Custom output scheme</td><td>casadi::FunctionInternal</td></tr>
<tr><td>parallelization</td><td>OT_STRING</td><td>Computational strategy for parallelization</td><td>casadi::MapReduce</td></tr>
<tr><td>reduced_inputs</td><td>OT_INTVECTOR</td><td>Reduction for certain inputs</td><td>casadi::MapReduce</td></tr>
<tr><td>reduced_outputs</td><td>OT_INTVECTOR</td><td>Reduction for certain outputs</td><td>casadi::MapReduce</td></tr>
<tr><td>regularity_check</td><td>OT_BOOL</td><td>Throw exceptions when NaN or Inf appears during evaluation</td><td>casadi::FunctionInternal</td></tr>
<tr><td>user_data</td><td>OT_VOIDPTR</td><td>A user-defined field that can be used to identify the function or pass additional information</td><td>casadi::FunctionInternal</td></tr>
<tr><td>verbose</td><td>OT_BOOL</td><td>Verbose evaluation -- for debugging</td><td>casadi::FunctionInternal</td></tr>
</table>
*/
/// \endcond
/// \cond INTERNAL
/** \class casadi::MapSerial
\n
\par
<a name='options'></a><table>
<caption>List of available options</caption>
<tr><th>Id</th><th>Type</th><th>Description</th><th>Used in</th></tr>
<tr><td>ad_weight</td><td>OT_DOUBLE</td><td>Weighting factor for derivative calculation.When there is an option of either using forward or reverse mode directional derivatives, the condition ad_weight*nf&lt;=(1-ad_weight)*na is used where nf and na are estimates of the number of forward/reverse mode directional derivatives needed. By default, ad_weight is calculated automatically, but this can be overridden by setting this option. In particular, 0 means forcing forward mode and 1 forcing reverse mode. Leave unset for (class specific) heuristics.</td><td>casadi::FunctionInternal</td></tr>
<tr><td>ad_weight_sp</td><td>OT_DOUBLE</td><td>Weighting factor for sparsity pattern calculation calculation.Overrides default behavior. Set to 0 and 1 to force forward and reverse mode respectively. Cf. option \"ad_weight\".</td><td>casadi::FunctionInternal</td></tr>
<tr><td>compiler</td><td>OT_STRING</td><td>Just-in-time compiler plugin to be used.</td><td>casadi::FunctionInternal</td></tr>
<tr><td>gather_stats</td><td>OT_BOOL</td><td>Flag to indicate whether statistics must be gathered</td><td>casadi::FunctionInternal</td></tr>
<tr><td>input_scheme</td><td>OT_STRINGVECTOR</td><td>Custom input scheme</td><td>casadi::FunctionInternal</td></tr>
<tr><td>inputs_check</td><td>OT_BOOL</td><td>Throw exceptions when the numerical values of the inputs don't make sense</td><td>casadi::FunctionInternal</td></tr>
<tr><td>jac_penalty</td><td>OT_DOUBLE</td><td>When requested for a number of forward/reverse directions,   it may be cheaper to compute first the full jacobian and then multiply with seeds, rather than obtain the requested directions in a straightforward manner. Casadi uses a heuristic to decide which is cheaper. A high value of 'jac_penalty' makes it less likely for the heurstic to chose the full Jacobian strategy. The special value -1 indicates never to use the full Jacobian strategy</td><td>casadi::FunctionInternal</td></tr>
<tr><td>jit</td><td>OT_BOOL</td><td>Use just-in-time compiler to speed up the evaluation</td><td>casadi::FunctionInternal</td></tr>
<tr><td>jit_options</td><td>OT_DICT</td><td>Options to be passed to the jit compiler.</td><td>casadi::FunctionInternal</td></tr>
<tr><td>monitor</td><td>OT_STRINGVECTOR</td><td>Monitors to be activated</td><td>casadi::FunctionInternal</td></tr>
<tr><td>output_scheme</td><td>OT_STRINGVECTOR</td><td>Custom output scheme</td><td>casadi::FunctionInternal</td></tr>
<tr><td>parallelization</td><td>OT_STRING</td><td>Computational strategy for parallelization</td><td>casadi::MapSerial</td></tr>
<tr><td>reduced_inputs</td><td>OT_INTVECTOR</td><td>Reduction for certain inputs</td><td>casadi::MapSerial</td></tr>
<tr><td>reduced_outputs</td><td>OT_INTVECTOR</td><td>Reduction for certain outputs</td><td>casadi::MapSerial</td></tr>
<tr><td>regularity_check</td><td>OT_BOOL</td><td>Throw exceptions when NaN or Inf appears during evaluation</td><td>casadi::FunctionInternal</td></tr>
<tr><td>user_data</td><td>OT_VOIDPTR</td><td>A user-defined field that can be used to identify the function or pass additional information</td><td>casadi::FunctionInternal</td></tr>
<tr><td>verbose</td><td>OT_BOOL</td><td>Verbose evaluation -- for debugging</td><td>casadi::FunctionInternal</td></tr>
</table>
*/
/// \endcond
/// \cond INTERNAL
/** \class casadi::Newton
\n
\par
<a name='options'></a><table>
<caption>List of available options</caption>
<tr><th>Id</th><th>Type</th><th>Description</th><th>Used in</th></tr>
<tr><td>abstol</td><td>OT_DOUBLE</td><td>Stopping criterion tolerance on max(|F|)</td><td>casadi::Newton</td></tr>
<tr><td>abstolStep</td><td>OT_DOUBLE</td><td>Stopping criterion tolerance on step size</td><td>casadi::Newton</td></tr>
<tr><td>constraints</td><td>OT_INTVECTOR</td><td>Constrain the unknowns. 0 (default): no constraint on ui, 1: ui &gt;= 0.0, -1: ui &lt;= 0.0, 2: ui &gt; 0.0, -2: ui &lt; 0.0.</td><td>casadi::Rootfinder</td></tr>
<tr><td>implicit_input</td><td>OT_INT</td><td>Index of the input that corresponds to the actual root-finding</td><td>casadi::Rootfinder</td></tr>
<tr><td>implicit_output</td><td>OT_INT</td><td>Index of the output that corresponds to the actual root-finding</td><td>casadi::Rootfinder</td></tr>
<tr><td>jacobian_function</td><td>OT_FUNCTION</td><td>Function object for calculating the Jacobian (autogenerated by default)</td><td>casadi::Rootfinder</td></tr>
<tr><td>linear_solver</td><td>OT_STRING</td><td>User-defined linear solver class. Needed for sensitivities.</td><td>casadi::Rootfinder</td></tr>
<tr><td>linear_solver_options</td><td>OT_DICT</td><td>Options to be passed to the linear solver.</td><td>casadi::Rootfinder</td></tr>
<tr><td>max_iter</td><td>OT_INT</td><td>Maximum number of Newton iterations to perform before returning.</td><td>casadi::Newton</td></tr>
<tr><td>print_iteration</td><td>OT_BOOL</td><td>Print information about each iteration</td><td>casadi::Newton</td></tr>
</table>
*/
/// \endcond
/** \addtogroup plugin_Rootfinder_newton
\n
\par
<a name='options'></a><table>
<caption>List of available options</caption>
<tr><th>Id</th><th>Type</th><th>Description</th></tr>
<tr><td>abstol</td><td>OT_DOUBLE</td><td>Stopping criterion tolerance on max(|F|)</td></tr>
<tr><td>abstolStep</td><td>OT_DOUBLE</td><td>Stopping criterion tolerance on step size</td></tr>
<tr><td>max_iter</td><td>OT_INT</td><td>Maximum number of Newton iterations to perform before returning.</td></tr>
<tr><td>print_iteration</td><td>OT_BOOL</td><td>Print information about each iteration</td></tr>
</table>
*/
/** \addtogroup general_Newton
\n
\par
<a name='options'></a><table>
<caption>List of available options</caption>
<tr><th>Id</th><th>Type</th><th>Description</th><th>Used in</th></tr>
<tr><td>abstol</td><td>OT_DOUBLE</td><td>Stopping criterion tolerance on max(|F|)</td><td>casadi::Newton</td></tr>
<tr><td>abstolStep</td><td>OT_DOUBLE</td><td>Stopping criterion tolerance on step size</td><td>casadi::Newton</td></tr>
<tr><td>constraints</td><td>OT_INTVECTOR</td><td>Constrain the unknowns. 0 (default): no constraint on ui, 1: ui &gt;= 0.0, -1: ui &lt;= 0.0, 2: ui &gt; 0.0, -2: ui &lt; 0.0.</td><td>casadi::Rootfinder</td></tr>
<tr><td>implicit_input</td><td>OT_INT</td><td>Index of the input that corresponds to the actual root-finding</td><td>casadi::Rootfinder</td></tr>
<tr><td>implicit_output</td><td>OT_INT</td><td>Index of the output that corresponds to the actual root-finding</td><td>casadi::Rootfinder</td></tr>
<tr><td>jacobian_function</td><td>OT_FUNCTION</td><td>Function object for calculating the Jacobian (autogenerated by default)</td><td>casadi::Rootfinder</td></tr>
<tr><td>linear_solver</td><td>OT_STRING</td><td>User-defined linear solver class. Needed for sensitivities.</td><td>casadi::Rootfinder</td></tr>
<tr><td>linear_solver_options</td><td>OT_DICT</td><td>Options to be passed to the linear solver.</td><td>casadi::Rootfinder</td></tr>
<tr><td>max_iter</td><td>OT_INT</td><td>Maximum number of Newton iterations to perform before returning.</td><td>casadi::Newton</td></tr>
<tr><td>print_iteration</td><td>OT_BOOL</td><td>Print information about each iteration</td><td>casadi::Newton</td></tr>
</table>
*/
/// \cond INTERNAL
/** \class casadi::Nlpsol
\n
\par
<a name='options'></a><table>
<caption>List of available options</caption>
<tr><th>Id</th><th>Type</th><th>Description</th><th>Used in</th></tr>
<tr><td>ad_weight</td><td>OT_DOUBLE</td><td>Weighting factor for derivative calculation.When there is an option of either using forward or reverse mode directional derivatives, the condition ad_weight*nf&lt;=(1-ad_weight)*na is used where nf and na are estimates of the number of forward/reverse mode directional derivatives needed. By default, ad_weight is calculated automatically, but this can be overridden by setting this option. In particular, 0 means forcing forward mode and 1 forcing reverse mode. Leave unset for (class specific) heuristics.</td><td>casadi::FunctionInternal</td></tr>
<tr><td>ad_weight_sp</td><td>OT_DOUBLE</td><td>Weighting factor for sparsity pattern calculation calculation.Overrides default behavior. Set to 0 and 1 to force forward and reverse mode respectively. Cf. option \"ad_weight\".</td><td>casadi::FunctionInternal</td></tr>
<tr><td>compiler</td><td>OT_STRING</td><td>Just-in-time compiler plugin to be used.</td><td>casadi::FunctionInternal</td></tr>
<tr><td>eval_errors_fatal</td><td>OT_BOOL</td><td>When errors occur during evaluation of f,g,...,stop the iterations</td><td>casadi::Nlpsol</td></tr>
<tr><td>expand</td><td>OT_BOOL</td><td>Replace MX with SX expressions in problem formulation [false]</td><td>casadi::Nlpsol</td></tr>
<tr><td>gather_stats</td><td>OT_BOOL</td><td>Flag to indicate whether statistics must be gathered</td><td>casadi::FunctionInternal</td></tr>
<tr><td>ignore_check_vec</td><td>OT_BOOL</td><td>If set to true, the input shape of F will not be checked.</td><td>casadi::Nlpsol</td></tr>
<tr><td>input_scheme</td><td>OT_STRINGVECTOR</td><td>Custom input scheme</td><td>casadi::FunctionInternal</td></tr>
<tr><td>inputs_check</td><td>OT_BOOL</td><td>Throw exceptions when the numerical values of the inputs don't make sense</td><td>casadi::FunctionInternal</td></tr>
<tr><td>iteration_callback</td><td>OT_FUNCTION</td><td>A function that will be called at each iteration with the solver as input. Check documentation of Callback.</td><td>casadi::Nlpsol</td></tr>
<tr><td>iteration_callback_ignore_errors</td><td>OT_BOOL</td><td>If set to true, errors thrown by iteration_callback will be ignored.</td><td>casadi::Nlpsol</td></tr>
<tr><td>iteration_callback_step</td><td>OT_INT</td><td>Only call the callback function every few iterations.</td><td>casadi::Nlpsol</td></tr>
<tr><td>jac_penalty</td><td>OT_DOUBLE</td><td>When requested for a number of forward/reverse directions,   it may be cheaper to compute first the full jacobian and then multiply with seeds, rather than obtain the requested directions in a straightforward manner. Casadi uses a heuristic to decide which is cheaper. A high value of 'jac_penalty' makes it less likely for the heurstic to chose the full Jacobian strategy. The special value -1 indicates never to use the full Jacobian strategy</td><td>casadi::FunctionInternal</td></tr>
<tr><td>jit</td><td>OT_BOOL</td><td>Use just-in-time compiler to speed up the evaluation</td><td>casadi::FunctionInternal</td></tr>
<tr><td>jit_options</td><td>OT_DICT</td><td>Options to be passed to the jit compiler.</td><td>casadi::FunctionInternal</td></tr>
<tr><td>monitor</td><td>OT_STRINGVECTOR</td><td>Monitors to be activated</td><td>casadi::FunctionInternal</td></tr>
<tr><td>output_scheme</td><td>OT_STRINGVECTOR</td><td>Custom output scheme</td><td>casadi::FunctionInternal</td></tr>
<tr><td>regularity_check</td><td>OT_BOOL</td><td>Throw exceptions when NaN or Inf appears during evaluation</td><td>casadi::FunctionInternal</td></tr>
<tr><td>user_data</td><td>OT_VOIDPTR</td><td>A user-defined field that can be used to identify the function or pass additional information</td><td>casadi::FunctionInternal</td></tr>
<tr><td>verbose</td><td>OT_BOOL</td><td>Verbose evaluation -- for debugging</td><td>casadi::FunctionInternal</td></tr>
<tr><td>verbose_init</td><td>OT_BOOL</td><td>Print out timing information about the different stages of initialization</td><td>casadi::Nlpsol</td></tr>
<tr><td>warn_initial_bounds</td><td>OT_BOOL</td><td>Warn if the initial guess does not satisfy LBX and UBX</td><td>casadi::Nlpsol</td></tr>
</table>
*/
/// \endcond
/** \addtogroup general_Nlpsol
\n
\par
<a name='options'></a><table>
<caption>List of available options</caption>
<tr><th>Id</th><th>Type</th><th>Description</th><th>Used in</th></tr>
<tr><td>ad_weight</td><td>OT_DOUBLE</td><td>Weighting factor for derivative calculation.When there is an option of either using forward or reverse mode directional derivatives, the condition ad_weight*nf&lt;=(1-ad_weight)*na is used where nf and na are estimates of the number of forward/reverse mode directional derivatives needed. By default, ad_weight is calculated automatically, but this can be overridden by setting this option. In particular, 0 means forcing forward mode and 1 forcing reverse mode. Leave unset for (class specific) heuristics.</td><td>casadi::FunctionInternal</td></tr>
<tr><td>ad_weight_sp</td><td>OT_DOUBLE</td><td>Weighting factor for sparsity pattern calculation calculation.Overrides default behavior. Set to 0 and 1 to force forward and reverse mode respectively. Cf. option \"ad_weight\".</td><td>casadi::FunctionInternal</td></tr>
<tr><td>compiler</td><td>OT_STRING</td><td>Just-in-time compiler plugin to be used.</td><td>casadi::FunctionInternal</td></tr>
<tr><td>eval_errors_fatal</td><td>OT_BOOL</td><td>When errors occur during evaluation of f,g,...,stop the iterations</td><td>casadi::Nlpsol</td></tr>
<tr><td>expand</td><td>OT_BOOL</td><td>Replace MX with SX expressions in problem formulation [false]</td><td>casadi::Nlpsol</td></tr>
<tr><td>gather_stats</td><td>OT_BOOL</td><td>Flag to indicate whether statistics must be gathered</td><td>casadi::FunctionInternal</td></tr>
<tr><td>ignore_check_vec</td><td>OT_BOOL</td><td>If set to true, the input shape of F will not be checked.</td><td>casadi::Nlpsol</td></tr>
<tr><td>input_scheme</td><td>OT_STRINGVECTOR</td><td>Custom input scheme</td><td>casadi::FunctionInternal</td></tr>
<tr><td>inputs_check</td><td>OT_BOOL</td><td>Throw exceptions when the numerical values of the inputs don't make sense</td><td>casadi::FunctionInternal</td></tr>
<tr><td>iteration_callback</td><td>OT_FUNCTION</td><td>A function that will be called at each iteration with the solver as input. Check documentation of Callback.</td><td>casadi::Nlpsol</td></tr>
<tr><td>iteration_callback_ignore_errors</td><td>OT_BOOL</td><td>If set to true, errors thrown by iteration_callback will be ignored.</td><td>casadi::Nlpsol</td></tr>
<tr><td>iteration_callback_step</td><td>OT_INT</td><td>Only call the callback function every few iterations.</td><td>casadi::Nlpsol</td></tr>
<tr><td>jac_penalty</td><td>OT_DOUBLE</td><td>When requested for a number of forward/reverse directions,   it may be cheaper to compute first the full jacobian and then multiply with seeds, rather than obtain the requested directions in a straightforward manner. Casadi uses a heuristic to decide which is cheaper. A high value of 'jac_penalty' makes it less likely for the heurstic to chose the full Jacobian strategy. The special value -1 indicates never to use the full Jacobian strategy</td><td>casadi::FunctionInternal</td></tr>
<tr><td>jit</td><td>OT_BOOL</td><td>Use just-in-time compiler to speed up the evaluation</td><td>casadi::FunctionInternal</td></tr>
<tr><td>jit_options</td><td>OT_DICT</td><td>Options to be passed to the jit compiler.</td><td>casadi::FunctionInternal</td></tr>
<tr><td>monitor</td><td>OT_STRINGVECTOR</td><td>Monitors to be activated</td><td>casadi::FunctionInternal</td></tr>
<tr><td>output_scheme</td><td>OT_STRINGVECTOR</td><td>Custom output scheme</td><td>casadi::FunctionInternal</td></tr>
<tr><td>regularity_check</td><td>OT_BOOL</td><td>Throw exceptions when NaN or Inf appears during evaluation</td><td>casadi::FunctionInternal</td></tr>
<tr><td>user_data</td><td>OT_VOIDPTR</td><td>A user-defined field that can be used to identify the function or pass additional information</td><td>casadi::FunctionInternal</td></tr>
<tr><td>verbose</td><td>OT_BOOL</td><td>Verbose evaluation -- for debugging</td><td>casadi::FunctionInternal</td></tr>
<tr><td>verbose_init</td><td>OT_BOOL</td><td>Print out timing information about the different stages of initialization</td><td>casadi::Nlpsol</td></tr>
<tr><td>warn_initial_bounds</td><td>OT_BOOL</td><td>Warn if the initial guess does not satisfy LBX and UBX</td><td>casadi::Nlpsol</td></tr>
</table>
*/
/// \cond INTERNAL
/** \class casadi::OoqpInterface
\n
\par
<a name='options'></a><table>
<caption>List of available options</caption>
<tr><th>Id</th><th>Type</th><th>Description</th><th>Used in</th></tr>
<tr><td>artol</td><td>OT_DOUBLE</td><td>tolerance as provided with setArTol to OOQP</td><td>casadi::OoqpInterface</td></tr>
<tr><td>discrete</td><td>OT_BOOLVECTOR</td><td>Indicates which of the variables are discrete, i.e. integer-valued</td><td>casadi::Qpsol</td></tr>
<tr><td>mutol</td><td>OT_DOUBLE</td><td>tolerance as provided with setMuTol to OOQP</td><td>casadi::OoqpInterface</td></tr>
<tr><td>print_level</td><td>OT_INT</td><td>Print level. OOQP listens to print_level 0, 10 and 100</td><td>casadi::OoqpInterface</td></tr>
</table>
*/
/// \endcond
/** \addtogroup plugin_Qpsol_ooqp
\n
\par
<a name='options'></a><table>
<caption>List of available options</caption>
<tr><th>Id</th><th>Type</th><th>Description</th></tr>
<tr><td>artol</td><td>OT_DOUBLE</td><td>tolerance as provided with setArTol to OOQP</td></tr>
<tr><td>mutol</td><td>OT_DOUBLE</td><td>tolerance as provided with setMuTol to OOQP</td></tr>
<tr><td>print_level</td><td>OT_INT</td><td>Print level. OOQP listens to print_level 0, 10 and 100</td></tr>
</table>
*/
/** \addtogroup general_OoqpInterface
\n
\par
<a name='options'></a><table>
<caption>List of available options</caption>
<tr><th>Id</th><th>Type</th><th>Description</th><th>Used in</th></tr>
<tr><td>artol</td><td>OT_DOUBLE</td><td>tolerance as provided with setArTol to OOQP</td><td>casadi::OoqpInterface</td></tr>
<tr><td>discrete</td><td>OT_BOOLVECTOR</td><td>Indicates which of the variables are discrete, i.e. integer-valued</td><td>casadi::Qpsol</td></tr>
<tr><td>mutol</td><td>OT_DOUBLE</td><td>tolerance as provided with setMuTol to OOQP</td><td>casadi::OoqpInterface</td></tr>
<tr><td>print_level</td><td>OT_INT</td><td>Print level. OOQP listens to print_level 0, 10 and 100</td><td>casadi::OoqpInterface</td></tr>
</table>
*/
/// \cond INTERNAL
/** \class casadi::QpToNlp
\n
\par
<a name='options'></a><table>
<caption>List of available options</caption>
<tr><th>Id</th><th>Type</th><th>Description</th><th>Used in</th></tr>
<tr><td>discrete</td><td>OT_BOOLVECTOR</td><td>Indicates which of the variables are discrete, i.e. integer-valued</td><td>casadi::Qpsol</td></tr>
<tr><td>nlpsol</td><td>OT_STRING</td><td>Name of solver.</td><td>casadi::QpToNlp</td></tr>
<tr><td>nlpsol_options</td><td>OT_DICT</td><td>Options to be passed to solver.</td><td>casadi::QpToNlp</td></tr>
</table>
*/
/// \endcond
/** \addtogroup plugin_Qpsol_nlp
\n
\par
<a name='options'></a><table>
<caption>List of available options</caption>
<tr><th>Id</th><th>Type</th><th>Description</th></tr>
<tr><td>nlpsol</td><td>OT_STRING</td><td>Name of solver.</td></tr>
<tr><td>nlpsol_options</td><td>OT_DICT</td><td>Options to be passed to solver.</td></tr>
</table>
*/
/** \addtogroup general_QpToNlp
\n
\par
<a name='options'></a><table>
<caption>List of available options</caption>
<tr><th>Id</th><th>Type</th><th>Description</th><th>Used in</th></tr>
<tr><td>discrete</td><td>OT_BOOLVECTOR</td><td>Indicates which of the variables are discrete, i.e. integer-valued</td><td>casadi::Qpsol</td></tr>
<tr><td>nlpsol</td><td>OT_STRING</td><td>Name of solver.</td><td>casadi::QpToNlp</td></tr>
<tr><td>nlpsol_options</td><td>OT_DICT</td><td>Options to be passed to solver.</td><td>casadi::QpToNlp</td></tr>
</table>
*/
/// \cond INTERNAL
/** \class casadi::QpoasesInterface
\n
\par
<a name='options'></a><table>
<caption>List of available options</caption>
<tr><th>Id</th><th>Type</th><th>Description</th><th>Used in</th></tr>
<tr><td>CPUtime</td><td>OT_DOUBLE</td><td>The maximum allowed CPU time in seconds for the whole initialisation (and the actually required one on output). Disabled if unset.</td><td>casadi::QpoasesInterface</td></tr>
<tr><td>boundRelaxation</td><td>OT_DOUBLE</td><td>Initial relaxation of bounds to start homotopy  and initial value for far bounds.</td><td>casadi::QpoasesInterface</td></tr>
<tr><td>boundTolerance</td><td>OT_DOUBLE</td><td>If upper and lower bounds differ less than this tolerance, they are regarded equal, i.e. as  equality constraint.</td><td>casadi::QpoasesInterface</td></tr>
<tr><td>discrete</td><td>OT_BOOLVECTOR</td><td>Indicates which of the variables are discrete, i.e. integer-valued</td><td>casadi::Qpsol</td></tr>
<tr><td>enableCholeskyRefactorisation</td><td>OT_INT</td><td>Specifies the frequency of a full re-factorisation of projected Hessian matrix: 0: turns them off,  1: uses them at each iteration etc.</td><td>casadi::QpoasesInterface</td></tr>
<tr><td>enableDriftCorrection</td><td>OT_INT</td><td>Specifies the frequency of drift corrections: 0: turns them off.</td><td>casadi::QpoasesInterface</td></tr>
<tr><td>enableEqualities</td><td>OT_BOOL</td><td>Specifies whether equalities should be treated  as always active (True) or not (False)</td><td>casadi::QpoasesInterface</td></tr>
<tr><td>enableFarBounds</td><td>OT_BOOL</td><td>Enables the use of  far bounds.</td><td>casadi::QpoasesInterface</td></tr>
<tr><td>enableFlippingBounds</td><td>OT_BOOL</td><td>Enables the use of  flipping bounds.</td><td>casadi::QpoasesInterface</td></tr>
<tr><td>enableFullLITests</td><td>OT_BOOL</td><td>Enables condition-hardened  (but more expensive) LI test.</td><td>casadi::QpoasesInterface</td></tr>
<tr><td>enableNZCTests</td><td>OT_BOOL</td><td>Enables nonzero curvature  tests.</td><td>casadi::QpoasesInterface</td></tr>
<tr><td>enableRamping</td><td>OT_BOOL</td><td>Enables ramping.</td><td>casadi::QpoasesInterface</td></tr>
<tr><td>enableRegularisation</td><td>OT_BOOL</td><td>Enables automatic  Hessian regularisation.</td><td>casadi::QpoasesInterface</td></tr>
<tr><td>epsDen</td><td>OT_DOUBLE</td><td>Denominator tolerance for ratio tests.</td><td>casadi::QpoasesInterface</td></tr>
<tr><td>epsFlipping</td><td>OT_DOUBLE</td><td>Tolerance of squared Cholesky diagonal factor  which triggers flipping bound.</td><td>casadi::QpoasesInterface</td></tr>
<tr><td>epsIterRef</td><td>OT_DOUBLE</td><td>Early termination tolerance for iterative  refinement.</td><td>casadi::QpoasesInterface</td></tr>
<tr><td>epsLITests</td><td>OT_DOUBLE</td><td>Tolerance for linear independence tests.</td><td>casadi::QpoasesInterface</td></tr>
<tr><td>epsNZCTests</td><td>OT_DOUBLE</td><td>Tolerance for nonzero curvature tests.</td><td>casadi::QpoasesInterface</td></tr>
<tr><td>epsNum</td><td>OT_DOUBLE</td><td>Numerator tolerance for ratio tests.</td><td>casadi::QpoasesInterface</td></tr>
<tr><td>epsRegularisation</td><td>OT_DOUBLE</td><td>Scaling factor of identity matrix used for  Hessian regularisation.</td><td>casadi::QpoasesInterface</td></tr>
<tr><td>finalRamping</td><td>OT_DOUBLE</td><td>Final value for ramping strategy.</td><td>casadi::QpoasesInterface</td></tr>
<tr><td>growFarBounds</td><td>OT_DOUBLE</td><td>Factor to grow far bounds.</td><td>casadi::QpoasesInterface</td></tr>
<tr><td>initialFarBounds</td><td>OT_DOUBLE</td><td>Initial size for far bounds.</td><td>casadi::QpoasesInterface</td></tr>
<tr><td>initialRamping</td><td>OT_DOUBLE</td><td>Start value for ramping strategy.</td><td>casadi::QpoasesInterface</td></tr>
<tr><td>initialStatusBounds</td><td>OT_STRING</td><td>Initial status of bounds at first iteration.</td><td>casadi::QpoasesInterface</td></tr>
<tr><td>maxDualJump</td><td>OT_DOUBLE</td><td>Maximum allowed jump in dual variables in  linear independence tests.</td><td>casadi::QpoasesInterface</td></tr>
<tr><td>maxPrimalJump</td><td>OT_DOUBLE</td><td>Maximum allowed jump in primal variables in  nonzero curvature tests.</td><td>casadi::QpoasesInterface</td></tr>
<tr><td>nWSR</td><td>OT_INT</td><td>The maximum number of working set recalculations to be performed during the initial homotopy. Default is 5(nx + nc)</td><td>casadi::QpoasesInterface</td></tr>
<tr><td>numRefinementSteps</td><td>OT_INT</td><td>Maximum number of iterative refinement steps.</td><td>casadi::QpoasesInterface</td></tr>
<tr><td>numRegularisationSteps</td><td>OT_INT</td><td>Maximum number of successive regularisation steps.</td><td>casadi::QpoasesInterface</td></tr>
<tr><td>printLevel</td><td>OT_STRING</td><td>Defines the amount of text output during QP solution, see Section 5.7</td><td>casadi::QpoasesInterface</td></tr>
<tr><td>sparse</td><td>OT_BOOL</td><td>Formulate the QP using sparse matrices. Default: false</td><td>casadi::QpoasesInterface</td></tr>
<tr><td>terminationTolerance</td><td>OT_DOUBLE</td><td>Relative termination tolerance to stop homotopy.</td><td>casadi::QpoasesInterface</td></tr>
</table>
*/
/// \endcond
/** \addtogroup plugin_Qpsol_qpoases
\n
\par
<a name='options'></a><table>
<caption>List of available options</caption>
<tr><th>Id</th><th>Type</th><th>Description</th></tr>
<tr><td>CPUtime</td><td>OT_DOUBLE</td><td>The maximum allowed CPU time in seconds for the whole initialisation (and the actually required one on output). Disabled if unset.</td></tr>
<tr><td>boundRelaxation</td><td>OT_DOUBLE</td><td>Initial relaxation of bounds to start homotopy  and initial value for far bounds.</td></tr>
<tr><td>boundTolerance</td><td>OT_DOUBLE</td><td>If upper and lower bounds differ less than this tolerance, they are regarded equal, i.e. as  equality constraint.</td></tr>
<tr><td>enableCholeskyRefactorisation</td><td>OT_INT</td><td>Specifies the frequency of a full re-factorisation of projected Hessian matrix: 0: turns them off,  1: uses them at each iteration etc.</td></tr>
<tr><td>enableDriftCorrection</td><td>OT_INT</td><td>Specifies the frequency of drift corrections: 0: turns them off.</td></tr>
<tr><td>enableEqualities</td><td>OT_BOOL</td><td>Specifies whether equalities should be treated  as always active (True) or not (False)</td></tr>
<tr><td>enableFarBounds</td><td>OT_BOOL</td><td>Enables the use of  far bounds.</td></tr>
<tr><td>enableFlippingBounds</td><td>OT_BOOL</td><td>Enables the use of  flipping bounds.</td></tr>
<tr><td>enableFullLITests</td><td>OT_BOOL</td><td>Enables condition-hardened  (but more expensive) LI test.</td></tr>
<tr><td>enableNZCTests</td><td>OT_BOOL</td><td>Enables nonzero curvature  tests.</td></tr>
<tr><td>enableRamping</td><td>OT_BOOL</td><td>Enables ramping.</td></tr>
<tr><td>enableRegularisation</td><td>OT_BOOL</td><td>Enables automatic  Hessian regularisation.</td></tr>
<tr><td>epsDen</td><td>OT_DOUBLE</td><td>Denominator tolerance for ratio tests.</td></tr>
<tr><td>epsFlipping</td><td>OT_DOUBLE</td><td>Tolerance of squared Cholesky diagonal factor  which triggers flipping bound.</td></tr>
<tr><td>epsIterRef</td><td>OT_DOUBLE</td><td>Early termination tolerance for iterative  refinement.</td></tr>
<tr><td>epsLITests</td><td>OT_DOUBLE</td><td>Tolerance for linear independence tests.</td></tr>
<tr><td>epsNZCTests</td><td>OT_DOUBLE</td><td>Tolerance for nonzero curvature tests.</td></tr>
<tr><td>epsNum</td><td>OT_DOUBLE</td><td>Numerator tolerance for ratio tests.</td></tr>
<tr><td>epsRegularisation</td><td>OT_DOUBLE</td><td>Scaling factor of identity matrix used for  Hessian regularisation.</td></tr>
<tr><td>finalRamping</td><td>OT_DOUBLE</td><td>Final value for ramping strategy.</td></tr>
<tr><td>growFarBounds</td><td>OT_DOUBLE</td><td>Factor to grow far bounds.</td></tr>
<tr><td>initialFarBounds</td><td>OT_DOUBLE</td><td>Initial size for far bounds.</td></tr>
<tr><td>initialRamping</td><td>OT_DOUBLE</td><td>Start value for ramping strategy.</td></tr>
<tr><td>initialStatusBounds</td><td>OT_STRING</td><td>Initial status of bounds at first iteration.</td></tr>
<tr><td>maxDualJump</td><td>OT_DOUBLE</td><td>Maximum allowed jump in dual variables in  linear independence tests.</td></tr>
<tr><td>maxPrimalJump</td><td>OT_DOUBLE</td><td>Maximum allowed jump in primal variables in  nonzero curvature tests.</td></tr>
<tr><td>nWSR</td><td>OT_INT</td><td>The maximum number of working set recalculations to be performed during the initial homotopy. Default is 5(nx + nc)</td></tr>
<tr><td>numRefinementSteps</td><td>OT_INT</td><td>Maximum number of iterative refinement steps.</td></tr>
<tr><td>numRegularisationSteps</td><td>OT_INT</td><td>Maximum number of successive regularisation steps.</td></tr>
<tr><td>printLevel</td><td>OT_STRING</td><td>Defines the amount of text output during QP solution, see Section 5.7</td></tr>
<tr><td>sparse</td><td>OT_BOOL</td><td>Formulate the QP using sparse matrices. Default: false</td></tr>
<tr><td>terminationTolerance</td><td>OT_DOUBLE</td><td>Relative termination tolerance to stop homotopy.</td></tr>
</table>
*/
/** \addtogroup general_QpoasesInterface
\n
\par
<a name='options'></a><table>
<caption>List of available options</caption>
<tr><th>Id</th><th>Type</th><th>Description</th><th>Used in</th></tr>
<tr><td>CPUtime</td><td>OT_DOUBLE</td><td>The maximum allowed CPU time in seconds for the whole initialisation (and the actually required one on output). Disabled if unset.</td><td>casadi::QpoasesInterface</td></tr>
<tr><td>boundRelaxation</td><td>OT_DOUBLE</td><td>Initial relaxation of bounds to start homotopy  and initial value for far bounds.</td><td>casadi::QpoasesInterface</td></tr>
<tr><td>boundTolerance</td><td>OT_DOUBLE</td><td>If upper and lower bounds differ less than this tolerance, they are regarded equal, i.e. as  equality constraint.</td><td>casadi::QpoasesInterface</td></tr>
<tr><td>discrete</td><td>OT_BOOLVECTOR</td><td>Indicates which of the variables are discrete, i.e. integer-valued</td><td>casadi::Qpsol</td></tr>
<tr><td>enableCholeskyRefactorisation</td><td>OT_INT</td><td>Specifies the frequency of a full re-factorisation of projected Hessian matrix: 0: turns them off,  1: uses them at each iteration etc.</td><td>casadi::QpoasesInterface</td></tr>
<tr><td>enableDriftCorrection</td><td>OT_INT</td><td>Specifies the frequency of drift corrections: 0: turns them off.</td><td>casadi::QpoasesInterface</td></tr>
<tr><td>enableEqualities</td><td>OT_BOOL</td><td>Specifies whether equalities should be treated  as always active (True) or not (False)</td><td>casadi::QpoasesInterface</td></tr>
<tr><td>enableFarBounds</td><td>OT_BOOL</td><td>Enables the use of  far bounds.</td><td>casadi::QpoasesInterface</td></tr>
<tr><td>enableFlippingBounds</td><td>OT_BOOL</td><td>Enables the use of  flipping bounds.</td><td>casadi::QpoasesInterface</td></tr>
<tr><td>enableFullLITests</td><td>OT_BOOL</td><td>Enables condition-hardened  (but more expensive) LI test.</td><td>casadi::QpoasesInterface</td></tr>
<tr><td>enableNZCTests</td><td>OT_BOOL</td><td>Enables nonzero curvature  tests.</td><td>casadi::QpoasesInterface</td></tr>
<tr><td>enableRamping</td><td>OT_BOOL</td><td>Enables ramping.</td><td>casadi::QpoasesInterface</td></tr>
<tr><td>enableRegularisation</td><td>OT_BOOL</td><td>Enables automatic  Hessian regularisation.</td><td>casadi::QpoasesInterface</td></tr>
<tr><td>epsDen</td><td>OT_DOUBLE</td><td>Denominator tolerance for ratio tests.</td><td>casadi::QpoasesInterface</td></tr>
<tr><td>epsFlipping</td><td>OT_DOUBLE</td><td>Tolerance of squared Cholesky diagonal factor  which triggers flipping bound.</td><td>casadi::QpoasesInterface</td></tr>
<tr><td>epsIterRef</td><td>OT_DOUBLE</td><td>Early termination tolerance for iterative  refinement.</td><td>casadi::QpoasesInterface</td></tr>
<tr><td>epsLITests</td><td>OT_DOUBLE</td><td>Tolerance for linear independence tests.</td><td>casadi::QpoasesInterface</td></tr>
<tr><td>epsNZCTests</td><td>OT_DOUBLE</td><td>Tolerance for nonzero curvature tests.</td><td>casadi::QpoasesInterface</td></tr>
<tr><td>epsNum</td><td>OT_DOUBLE</td><td>Numerator tolerance for ratio tests.</td><td>casadi::QpoasesInterface</td></tr>
<tr><td>epsRegularisation</td><td>OT_DOUBLE</td><td>Scaling factor of identity matrix used for  Hessian regularisation.</td><td>casadi::QpoasesInterface</td></tr>
<tr><td>finalRamping</td><td>OT_DOUBLE</td><td>Final value for ramping strategy.</td><td>casadi::QpoasesInterface</td></tr>
<tr><td>growFarBounds</td><td>OT_DOUBLE</td><td>Factor to grow far bounds.</td><td>casadi::QpoasesInterface</td></tr>
<tr><td>initialFarBounds</td><td>OT_DOUBLE</td><td>Initial size for far bounds.</td><td>casadi::QpoasesInterface</td></tr>
<tr><td>initialRamping</td><td>OT_DOUBLE</td><td>Start value for ramping strategy.</td><td>casadi::QpoasesInterface</td></tr>
<tr><td>initialStatusBounds</td><td>OT_STRING</td><td>Initial status of bounds at first iteration.</td><td>casadi::QpoasesInterface</td></tr>
<tr><td>maxDualJump</td><td>OT_DOUBLE</td><td>Maximum allowed jump in dual variables in  linear independence tests.</td><td>casadi::QpoasesInterface</td></tr>
<tr><td>maxPrimalJump</td><td>OT_DOUBLE</td><td>Maximum allowed jump in primal variables in  nonzero curvature tests.</td><td>casadi::QpoasesInterface</td></tr>
<tr><td>nWSR</td><td>OT_INT</td><td>The maximum number of working set recalculations to be performed during the initial homotopy. Default is 5(nx + nc)</td><td>casadi::QpoasesInterface</td></tr>
<tr><td>numRefinementSteps</td><td>OT_INT</td><td>Maximum number of iterative refinement steps.</td><td>casadi::QpoasesInterface</td></tr>
<tr><td>numRegularisationSteps</td><td>OT_INT</td><td>Maximum number of successive regularisation steps.</td><td>casadi::QpoasesInterface</td></tr>
<tr><td>printLevel</td><td>OT_STRING</td><td>Defines the amount of text output during QP solution, see Section 5.7</td><td>casadi::QpoasesInterface</td></tr>
<tr><td>sparse</td><td>OT_BOOL</td><td>Formulate the QP using sparse matrices. Default: false</td><td>casadi::QpoasesInterface</td></tr>
<tr><td>terminationTolerance</td><td>OT_DOUBLE</td><td>Relative termination tolerance to stop homotopy.</td><td>casadi::QpoasesInterface</td></tr>
</table>
*/
/// \cond INTERNAL
/** \class casadi::Qpsol
\n
\par
<a name='options'></a><table>
<caption>List of available options</caption>
<tr><th>Id</th><th>Type</th><th>Description</th><th>Used in</th></tr>
<tr><td>ad_weight</td><td>OT_DOUBLE</td><td>Weighting factor for derivative calculation.When there is an option of either using forward or reverse mode directional derivatives, the condition ad_weight*nf&lt;=(1-ad_weight)*na is used where nf and na are estimates of the number of forward/reverse mode directional derivatives needed. By default, ad_weight is calculated automatically, but this can be overridden by setting this option. In particular, 0 means forcing forward mode and 1 forcing reverse mode. Leave unset for (class specific) heuristics.</td><td>casadi::FunctionInternal</td></tr>
<tr><td>ad_weight_sp</td><td>OT_DOUBLE</td><td>Weighting factor for sparsity pattern calculation calculation.Overrides default behavior. Set to 0 and 1 to force forward and reverse mode respectively. Cf. option \"ad_weight\".</td><td>casadi::FunctionInternal</td></tr>
<tr><td>compiler</td><td>OT_STRING</td><td>Just-in-time compiler plugin to be used.</td><td>casadi::FunctionInternal</td></tr>
<tr><td>discrete</td><td>OT_BOOLVECTOR</td><td>Indicates which of the variables are discrete, i.e. integer-valued</td><td>casadi::Qpsol</td></tr>
<tr><td>gather_stats</td><td>OT_BOOL</td><td>Flag to indicate whether statistics must be gathered</td><td>casadi::FunctionInternal</td></tr>
<tr><td>input_scheme</td><td>OT_STRINGVECTOR</td><td>Custom input scheme</td><td>casadi::FunctionInternal</td></tr>
<tr><td>inputs_check</td><td>OT_BOOL</td><td>Throw exceptions when the numerical values of the inputs don't make sense</td><td>casadi::FunctionInternal</td></tr>
<tr><td>jac_penalty</td><td>OT_DOUBLE</td><td>When requested for a number of forward/reverse directions,   it may be cheaper to compute first the full jacobian and then multiply with seeds, rather than obtain the requested directions in a straightforward manner. Casadi uses a heuristic to decide which is cheaper. A high value of 'jac_penalty' makes it less likely for the heurstic to chose the full Jacobian strategy. The special value -1 indicates never to use the full Jacobian strategy</td><td>casadi::FunctionInternal</td></tr>
<tr><td>jit</td><td>OT_BOOL</td><td>Use just-in-time compiler to speed up the evaluation</td><td>casadi::FunctionInternal</td></tr>
<tr><td>jit_options</td><td>OT_DICT</td><td>Options to be passed to the jit compiler.</td><td>casadi::FunctionInternal</td></tr>
<tr><td>monitor</td><td>OT_STRINGVECTOR</td><td>Monitors to be activated</td><td>casadi::FunctionInternal</td></tr>
<tr><td>output_scheme</td><td>OT_STRINGVECTOR</td><td>Custom output scheme</td><td>casadi::FunctionInternal</td></tr>
<tr><td>regularity_check</td><td>OT_BOOL</td><td>Throw exceptions when NaN or Inf appears during evaluation</td><td>casadi::FunctionInternal</td></tr>
<tr><td>user_data</td><td>OT_VOIDPTR</td><td>A user-defined field that can be used to identify the function or pass additional information</td><td>casadi::FunctionInternal</td></tr>
<tr><td>verbose</td><td>OT_BOOL</td><td>Verbose evaluation -- for debugging</td><td>casadi::FunctionInternal</td></tr>
</table>
*/
/// \endcond
/** \addtogroup general_Qpsol
\n
\par
<a name='options'></a><table>
<caption>List of available options</caption>
<tr><th>Id</th><th>Type</th><th>Description</th><th>Used in</th></tr>
<tr><td>ad_weight</td><td>OT_DOUBLE</td><td>Weighting factor for derivative calculation.When there is an option of either using forward or reverse mode directional derivatives, the condition ad_weight*nf&lt;=(1-ad_weight)*na is used where nf and na are estimates of the number of forward/reverse mode directional derivatives needed. By default, ad_weight is calculated automatically, but this can be overridden by setting this option. In particular, 0 means forcing forward mode and 1 forcing reverse mode. Leave unset for (class specific) heuristics.</td><td>casadi::FunctionInternal</td></tr>
<tr><td>ad_weight_sp</td><td>OT_DOUBLE</td><td>Weighting factor for sparsity pattern calculation calculation.Overrides default behavior. Set to 0 and 1 to force forward and reverse mode respectively. Cf. option \"ad_weight\".</td><td>casadi::FunctionInternal</td></tr>
<tr><td>compiler</td><td>OT_STRING</td><td>Just-in-time compiler plugin to be used.</td><td>casadi::FunctionInternal</td></tr>
<tr><td>discrete</td><td>OT_BOOLVECTOR</td><td>Indicates which of the variables are discrete, i.e. integer-valued</td><td>casadi::Qpsol</td></tr>
<tr><td>gather_stats</td><td>OT_BOOL</td><td>Flag to indicate whether statistics must be gathered</td><td>casadi::FunctionInternal</td></tr>
<tr><td>input_scheme</td><td>OT_STRINGVECTOR</td><td>Custom input scheme</td><td>casadi::FunctionInternal</td></tr>
<tr><td>inputs_check</td><td>OT_BOOL</td><td>Throw exceptions when the numerical values of the inputs don't make sense</td><td>casadi::FunctionInternal</td></tr>
<tr><td>jac_penalty</td><td>OT_DOUBLE</td><td>When requested for a number of forward/reverse directions,   it may be cheaper to compute first the full jacobian and then multiply with seeds, rather than obtain the requested directions in a straightforward manner. Casadi uses a heuristic to decide which is cheaper. A high value of 'jac_penalty' makes it less likely for the heurstic to chose the full Jacobian strategy. The special value -1 indicates never to use the full Jacobian strategy</td><td>casadi::FunctionInternal</td></tr>
<tr><td>jit</td><td>OT_BOOL</td><td>Use just-in-time compiler to speed up the evaluation</td><td>casadi::FunctionInternal</td></tr>
<tr><td>jit_options</td><td>OT_DICT</td><td>Options to be passed to the jit compiler.</td><td>casadi::FunctionInternal</td></tr>
<tr><td>monitor</td><td>OT_STRINGVECTOR</td><td>Monitors to be activated</td><td>casadi::FunctionInternal</td></tr>
<tr><td>output_scheme</td><td>OT_STRINGVECTOR</td><td>Custom output scheme</td><td>casadi::FunctionInternal</td></tr>
<tr><td>regularity_check</td><td>OT_BOOL</td><td>Throw exceptions when NaN or Inf appears during evaluation</td><td>casadi::FunctionInternal</td></tr>
<tr><td>user_data</td><td>OT_VOIDPTR</td><td>A user-defined field that can be used to identify the function or pass additional information</td><td>casadi::FunctionInternal</td></tr>
<tr><td>verbose</td><td>OT_BOOL</td><td>Verbose evaluation -- for debugging</td><td>casadi::FunctionInternal</td></tr>
</table>
*/
/// \cond INTERNAL
/** \class casadi::Rootfinder
\n
\par
<a name='options'></a><table>
<caption>List of available options</caption>
<tr><th>Id</th><th>Type</th><th>Description</th><th>Used in</th></tr>
<tr><td>ad_weight</td><td>OT_DOUBLE</td><td>Weighting factor for derivative calculation.When there is an option of either using forward or reverse mode directional derivatives, the condition ad_weight*nf&lt;=(1-ad_weight)*na is used where nf and na are estimates of the number of forward/reverse mode directional derivatives needed. By default, ad_weight is calculated automatically, but this can be overridden by setting this option. In particular, 0 means forcing forward mode and 1 forcing reverse mode. Leave unset for (class specific) heuristics.</td><td>casadi::FunctionInternal</td></tr>
<tr><td>ad_weight_sp</td><td>OT_DOUBLE</td><td>Weighting factor for sparsity pattern calculation calculation.Overrides default behavior. Set to 0 and 1 to force forward and reverse mode respectively. Cf. option \"ad_weight\".</td><td>casadi::FunctionInternal</td></tr>
<tr><td>compiler</td><td>OT_STRING</td><td>Just-in-time compiler plugin to be used.</td><td>casadi::FunctionInternal</td></tr>
<tr><td>constraints</td><td>OT_INTVECTOR</td><td>Constrain the unknowns. 0 (default): no constraint on ui, 1: ui &gt;= 0.0, -1: ui &lt;= 0.0, 2: ui &gt; 0.0, -2: ui &lt; 0.0.</td><td>casadi::Rootfinder</td></tr>
<tr><td>gather_stats</td><td>OT_BOOL</td><td>Flag to indicate whether statistics must be gathered</td><td>casadi::FunctionInternal</td></tr>
<tr><td>implicit_input</td><td>OT_INT</td><td>Index of the input that corresponds to the actual root-finding</td><td>casadi::Rootfinder</td></tr>
<tr><td>implicit_output</td><td>OT_INT</td><td>Index of the output that corresponds to the actual root-finding</td><td>casadi::Rootfinder</td></tr>
<tr><td>input_scheme</td><td>OT_STRINGVECTOR</td><td>Custom input scheme</td><td>casadi::FunctionInternal</td></tr>
<tr><td>inputs_check</td><td>OT_BOOL</td><td>Throw exceptions when the numerical values of the inputs don't make sense</td><td>casadi::FunctionInternal</td></tr>
<tr><td>jac_penalty</td><td>OT_DOUBLE</td><td>When requested for a number of forward/reverse directions,   it may be cheaper to compute first the full jacobian and then multiply with seeds, rather than obtain the requested directions in a straightforward manner. Casadi uses a heuristic to decide which is cheaper. A high value of 'jac_penalty' makes it less likely for the heurstic to chose the full Jacobian strategy. The special value -1 indicates never to use the full Jacobian strategy</td><td>casadi::FunctionInternal</td></tr>
<tr><td>jacobian_function</td><td>OT_FUNCTION</td><td>Function object for calculating the Jacobian (autogenerated by default)</td><td>casadi::Rootfinder</td></tr>
<tr><td>jit</td><td>OT_BOOL</td><td>Use just-in-time compiler to speed up the evaluation</td><td>casadi::FunctionInternal</td></tr>
<tr><td>jit_options</td><td>OT_DICT</td><td>Options to be passed to the jit compiler.</td><td>casadi::FunctionInternal</td></tr>
<tr><td>linear_solver</td><td>OT_STRING</td><td>User-defined linear solver class. Needed for sensitivities.</td><td>casadi::Rootfinder</td></tr>
<tr><td>linear_solver_options</td><td>OT_DICT</td><td>Options to be passed to the linear solver.</td><td>casadi::Rootfinder</td></tr>
<tr><td>monitor</td><td>OT_STRINGVECTOR</td><td>Monitors to be activated</td><td>casadi::FunctionInternal</td></tr>
<tr><td>output_scheme</td><td>OT_STRINGVECTOR</td><td>Custom output scheme</td><td>casadi::FunctionInternal</td></tr>
<tr><td>regularity_check</td><td>OT_BOOL</td><td>Throw exceptions when NaN or Inf appears during evaluation</td><td>casadi::FunctionInternal</td></tr>
<tr><td>user_data</td><td>OT_VOIDPTR</td><td>A user-defined field that can be used to identify the function or pass additional information</td><td>casadi::FunctionInternal</td></tr>
<tr><td>verbose</td><td>OT_BOOL</td><td>Verbose evaluation -- for debugging</td><td>casadi::FunctionInternal</td></tr>
</table>
*/
/// \endcond
/** \addtogroup general_Rootfinder
\n
\par
<a name='options'></a><table>
<caption>List of available options</caption>
<tr><th>Id</th><th>Type</th><th>Description</th><th>Used in</th></tr>
<tr><td>ad_weight</td><td>OT_DOUBLE</td><td>Weighting factor for derivative calculation.When there is an option of either using forward or reverse mode directional derivatives, the condition ad_weight*nf&lt;=(1-ad_weight)*na is used where nf and na are estimates of the number of forward/reverse mode directional derivatives needed. By default, ad_weight is calculated automatically, but this can be overridden by setting this option. In particular, 0 means forcing forward mode and 1 forcing reverse mode. Leave unset for (class specific) heuristics.</td><td>casadi::FunctionInternal</td></tr>
<tr><td>ad_weight_sp</td><td>OT_DOUBLE</td><td>Weighting factor for sparsity pattern calculation calculation.Overrides default behavior. Set to 0 and 1 to force forward and reverse mode respectively. Cf. option \"ad_weight\".</td><td>casadi::FunctionInternal</td></tr>
<tr><td>compiler</td><td>OT_STRING</td><td>Just-in-time compiler plugin to be used.</td><td>casadi::FunctionInternal</td></tr>
<tr><td>constraints</td><td>OT_INTVECTOR</td><td>Constrain the unknowns. 0 (default): no constraint on ui, 1: ui &gt;= 0.0, -1: ui &lt;= 0.0, 2: ui &gt; 0.0, -2: ui &lt; 0.0.</td><td>casadi::Rootfinder</td></tr>
<tr><td>gather_stats</td><td>OT_BOOL</td><td>Flag to indicate whether statistics must be gathered</td><td>casadi::FunctionInternal</td></tr>
<tr><td>implicit_input</td><td>OT_INT</td><td>Index of the input that corresponds to the actual root-finding</td><td>casadi::Rootfinder</td></tr>
<tr><td>implicit_output</td><td>OT_INT</td><td>Index of the output that corresponds to the actual root-finding</td><td>casadi::Rootfinder</td></tr>
<tr><td>input_scheme</td><td>OT_STRINGVECTOR</td><td>Custom input scheme</td><td>casadi::FunctionInternal</td></tr>
<tr><td>inputs_check</td><td>OT_BOOL</td><td>Throw exceptions when the numerical values of the inputs don't make sense</td><td>casadi::FunctionInternal</td></tr>
<tr><td>jac_penalty</td><td>OT_DOUBLE</td><td>When requested for a number of forward/reverse directions,   it may be cheaper to compute first the full jacobian and then multiply with seeds, rather than obtain the requested directions in a straightforward manner. Casadi uses a heuristic to decide which is cheaper. A high value of 'jac_penalty' makes it less likely for the heurstic to chose the full Jacobian strategy. The special value -1 indicates never to use the full Jacobian strategy</td><td>casadi::FunctionInternal</td></tr>
<tr><td>jacobian_function</td><td>OT_FUNCTION</td><td>Function object for calculating the Jacobian (autogenerated by default)</td><td>casadi::Rootfinder</td></tr>
<tr><td>jit</td><td>OT_BOOL</td><td>Use just-in-time compiler to speed up the evaluation</td><td>casadi::FunctionInternal</td></tr>
<tr><td>jit_options</td><td>OT_DICT</td><td>Options to be passed to the jit compiler.</td><td>casadi::FunctionInternal</td></tr>
<tr><td>linear_solver</td><td>OT_STRING</td><td>User-defined linear solver class. Needed for sensitivities.</td><td>casadi::Rootfinder</td></tr>
<tr><td>linear_solver_options</td><td>OT_DICT</td><td>Options to be passed to the linear solver.</td><td>casadi::Rootfinder</td></tr>
<tr><td>monitor</td><td>OT_STRINGVECTOR</td><td>Monitors to be activated</td><td>casadi::FunctionInternal</td></tr>
<tr><td>output_scheme</td><td>OT_STRINGVECTOR</td><td>Custom output scheme</td><td>casadi::FunctionInternal</td></tr>
<tr><td>regularity_check</td><td>OT_BOOL</td><td>Throw exceptions when NaN or Inf appears during evaluation</td><td>casadi::FunctionInternal</td></tr>
<tr><td>user_data</td><td>OT_VOIDPTR</td><td>A user-defined field that can be used to identify the function or pass additional information</td><td>casadi::FunctionInternal</td></tr>
<tr><td>verbose</td><td>OT_BOOL</td><td>Verbose evaluation -- for debugging</td><td>casadi::FunctionInternal</td></tr>
</table>
*/
/// \cond INTERNAL
/** \class casadi::SXFunction
\n
\par
<a name='options'></a><table>
<caption>List of available options</caption>
<tr><th>Id</th><th>Type</th><th>Description</th><th>Used in</th></tr>
<tr><td>ad_weight</td><td>OT_DOUBLE</td><td>Weighting factor for derivative calculation.When there is an option of either using forward or reverse mode directional derivatives, the condition ad_weight*nf&lt;=(1-ad_weight)*na is used where nf and na are estimates of the number of forward/reverse mode directional derivatives needed. By default, ad_weight is calculated automatically, but this can be overridden by setting this option. In particular, 0 means forcing forward mode and 1 forcing reverse mode. Leave unset for (class specific) heuristics.</td><td>casadi::FunctionInternal</td></tr>
<tr><td>ad_weight_sp</td><td>OT_DOUBLE</td><td>Weighting factor for sparsity pattern calculation calculation.Overrides default behavior. Set to 0 and 1 to force forward and reverse mode respectively. Cf. option \"ad_weight\".</td><td>casadi::FunctionInternal</td></tr>
<tr><td>compiler</td><td>OT_STRING</td><td>Just-in-time compiler plugin to be used.</td><td>casadi::FunctionInternal</td></tr>
<tr><td>default_in</td><td>OT_DOUBLEVECTOR</td><td>Default input values</td><td>casadi::SXFunction</td></tr>
<tr><td>gather_stats</td><td>OT_BOOL</td><td>Flag to indicate whether statistics must be gathered</td><td>casadi::FunctionInternal</td></tr>
<tr><td>input_scheme</td><td>OT_STRINGVECTOR</td><td>Custom input scheme</td><td>casadi::FunctionInternal</td></tr>
<tr><td>inputs_check</td><td>OT_BOOL</td><td>Throw exceptions when the numerical values of the inputs don't make sense</td><td>casadi::FunctionInternal</td></tr>
<tr><td>jac_penalty</td><td>OT_DOUBLE</td><td>When requested for a number of forward/reverse directions,   it may be cheaper to compute first the full jacobian and then multiply with seeds, rather than obtain the requested directions in a straightforward manner. Casadi uses a heuristic to decide which is cheaper. A high value of 'jac_penalty' makes it less likely for the heurstic to chose the full Jacobian strategy. The special value -1 indicates never to use the full Jacobian strategy</td><td>casadi::FunctionInternal</td></tr>
<tr><td>jit</td><td>OT_BOOL</td><td>Use just-in-time compiler to speed up the evaluation</td><td>casadi::FunctionInternal</td></tr>
<tr><td>jit_options</td><td>OT_DICT</td><td>Options to be passed to the jit compiler.</td><td>casadi::FunctionInternal</td></tr>
<tr><td>just_in_time_opencl</td><td>OT_BOOL</td><td>Just-in-time compilation for numeric evaluation using OpenCL (experimental)</td><td>casadi::SXFunction</td></tr>
<tr><td>just_in_time_sparsity</td><td>OT_BOOL</td><td>Propagate sparsity patterns using just-in-time compilation to a CPU or GPU using OpenCL</td><td>casadi::SXFunction</td></tr>
<tr><td>live_variables</td><td>OT_BOOL</td><td>Reuse variables in the work vector</td><td>casadi::SXFunction</td></tr>
<tr><td>monitor</td><td>OT_STRINGVECTOR</td><td>Monitors to be activated</td><td>casadi::FunctionInternal</td></tr>
<tr><td>output_scheme</td><td>OT_STRINGVECTOR</td><td>Custom output scheme</td><td>casadi::FunctionInternal</td></tr>
<tr><td>regularity_check</td><td>OT_BOOL</td><td>Throw exceptions when NaN or Inf appears during evaluation</td><td>casadi::FunctionInternal</td></tr>
<tr><td>user_data</td><td>OT_VOIDPTR</td><td>A user-defined field that can be used to identify the function or pass additional information</td><td>casadi::FunctionInternal</td></tr>
<tr><td>verbose</td><td>OT_BOOL</td><td>Verbose evaluation -- for debugging</td><td>casadi::FunctionInternal</td></tr>
</table>
*/
/// \endcond
/// \cond INTERNAL
/** \class casadi::Scpgen
\n
\par
<a name='options'></a><table>
<caption>List of available options</caption>
<tr><th>Id</th><th>Type</th><th>Description</th><th>Used in</th></tr>
<tr><td>beta</td><td>OT_DOUBLE</td><td>Line-search parameter, restoration factor of stepsize</td><td>casadi::Scpgen</td></tr>
<tr><td>c1</td><td>OT_DOUBLE</td><td>Armijo condition, coefficient of decrease in merit</td><td>casadi::Scpgen</td></tr>
<tr><td>codegen</td><td>OT_BOOL</td><td>C-code generation</td><td>casadi::Scpgen</td></tr>
<tr><td>eval_errors_fatal</td><td>OT_BOOL</td><td>When errors occur during evaluation of f,g,...,stop the iterations</td><td>casadi::Nlpsol</td></tr>
<tr><td>expand</td><td>OT_BOOL</td><td>Replace MX with SX expressions in problem formulation [false]</td><td>casadi::Nlpsol</td></tr>
<tr><td>hessian_approximation</td><td>OT_STRING</td><td>gauss-newton|exact</td><td>casadi::Scpgen</td></tr>
<tr><td>ignore_check_vec</td><td>OT_BOOL</td><td>If set to true, the input shape of F will not be checked.</td><td>casadi::Nlpsol</td></tr>
<tr><td>iteration_callback</td><td>OT_FUNCTION</td><td>A function that will be called at each iteration with the solver as input. Check documentation of Callback.</td><td>casadi::Nlpsol</td></tr>
<tr><td>iteration_callback_ignore_errors</td><td>OT_BOOL</td><td>If set to true, errors thrown by iteration_callback will be ignored.</td><td>casadi::Nlpsol</td></tr>
<tr><td>iteration_callback_step</td><td>OT_INT</td><td>Only call the callback function every few iterations.</td><td>casadi::Nlpsol</td></tr>
<tr><td>lbfgs_memory</td><td>OT_INT</td><td>Size of L-BFGS memory.</td><td>casadi::Scpgen</td></tr>
<tr><td>max_iter</td><td>OT_INT</td><td>Maximum number of SQP iterations</td><td>casadi::Scpgen</td></tr>
<tr><td>max_iter_ls</td><td>OT_INT</td><td>Maximum number of linesearch iterations</td><td>casadi::Scpgen</td></tr>
<tr><td>merit_memsize</td><td>OT_INT</td><td>Size of memory to store history of merit function values</td><td>casadi::Scpgen</td></tr>
<tr><td>merit_start</td><td>OT_DOUBLE</td><td>Lower bound for the merit function parameter</td><td>casadi::Scpgen</td></tr>
<tr><td>name_x</td><td>OT_STRINGVECTOR</td><td>Names of the variables.</td><td>casadi::Scpgen</td></tr>
<tr><td>print_header</td><td>OT_BOOL</td><td>Print the header with problem statistics</td><td>casadi::Scpgen</td></tr>
<tr><td>print_time</td><td>OT_BOOL</td><td>Print information about execution time</td><td>casadi::Scpgen</td></tr>
<tr><td>print_x</td><td>OT_INTVECTOR</td><td>Which variables to print.</td><td>casadi::Scpgen</td></tr>
<tr><td>qpsol</td><td>OT_STRING</td><td>The QP solver to be used by the SQP method</td><td>casadi::Scpgen</td></tr>
<tr><td>qpsol_options</td><td>OT_DICT</td><td>Options to be passed to the QP solver</td><td>casadi::Scpgen</td></tr>
<tr><td>reg_threshold</td><td>OT_DOUBLE</td><td>Threshold for the regularization.</td><td>casadi::Scpgen</td></tr>
<tr><td>regularize</td><td>OT_BOOL</td><td>Automatic regularization of Lagrange Hessian.</td><td>casadi::Scpgen</td></tr>
<tr><td>tol_du</td><td>OT_DOUBLE</td><td>Stopping criterion for dual infeasability</td><td>casadi::Scpgen</td></tr>
<tr><td>tol_pr</td><td>OT_DOUBLE</td><td>Stopping criterion for primal infeasibility</td><td>casadi::Scpgen</td></tr>
<tr><td>tol_pr_step</td><td>OT_DOUBLE</td><td>Stopping criterion for the step size</td><td>casadi::Scpgen</td></tr>
<tr><td>tol_reg</td><td>OT_DOUBLE</td><td>Stopping criterion for regularization</td><td>casadi::Scpgen</td></tr>
<tr><td>verbose_init</td><td>OT_BOOL</td><td>Print out timing information about the different stages of initialization</td><td>casadi::Nlpsol</td></tr>
<tr><td>warn_initial_bounds</td><td>OT_BOOL</td><td>Warn if the initial guess does not satisfy LBX and UBX</td><td>casadi::Nlpsol</td></tr>
</table>
*/
/// \endcond
/** \addtogroup plugin_Nlpsol_scpgen
\n
\par
<a name='options'></a><table>
<caption>List of available options</caption>
<tr><th>Id</th><th>Type</th><th>Description</th></tr>
<tr><td>beta</td><td>OT_DOUBLE</td><td>Line-search parameter, restoration factor of stepsize</td></tr>
<tr><td>c1</td><td>OT_DOUBLE</td><td>Armijo condition, coefficient of decrease in merit</td></tr>
<tr><td>codegen</td><td>OT_BOOL</td><td>C-code generation</td></tr>
<tr><td>hessian_approximation</td><td>OT_STRING</td><td>gauss-newton|exact</td></tr>
<tr><td>lbfgs_memory</td><td>OT_INT</td><td>Size of L-BFGS memory.</td></tr>
<tr><td>max_iter</td><td>OT_INT</td><td>Maximum number of SQP iterations</td></tr>
<tr><td>max_iter_ls</td><td>OT_INT</td><td>Maximum number of linesearch iterations</td></tr>
<tr><td>merit_memsize</td><td>OT_INT</td><td>Size of memory to store history of merit function values</td></tr>
<tr><td>merit_start</td><td>OT_DOUBLE</td><td>Lower bound for the merit function parameter</td></tr>
<tr><td>name_x</td><td>OT_STRINGVECTOR</td><td>Names of the variables.</td></tr>
<tr><td>print_header</td><td>OT_BOOL</td><td>Print the header with problem statistics</td></tr>
<tr><td>print_time</td><td>OT_BOOL</td><td>Print information about execution time</td></tr>
<tr><td>print_x</td><td>OT_INTVECTOR</td><td>Which variables to print.</td></tr>
<tr><td>qpsol</td><td>OT_STRING</td><td>The QP solver to be used by the SQP method</td></tr>
<tr><td>qpsol_options</td><td>OT_DICT</td><td>Options to be passed to the QP solver</td></tr>
<tr><td>reg_threshold</td><td>OT_DOUBLE</td><td>Threshold for the regularization.</td></tr>
<tr><td>regularize</td><td>OT_BOOL</td><td>Automatic regularization of Lagrange Hessian.</td></tr>
<tr><td>tol_du</td><td>OT_DOUBLE</td><td>Stopping criterion for dual infeasability</td></tr>
<tr><td>tol_pr</td><td>OT_DOUBLE</td><td>Stopping criterion for primal infeasibility</td></tr>
<tr><td>tol_pr_step</td><td>OT_DOUBLE</td><td>Stopping criterion for the step size</td></tr>
<tr><td>tol_reg</td><td>OT_DOUBLE</td><td>Stopping criterion for regularization</td></tr>
</table>
*/
/** \addtogroup general_Scpgen
\n
\par
<a name='options'></a><table>
<caption>List of available options</caption>
<tr><th>Id</th><th>Type</th><th>Description</th><th>Used in</th></tr>
<tr><td>beta</td><td>OT_DOUBLE</td><td>Line-search parameter, restoration factor of stepsize</td><td>casadi::Scpgen</td></tr>
<tr><td>c1</td><td>OT_DOUBLE</td><td>Armijo condition, coefficient of decrease in merit</td><td>casadi::Scpgen</td></tr>
<tr><td>codegen</td><td>OT_BOOL</td><td>C-code generation</td><td>casadi::Scpgen</td></tr>
<tr><td>eval_errors_fatal</td><td>OT_BOOL</td><td>When errors occur during evaluation of f,g,...,stop the iterations</td><td>casadi::Nlpsol</td></tr>
<tr><td>expand</td><td>OT_BOOL</td><td>Replace MX with SX expressions in problem formulation [false]</td><td>casadi::Nlpsol</td></tr>
<tr><td>hessian_approximation</td><td>OT_STRING</td><td>gauss-newton|exact</td><td>casadi::Scpgen</td></tr>
<tr><td>ignore_check_vec</td><td>OT_BOOL</td><td>If set to true, the input shape of F will not be checked.</td><td>casadi::Nlpsol</td></tr>
<tr><td>iteration_callback</td><td>OT_FUNCTION</td><td>A function that will be called at each iteration with the solver as input. Check documentation of Callback.</td><td>casadi::Nlpsol</td></tr>
<tr><td>iteration_callback_ignore_errors</td><td>OT_BOOL</td><td>If set to true, errors thrown by iteration_callback will be ignored.</td><td>casadi::Nlpsol</td></tr>
<tr><td>iteration_callback_step</td><td>OT_INT</td><td>Only call the callback function every few iterations.</td><td>casadi::Nlpsol</td></tr>
<tr><td>lbfgs_memory</td><td>OT_INT</td><td>Size of L-BFGS memory.</td><td>casadi::Scpgen</td></tr>
<tr><td>max_iter</td><td>OT_INT</td><td>Maximum number of SQP iterations</td><td>casadi::Scpgen</td></tr>
<tr><td>max_iter_ls</td><td>OT_INT</td><td>Maximum number of linesearch iterations</td><td>casadi::Scpgen</td></tr>
<tr><td>merit_memsize</td><td>OT_INT</td><td>Size of memory to store history of merit function values</td><td>casadi::Scpgen</td></tr>
<tr><td>merit_start</td><td>OT_DOUBLE</td><td>Lower bound for the merit function parameter</td><td>casadi::Scpgen</td></tr>
<tr><td>name_x</td><td>OT_STRINGVECTOR</td><td>Names of the variables.</td><td>casadi::Scpgen</td></tr>
<tr><td>print_header</td><td>OT_BOOL</td><td>Print the header with problem statistics</td><td>casadi::Scpgen</td></tr>
<tr><td>print_time</td><td>OT_BOOL</td><td>Print information about execution time</td><td>casadi::Scpgen</td></tr>
<tr><td>print_x</td><td>OT_INTVECTOR</td><td>Which variables to print.</td><td>casadi::Scpgen</td></tr>
<tr><td>qpsol</td><td>OT_STRING</td><td>The QP solver to be used by the SQP method</td><td>casadi::Scpgen</td></tr>
<tr><td>qpsol_options</td><td>OT_DICT</td><td>Options to be passed to the QP solver</td><td>casadi::Scpgen</td></tr>
<tr><td>reg_threshold</td><td>OT_DOUBLE</td><td>Threshold for the regularization.</td><td>casadi::Scpgen</td></tr>
<tr><td>regularize</td><td>OT_BOOL</td><td>Automatic regularization of Lagrange Hessian.</td><td>casadi::Scpgen</td></tr>
<tr><td>tol_du</td><td>OT_DOUBLE</td><td>Stopping criterion for dual infeasability</td><td>casadi::Scpgen</td></tr>
<tr><td>tol_pr</td><td>OT_DOUBLE</td><td>Stopping criterion for primal infeasibility</td><td>casadi::Scpgen</td></tr>
<tr><td>tol_pr_step</td><td>OT_DOUBLE</td><td>Stopping criterion for the step size</td><td>casadi::Scpgen</td></tr>
<tr><td>tol_reg</td><td>OT_DOUBLE</td><td>Stopping criterion for regularization</td><td>casadi::Scpgen</td></tr>
<tr><td>verbose_init</td><td>OT_BOOL</td><td>Print out timing information about the different stages of initialization</td><td>casadi::Nlpsol</td></tr>
<tr><td>warn_initial_bounds</td><td>OT_BOOL</td><td>Warn if the initial guess does not satisfy LBX and UBX</td><td>casadi::Nlpsol</td></tr>
</table>
*/
/// \cond INTERNAL
/** \class casadi::ShellCompiler
\n
\par
<a name='options'></a><table>
<caption>List of available options</caption>
<tr><th>Id</th><th>Type</th><th>Description</th><th>Used in</th></tr>
<tr><td>compiler</td><td>OT_STRING</td><td>Compiler command</td><td>casadi::ShellCompiler</td></tr>
<tr><td>compiler_setup</td><td>OT_STRING</td><td>Compiler setup command. Intended to be fixed. The 'flag' option is the prefered way to set custom flags.</td><td>casadi::ShellCompiler</td></tr>
<tr><td>flags</td><td>OT_STRINGVECTOR</td><td>Compile flags for the JIT compiler. Default: None</td><td>casadi::ShellCompiler</td></tr>
</table>
*/
/// \endcond
/** \addtogroup plugin_Compiler_shell
\n
\par
<a name='options'></a><table>
<caption>List of available options</caption>
<tr><th>Id</th><th>Type</th><th>Description</th></tr>
<tr><td>compiler</td><td>OT_STRING</td><td>Compiler command</td></tr>
<tr><td>compiler_setup</td><td>OT_STRING</td><td>Compiler setup command. Intended to be fixed. The 'flag' option is the prefered way to set custom flags.</td></tr>
<tr><td>flags</td><td>OT_STRINGVECTOR</td><td>Compile flags for the JIT compiler. Default: None</td></tr>
</table>
*/
/** \addtogroup general_ShellCompiler
\n
\par
<a name='options'></a><table>
<caption>List of available options</caption>
<tr><th>Id</th><th>Type</th><th>Description</th><th>Used in</th></tr>
<tr><td>compiler</td><td>OT_STRING</td><td>Compiler command</td><td>casadi::ShellCompiler</td></tr>
<tr><td>compiler_setup</td><td>OT_STRING</td><td>Compiler setup command. Intended to be fixed. The 'flag' option is the prefered way to set custom flags.</td><td>casadi::ShellCompiler</td></tr>
<tr><td>flags</td><td>OT_STRINGVECTOR</td><td>Compile flags for the JIT compiler. Default: None</td><td>casadi::ShellCompiler</td></tr>
</table>
*/
/// \cond INTERNAL
/** \class casadi::SnoptInterface
\n
\par
<a name='options'></a><table>
<caption>List of available options</caption>
<tr><th>Id</th><th>Type</th><th>Description</th><th>Used in</th></tr>
<tr><td>eval_errors_fatal</td><td>OT_BOOL</td><td>When errors occur during evaluation of f,g,...,stop the iterations</td><td>casadi::Nlpsol</td></tr>
<tr><td>expand</td><td>OT_BOOL</td><td>Replace MX with SX expressions in problem formulation [false]</td><td>casadi::Nlpsol</td></tr>
<tr><td>ignore_check_vec</td><td>OT_BOOL</td><td>If set to true, the input shape of F will not be checked.</td><td>casadi::Nlpsol</td></tr>
<tr><td>iteration_callback</td><td>OT_FUNCTION</td><td>A function that will be called at each iteration with the solver as input. Check documentation of Callback.</td><td>casadi::Nlpsol</td></tr>
<tr><td>iteration_callback_ignore_errors</td><td>OT_BOOL</td><td>If set to true, errors thrown by iteration_callback will be ignored.</td><td>casadi::Nlpsol</td></tr>
<tr><td>iteration_callback_step</td><td>OT_INT</td><td>Only call the callback function every few iterations.</td><td>casadi::Nlpsol</td></tr>
<tr><td>snopt</td><td>OT_DICT</td><td>Options to be passed to SNOPT</td><td>casadi::SnoptInterface</td></tr>
<tr><td>verbose_init</td><td>OT_BOOL</td><td>Print out timing information about the different stages of initialization</td><td>casadi::Nlpsol</td></tr>
<tr><td>warn_initial_bounds</td><td>OT_BOOL</td><td>Warn if the initial guess does not satisfy LBX and UBX</td><td>casadi::Nlpsol</td></tr>
</table>
*/
/// \endcond
/** \addtogroup plugin_Nlpsol_snopt
\n
\par
<a name='options'></a><table>
<caption>List of available options</caption>
<tr><th>Id</th><th>Type</th><th>Description</th></tr>
<tr><td>snopt</td><td>OT_DICT</td><td>Options to be passed to SNOPT</td></tr>
</table>
*/
/** \addtogroup general_SnoptInterface
\n
\par
<a name='options'></a><table>
<caption>List of available options</caption>
<tr><th>Id</th><th>Type</th><th>Description</th><th>Used in</th></tr>
<tr><td>eval_errors_fatal</td><td>OT_BOOL</td><td>When errors occur during evaluation of f,g,...,stop the iterations</td><td>casadi::Nlpsol</td></tr>
<tr><td>expand</td><td>OT_BOOL</td><td>Replace MX with SX expressions in problem formulation [false]</td><td>casadi::Nlpsol</td></tr>
<tr><td>ignore_check_vec</td><td>OT_BOOL</td><td>If set to true, the input shape of F will not be checked.</td><td>casadi::Nlpsol</td></tr>
<tr><td>iteration_callback</td><td>OT_FUNCTION</td><td>A function that will be called at each iteration with the solver as input. Check documentation of Callback.</td><td>casadi::Nlpsol</td></tr>
<tr><td>iteration_callback_ignore_errors</td><td>OT_BOOL</td><td>If set to true, errors thrown by iteration_callback will be ignored.</td><td>casadi::Nlpsol</td></tr>
<tr><td>iteration_callback_step</td><td>OT_INT</td><td>Only call the callback function every few iterations.</td><td>casadi::Nlpsol</td></tr>
<tr><td>snopt</td><td>OT_DICT</td><td>Options to be passed to SNOPT</td><td>casadi::SnoptInterface</td></tr>
<tr><td>verbose_init</td><td>OT_BOOL</td><td>Print out timing information about the different stages of initialization</td><td>casadi::Nlpsol</td></tr>
<tr><td>warn_initial_bounds</td><td>OT_BOOL</td><td>Warn if the initial guess does not satisfy LBX and UBX</td><td>casadi::Nlpsol</td></tr>
</table>
*/
/// \cond INTERNAL
/** \class casadi::Sqpmethod
\n
\par
<a name='options'></a><table>
<caption>List of available options</caption>
<tr><th>Id</th><th>Type</th><th>Description</th><th>Used in</th></tr>
<tr><td>beta</td><td>OT_DOUBLE</td><td>Line-search parameter, restoration factor of stepsize</td><td>casadi::Sqpmethod</td></tr>
<tr><td>c1</td><td>OT_DOUBLE</td><td>Armijo condition, coefficient of decrease in merit</td><td>casadi::Sqpmethod</td></tr>
<tr><td>eval_errors_fatal</td><td>OT_BOOL</td><td>When errors occur during evaluation of f,g,...,stop the iterations</td><td>casadi::Nlpsol</td></tr>
<tr><td>expand</td><td>OT_BOOL</td><td>Replace MX with SX expressions in problem formulation [false]</td><td>casadi::Nlpsol</td></tr>
<tr><td>hessian_approximation</td><td>OT_STRING</td><td>limited-memory|exact</td><td>casadi::Sqpmethod</td></tr>
<tr><td>ignore_check_vec</td><td>OT_BOOL</td><td>If set to true, the input shape of F will not be checked.</td><td>casadi::Nlpsol</td></tr>
<tr><td>iteration_callback</td><td>OT_FUNCTION</td><td>A function that will be called at each iteration with the solver as input. Check documentation of Callback.</td><td>casadi::Nlpsol</td></tr>
<tr><td>iteration_callback_ignore_errors</td><td>OT_BOOL</td><td>If set to true, errors thrown by iteration_callback will be ignored.</td><td>casadi::Nlpsol</td></tr>
<tr><td>iteration_callback_step</td><td>OT_INT</td><td>Only call the callback function every few iterations.</td><td>casadi::Nlpsol</td></tr>
<tr><td>lbfgs_memory</td><td>OT_INT</td><td>Size of L-BFGS memory.</td><td>casadi::Sqpmethod</td></tr>
<tr><td>max_iter</td><td>OT_INT</td><td>Maximum number of SQP iterations</td><td>casadi::Sqpmethod</td></tr>
<tr><td>max_iter_ls</td><td>OT_INT</td><td>Maximum number of linesearch iterations</td><td>casadi::Sqpmethod</td></tr>
<tr><td>merit_memory</td><td>OT_INT</td><td>Size of memory to store history of merit function values</td><td>casadi::Sqpmethod</td></tr>
<tr><td>min_step_size</td><td>OT_DOUBLE</td><td>The size (inf-norm) of the step size should not become smaller than this.</td><td>casadi::Sqpmethod</td></tr>
<tr><td>print_header</td><td>OT_BOOL</td><td>Print the header with problem statistics</td><td>casadi::Sqpmethod</td></tr>
<tr><td>print_time</td><td>OT_BOOL</td><td>Print information about execution time</td><td>casadi::Sqpmethod</td></tr>
<tr><td>qpsol</td><td>OT_STRING</td><td>The QP solver to be used by the SQP method</td><td>casadi::Sqpmethod</td></tr>
<tr><td>qpsol_options</td><td>OT_DICT</td><td>Options to be passed to the QP solver</td><td>casadi::Sqpmethod</td></tr>
<tr><td>regularize</td><td>OT_BOOL</td><td>Automatic regularization of Lagrange Hessian.</td><td>casadi::Sqpmethod</td></tr>
<tr><td>tol_du</td><td>OT_DOUBLE</td><td>Stopping criterion for dual infeasability</td><td>casadi::Sqpmethod</td></tr>
<tr><td>tol_pr</td><td>OT_DOUBLE</td><td>Stopping criterion for primal infeasibility</td><td>casadi::Sqpmethod</td></tr>
<tr><td>verbose_init</td><td>OT_BOOL</td><td>Print out timing information about the different stages of initialization</td><td>casadi::Nlpsol</td></tr>
<tr><td>warn_initial_bounds</td><td>OT_BOOL</td><td>Warn if the initial guess does not satisfy LBX and UBX</td><td>casadi::Nlpsol</td></tr>
</table>
*/
/// \endcond
/** \addtogroup plugin_Nlpsol_sqpmethod
\n
\par
<a name='options'></a><table>
<caption>List of available options</caption>
<tr><th>Id</th><th>Type</th><th>Description</th></tr>
<tr><td>beta</td><td>OT_DOUBLE</td><td>Line-search parameter, restoration factor of stepsize</td></tr>
<tr><td>c1</td><td>OT_DOUBLE</td><td>Armijo condition, coefficient of decrease in merit</td></tr>
<tr><td>hessian_approximation</td><td>OT_STRING</td><td>limited-memory|exact</td></tr>
<tr><td>lbfgs_memory</td><td>OT_INT</td><td>Size of L-BFGS memory.</td></tr>
<tr><td>max_iter</td><td>OT_INT</td><td>Maximum number of SQP iterations</td></tr>
<tr><td>max_iter_ls</td><td>OT_INT</td><td>Maximum number of linesearch iterations</td></tr>
<tr><td>merit_memory</td><td>OT_INT</td><td>Size of memory to store history of merit function values</td></tr>
<tr><td>min_step_size</td><td>OT_DOUBLE</td><td>The size (inf-norm) of the step size should not become smaller than this.</td></tr>
<tr><td>print_header</td><td>OT_BOOL</td><td>Print the header with problem statistics</td></tr>
<tr><td>print_time</td><td>OT_BOOL</td><td>Print information about execution time</td></tr>
<tr><td>qpsol</td><td>OT_STRING</td><td>The QP solver to be used by the SQP method</td></tr>
<tr><td>qpsol_options</td><td>OT_DICT</td><td>Options to be passed to the QP solver</td></tr>
<tr><td>regularize</td><td>OT_BOOL</td><td>Automatic regularization of Lagrange Hessian.</td></tr>
<tr><td>tol_du</td><td>OT_DOUBLE</td><td>Stopping criterion for dual infeasability</td></tr>
<tr><td>tol_pr</td><td>OT_DOUBLE</td><td>Stopping criterion for primal infeasibility</td></tr>
</table>
*/
/** \addtogroup general_Sqpmethod
\n
\par
<a name='options'></a><table>
<caption>List of available options</caption>
<tr><th>Id</th><th>Type</th><th>Description</th><th>Used in</th></tr>
<tr><td>beta</td><td>OT_DOUBLE</td><td>Line-search parameter, restoration factor of stepsize</td><td>casadi::Sqpmethod</td></tr>
<tr><td>c1</td><td>OT_DOUBLE</td><td>Armijo condition, coefficient of decrease in merit</td><td>casadi::Sqpmethod</td></tr>
<tr><td>eval_errors_fatal</td><td>OT_BOOL</td><td>When errors occur during evaluation of f,g,...,stop the iterations</td><td>casadi::Nlpsol</td></tr>
<tr><td>expand</td><td>OT_BOOL</td><td>Replace MX with SX expressions in problem formulation [false]</td><td>casadi::Nlpsol</td></tr>
<tr><td>hessian_approximation</td><td>OT_STRING</td><td>limited-memory|exact</td><td>casadi::Sqpmethod</td></tr>
<tr><td>ignore_check_vec</td><td>OT_BOOL</td><td>If set to true, the input shape of F will not be checked.</td><td>casadi::Nlpsol</td></tr>
<tr><td>iteration_callback</td><td>OT_FUNCTION</td><td>A function that will be called at each iteration with the solver as input. Check documentation of Callback.</td><td>casadi::Nlpsol</td></tr>
<tr><td>iteration_callback_ignore_errors</td><td>OT_BOOL</td><td>If set to true, errors thrown by iteration_callback will be ignored.</td><td>casadi::Nlpsol</td></tr>
<tr><td>iteration_callback_step</td><td>OT_INT</td><td>Only call the callback function every few iterations.</td><td>casadi::Nlpsol</td></tr>
<tr><td>lbfgs_memory</td><td>OT_INT</td><td>Size of L-BFGS memory.</td><td>casadi::Sqpmethod</td></tr>
<tr><td>max_iter</td><td>OT_INT</td><td>Maximum number of SQP iterations</td><td>casadi::Sqpmethod</td></tr>
<tr><td>max_iter_ls</td><td>OT_INT</td><td>Maximum number of linesearch iterations</td><td>casadi::Sqpmethod</td></tr>
<tr><td>merit_memory</td><td>OT_INT</td><td>Size of memory to store history of merit function values</td><td>casadi::Sqpmethod</td></tr>
<tr><td>min_step_size</td><td>OT_DOUBLE</td><td>The size (inf-norm) of the step size should not become smaller than this.</td><td>casadi::Sqpmethod</td></tr>
<tr><td>print_header</td><td>OT_BOOL</td><td>Print the header with problem statistics</td><td>casadi::Sqpmethod</td></tr>
<tr><td>print_time</td><td>OT_BOOL</td><td>Print information about execution time</td><td>casadi::Sqpmethod</td></tr>
<tr><td>qpsol</td><td>OT_STRING</td><td>The QP solver to be used by the SQP method</td><td>casadi::Sqpmethod</td></tr>
<tr><td>qpsol_options</td><td>OT_DICT</td><td>Options to be passed to the QP solver</td><td>casadi::Sqpmethod</td></tr>
<tr><td>regularize</td><td>OT_BOOL</td><td>Automatic regularization of Lagrange Hessian.</td><td>casadi::Sqpmethod</td></tr>
<tr><td>tol_du</td><td>OT_DOUBLE</td><td>Stopping criterion for dual infeasability</td><td>casadi::Sqpmethod</td></tr>
<tr><td>tol_pr</td><td>OT_DOUBLE</td><td>Stopping criterion for primal infeasibility</td><td>casadi::Sqpmethod</td></tr>
<tr><td>verbose_init</td><td>OT_BOOL</td><td>Print out timing information about the different stages of initialization</td><td>casadi::Nlpsol</td></tr>
<tr><td>warn_initial_bounds</td><td>OT_BOOL</td><td>Warn if the initial guess does not satisfy LBX and UBX</td><td>casadi::Nlpsol</td></tr>
</table>
*/
/// \cond INTERNAL
/** \class casadi::SundialsInterface
\n
\par
<a name='options'></a><table>
<caption>List of available options</caption>
<tr><th>Id</th><th>Type</th><th>Description</th><th>Used in</th></tr>
<tr><td>abstol</td><td>OT_DOUBLE</td><td>Absolute tolerence  for the IVP solution</td><td>casadi::SundialsInterface</td></tr>
<tr><td>abstolB</td><td>OT_DOUBLE</td><td>Absolute tolerence for the adjoint sensitivity solution [default: equal to abstol]</td><td>casadi::SundialsInterface</td></tr>
<tr><td>augmented_options</td><td>OT_DICT</td><td>Options to be passed down to the augmented integrator, if one is constructed.</td><td>casadi::Integrator</td></tr>
<tr><td>disable_internal_warnings</td><td>OT_BOOL</td><td>Disable SUNDIALS internal warning messages</td><td>casadi::SundialsInterface</td></tr>
<tr><td>exact_jacobian</td><td>OT_BOOL</td><td>Use exact Jacobian information for the forward integration</td><td>casadi::SundialsInterface</td></tr>
<tr><td>exact_jacobianB</td><td>OT_BOOL</td><td>Use exact Jacobian information for the backward integration [default: equal to exact_jacobian]</td><td>casadi::SundialsInterface</td></tr>
<tr><td>expand</td><td>OT_BOOL</td><td>Replace MX with SX expressions in problem formulation [false]</td><td>casadi::Integrator</td></tr>
<tr><td>finite_difference_fsens</td><td>OT_BOOL</td><td>Use finite differences to approximate the forward sensitivity equations (if AD is not available)</td><td>casadi::SundialsInterface</td></tr>
<tr><td>fsens_abstol</td><td>OT_DOUBLE</td><td>Absolute tolerence for the forward sensitivity solution [default: equal to abstol]</td><td>casadi::SundialsInterface</td></tr>
<tr><td>fsens_err_con</td><td>OT_BOOL</td><td>include the forward sensitivities in all error controls</td><td>casadi::SundialsInterface</td></tr>
<tr><td>fsens_reltol</td><td>OT_DOUBLE</td><td>Relative tolerence for the forward sensitivity solution [default: equal to reltol]</td><td>casadi::SundialsInterface</td></tr>
<tr><td>fsens_scaling_factors</td><td>OT_DOUBLEVECTOR</td><td>Scaling factor for the components if finite differences is used</td><td>casadi::SundialsInterface</td></tr>
<tr><td>fsens_sensitiviy_parameters</td><td>OT_INTVECTOR</td><td>Specifies which components will be used when estimating the sensitivity equations</td><td>casadi::SundialsInterface</td></tr>
<tr><td>grid</td><td>OT_DOUBLEVECTOR</td><td>Time grid</td><td>casadi::Integrator</td></tr>
<tr><td>interpolation_type</td><td>OT_STRING</td><td>Type of interpolation for the adjoint sensitivities</td><td>casadi::SundialsInterface</td></tr>
<tr><td>iterative_solver</td><td>OT_STRING</td><td>Iterative solver: GMRES|bcgstab|tfqmr</td><td>casadi::SundialsInterface</td></tr>
<tr><td>iterative_solverB</td><td>OT_STRING</td><td>Iterative solver for backward integration</td><td>casadi::SundialsInterface</td></tr>
<tr><td>linear_solver</td><td>OT_STRING</td><td>A custom linear solver creator function</td><td>casadi::SundialsInterface</td></tr>
<tr><td>linear_solverB</td><td>OT_STRING</td><td>A custom linear solver creator function for backwards integration [default: equal to linear_solver]</td><td>casadi::SundialsInterface</td></tr>
<tr><td>linear_solver_options</td><td>OT_DICT</td><td>Options to be passed to the linear solver</td><td>casadi::SundialsInterface</td></tr>
<tr><td>linear_solver_optionsB</td><td>OT_DICT</td><td>Options to be passed to the linear solver for backwards integration [default: equal to linear_solver_options]</td><td>casadi::SundialsInterface</td></tr>
<tr><td>linear_solver_type</td><td>OT_STRING</td><td>Type of iterative solver: user_defined|DENSE|banded|iterative</td><td>casadi::SundialsInterface</td></tr>
<tr><td>linear_solver_typeB</td><td>OT_STRING</td><td>Linear solver for backward integration</td><td>casadi::SundialsInterface</td></tr>
<tr><td>lower_bandwidth</td><td>OT_INT</td><td>Lower band-width of banded Jacobian (estimations)</td><td>casadi::SundialsInterface</td></tr>
<tr><td>lower_bandwidthB</td><td>OT_INT</td><td>lower band-width of banded jacobians for backward integration [default: equal to lower_bandwidth]</td><td>casadi::SundialsInterface</td></tr>
<tr><td>max_krylov</td><td>OT_INT</td><td>Maximum Krylov subspace size</td><td>casadi::SundialsInterface</td></tr>
<tr><td>max_krylovB</td><td>OT_INT</td><td>Maximum krylov subspace size for backward integration</td><td>casadi::SundialsInterface</td></tr>
<tr><td>max_multistep_order</td><td>OT_INT</td><td>Maximum order for the (variable-order) multistep method</td><td>casadi::SundialsInterface</td></tr>
<tr><td>max_num_steps</td><td>OT_INT</td><td>Maximum number of integrator steps</td><td>casadi::SundialsInterface</td></tr>
<tr><td>number_of_finite_elements</td><td>OT_INT</td><td>Number of finite elements</td><td>casadi::Integrator</td></tr>
<tr><td>output_t0</td><td>OT_BOOL</td><td>Output the state at the initial time</td><td>casadi::Integrator</td></tr>
<tr><td>pretype</td><td>OT_STRING</td><td>Type of preconditioning: NONE|left|right|both</td><td>casadi::SundialsInterface</td></tr>
<tr><td>pretypeB</td><td>OT_STRING</td><td>Preconditioner for backward integration</td><td>casadi::SundialsInterface</td></tr>
<tr><td>print_stats</td><td>OT_BOOL</td><td>Print out statistics after integration</td><td>casadi::Integrator</td></tr>
<tr><td>quad_err_con</td><td>OT_BOOL</td><td>Should the quadratures affect the step size control</td><td>casadi::SundialsInterface</td></tr>
<tr><td>reltol</td><td>OT_DOUBLE</td><td>Relative tolerence for the IVP solution</td><td>casadi::SundialsInterface</td></tr>
<tr><td>reltolB</td><td>OT_DOUBLE</td><td>Relative tolerence for the adjoint sensitivity solution [default: equal to reltol]</td><td>casadi::SundialsInterface</td></tr>
<tr><td>rootfinder</td><td>OT_STRING</td><td>An implicit function solver</td><td>casadi::Integrator</td></tr>
<tr><td>rootfinder_options</td><td>OT_DICT</td><td>Options to be passed to the NLP Solver</td><td>casadi::Integrator</td></tr>
<tr><td>sensitivity_method</td><td>OT_STRING</td><td>Sensitivity method: SIMULTANEOUS|staggered</td><td>casadi::SundialsInterface</td></tr>
<tr><td>steps_per_checkpoint</td><td>OT_INT</td><td>Number of steps between two consecutive checkpoints</td><td>casadi::SundialsInterface</td></tr>
<tr><td>stop_at_end</td><td>OT_BOOL</td><td>Stop the integrator at the end of the interval</td><td>casadi::SundialsInterface</td></tr>
<tr><td>t0</td><td>OT_DOUBLE</td><td>Beginning of the time horizon</td><td>casadi::Integrator</td></tr>
<tr><td>tf</td><td>OT_DOUBLE</td><td>End of the time horizon</td><td>casadi::Integrator</td></tr>
<tr><td>upper_bandwidth</td><td>OT_INT</td><td>Upper band-width of banded Jacobian (estimations)</td><td>casadi::SundialsInterface</td></tr>
<tr><td>upper_bandwidthB</td><td>OT_INT</td><td>Upper band-width of banded jacobians for backward integration [default: equal to upper_bandwidth]</td><td>casadi::SundialsInterface</td></tr>
<tr><td>use_preconditioner</td><td>OT_BOOL</td><td>Precondition an iterative solver</td><td>casadi::SundialsInterface</td></tr>
<tr><td>use_preconditionerB</td><td>OT_BOOL</td><td>Precondition an iterative solver for the backwards problem [default: equal to use_preconditioner]</td><td>casadi::SundialsInterface</td></tr>
</table>
*/
/// \endcond
/** \addtogroup general_SundialsInterface
\n
\par
<a name='options'></a><table>
<caption>List of available options</caption>
<tr><th>Id</th><th>Type</th><th>Description</th><th>Used in</th></tr>
<tr><td>abstol</td><td>OT_DOUBLE</td><td>Absolute tolerence  for the IVP solution</td><td>casadi::SundialsInterface</td></tr>
<tr><td>abstolB</td><td>OT_DOUBLE</td><td>Absolute tolerence for the adjoint sensitivity solution [default: equal to abstol]</td><td>casadi::SundialsInterface</td></tr>
<tr><td>augmented_options</td><td>OT_DICT</td><td>Options to be passed down to the augmented integrator, if one is constructed.</td><td>casadi::Integrator</td></tr>
<tr><td>disable_internal_warnings</td><td>OT_BOOL</td><td>Disable SUNDIALS internal warning messages</td><td>casadi::SundialsInterface</td></tr>
<tr><td>exact_jacobian</td><td>OT_BOOL</td><td>Use exact Jacobian information for the forward integration</td><td>casadi::SundialsInterface</td></tr>
<tr><td>exact_jacobianB</td><td>OT_BOOL</td><td>Use exact Jacobian information for the backward integration [default: equal to exact_jacobian]</td><td>casadi::SundialsInterface</td></tr>
<tr><td>expand</td><td>OT_BOOL</td><td>Replace MX with SX expressions in problem formulation [false]</td><td>casadi::Integrator</td></tr>
<tr><td>finite_difference_fsens</td><td>OT_BOOL</td><td>Use finite differences to approximate the forward sensitivity equations (if AD is not available)</td><td>casadi::SundialsInterface</td></tr>
<tr><td>fsens_abstol</td><td>OT_DOUBLE</td><td>Absolute tolerence for the forward sensitivity solution [default: equal to abstol]</td><td>casadi::SundialsInterface</td></tr>
<tr><td>fsens_err_con</td><td>OT_BOOL</td><td>include the forward sensitivities in all error controls</td><td>casadi::SundialsInterface</td></tr>
<tr><td>fsens_reltol</td><td>OT_DOUBLE</td><td>Relative tolerence for the forward sensitivity solution [default: equal to reltol]</td><td>casadi::SundialsInterface</td></tr>
<tr><td>fsens_scaling_factors</td><td>OT_DOUBLEVECTOR</td><td>Scaling factor for the components if finite differences is used</td><td>casadi::SundialsInterface</td></tr>
<tr><td>fsens_sensitiviy_parameters</td><td>OT_INTVECTOR</td><td>Specifies which components will be used when estimating the sensitivity equations</td><td>casadi::SundialsInterface</td></tr>
<tr><td>grid</td><td>OT_DOUBLEVECTOR</td><td>Time grid</td><td>casadi::Integrator</td></tr>
<tr><td>interpolation_type</td><td>OT_STRING</td><td>Type of interpolation for the adjoint sensitivities</td><td>casadi::SundialsInterface</td></tr>
<tr><td>iterative_solver</td><td>OT_STRING</td><td>Iterative solver: GMRES|bcgstab|tfqmr</td><td>casadi::SundialsInterface</td></tr>
<tr><td>iterative_solverB</td><td>OT_STRING</td><td>Iterative solver for backward integration</td><td>casadi::SundialsInterface</td></tr>
<tr><td>linear_solver</td><td>OT_STRING</td><td>A custom linear solver creator function</td><td>casadi::SundialsInterface</td></tr>
<tr><td>linear_solverB</td><td>OT_STRING</td><td>A custom linear solver creator function for backwards integration [default: equal to linear_solver]</td><td>casadi::SundialsInterface</td></tr>
<tr><td>linear_solver_options</td><td>OT_DICT</td><td>Options to be passed to the linear solver</td><td>casadi::SundialsInterface</td></tr>
<tr><td>linear_solver_optionsB</td><td>OT_DICT</td><td>Options to be passed to the linear solver for backwards integration [default: equal to linear_solver_options]</td><td>casadi::SundialsInterface</td></tr>
<tr><td>linear_solver_type</td><td>OT_STRING</td><td>Type of iterative solver: user_defined|DENSE|banded|iterative</td><td>casadi::SundialsInterface</td></tr>
<tr><td>linear_solver_typeB</td><td>OT_STRING</td><td>Linear solver for backward integration</td><td>casadi::SundialsInterface</td></tr>
<tr><td>lower_bandwidth</td><td>OT_INT</td><td>Lower band-width of banded Jacobian (estimations)</td><td>casadi::SundialsInterface</td></tr>
<tr><td>lower_bandwidthB</td><td>OT_INT</td><td>lower band-width of banded jacobians for backward integration [default: equal to lower_bandwidth]</td><td>casadi::SundialsInterface</td></tr>
<tr><td>max_krylov</td><td>OT_INT</td><td>Maximum Krylov subspace size</td><td>casadi::SundialsInterface</td></tr>
<tr><td>max_krylovB</td><td>OT_INT</td><td>Maximum krylov subspace size for backward integration</td><td>casadi::SundialsInterface</td></tr>
<tr><td>max_multistep_order</td><td>OT_INT</td><td>Maximum order for the (variable-order) multistep method</td><td>casadi::SundialsInterface</td></tr>
<tr><td>max_num_steps</td><td>OT_INT</td><td>Maximum number of integrator steps</td><td>casadi::SundialsInterface</td></tr>
<tr><td>number_of_finite_elements</td><td>OT_INT</td><td>Number of finite elements</td><td>casadi::Integrator</td></tr>
<tr><td>output_t0</td><td>OT_BOOL</td><td>Output the state at the initial time</td><td>casadi::Integrator</td></tr>
<tr><td>pretype</td><td>OT_STRING</td><td>Type of preconditioning: NONE|left|right|both</td><td>casadi::SundialsInterface</td></tr>
<tr><td>pretypeB</td><td>OT_STRING</td><td>Preconditioner for backward integration</td><td>casadi::SundialsInterface</td></tr>
<tr><td>print_stats</td><td>OT_BOOL</td><td>Print out statistics after integration</td><td>casadi::Integrator</td></tr>
<tr><td>quad_err_con</td><td>OT_BOOL</td><td>Should the quadratures affect the step size control</td><td>casadi::SundialsInterface</td></tr>
<tr><td>reltol</td><td>OT_DOUBLE</td><td>Relative tolerence for the IVP solution</td><td>casadi::SundialsInterface</td></tr>
<tr><td>reltolB</td><td>OT_DOUBLE</td><td>Relative tolerence for the adjoint sensitivity solution [default: equal to reltol]</td><td>casadi::SundialsInterface</td></tr>
<tr><td>rootfinder</td><td>OT_STRING</td><td>An implicit function solver</td><td>casadi::Integrator</td></tr>
<tr><td>rootfinder_options</td><td>OT_DICT</td><td>Options to be passed to the NLP Solver</td><td>casadi::Integrator</td></tr>
<tr><td>sensitivity_method</td><td>OT_STRING</td><td>Sensitivity method: SIMULTANEOUS|staggered</td><td>casadi::SundialsInterface</td></tr>
<tr><td>steps_per_checkpoint</td><td>OT_INT</td><td>Number of steps between two consecutive checkpoints</td><td>casadi::SundialsInterface</td></tr>
<tr><td>stop_at_end</td><td>OT_BOOL</td><td>Stop the integrator at the end of the interval</td><td>casadi::SundialsInterface</td></tr>
<tr><td>t0</td><td>OT_DOUBLE</td><td>Beginning of the time horizon</td><td>casadi::Integrator</td></tr>
<tr><td>tf</td><td>OT_DOUBLE</td><td>End of the time horizon</td><td>casadi::Integrator</td></tr>
<tr><td>upper_bandwidth</td><td>OT_INT</td><td>Upper band-width of banded Jacobian (estimations)</td><td>casadi::SundialsInterface</td></tr>
<tr><td>upper_bandwidthB</td><td>OT_INT</td><td>Upper band-width of banded jacobians for backward integration [default: equal to upper_bandwidth]</td><td>casadi::SundialsInterface</td></tr>
<tr><td>use_preconditioner</td><td>OT_BOOL</td><td>Precondition an iterative solver</td><td>casadi::SundialsInterface</td></tr>
<tr><td>use_preconditionerB</td><td>OT_BOOL</td><td>Precondition an iterative solver for the backwards problem [default: equal to use_preconditioner]</td><td>casadi::SundialsInterface</td></tr>
</table>
*/
/// \cond INTERNAL
/** \class casadi::SymbolicQr
\n
\par
<a name='options'></a><table>
<caption>List of available options</caption>
<tr><th>Id</th><th>Type</th><th>Description</th><th>Used in</th></tr>
<tr><td>ad_weight</td><td>OT_DOUBLE</td><td>Weighting factor for derivative calculation.When there is an option of either using forward or reverse mode directional derivatives, the condition ad_weight*nf&lt;=(1-ad_weight)*na is used where nf and na are estimates of the number of forward/reverse mode directional derivatives needed. By default, ad_weight is calculated automatically, but this can be overridden by setting this option. In particular, 0 means forcing forward mode and 1 forcing reverse mode. Leave unset for (class specific) heuristics.</td><td>casadi::FunctionInternal</td></tr>
<tr><td>ad_weight_sp</td><td>OT_DOUBLE</td><td>Weighting factor for sparsity pattern calculation calculation.Overrides default behavior. Set to 0 and 1 to force forward and reverse mode respectively. Cf. option \"ad_weight\".</td><td>casadi::FunctionInternal</td></tr>
<tr><td>codegen</td><td>OT_BOOL</td><td>C-code generation</td><td>casadi::SymbolicQr</td></tr>
<tr><td>compiler</td><td>OT_STRING</td><td>Compiler command to be used for compiling generated code</td><td>casadi::SymbolicQr</td></tr>
<tr><td>gather_stats</td><td>OT_BOOL</td><td>Flag to indicate whether statistics must be gathered</td><td>casadi::FunctionInternal</td></tr>
<tr><td>input_scheme</td><td>OT_STRINGVECTOR</td><td>Custom input scheme</td><td>casadi::FunctionInternal</td></tr>
<tr><td>inputs_check</td><td>OT_BOOL</td><td>Throw exceptions when the numerical values of the inputs don't make sense</td><td>casadi::FunctionInternal</td></tr>
<tr><td>jac_penalty</td><td>OT_DOUBLE</td><td>When requested for a number of forward/reverse directions,   it may be cheaper to compute first the full jacobian and then multiply with seeds, rather than obtain the requested directions in a straightforward manner. Casadi uses a heuristic to decide which is cheaper. A high value of 'jac_penalty' makes it less likely for the heurstic to chose the full Jacobian strategy. The special value -1 indicates never to use the full Jacobian strategy</td><td>casadi::FunctionInternal</td></tr>
<tr><td>jit</td><td>OT_BOOL</td><td>Use just-in-time compiler to speed up the evaluation</td><td>casadi::FunctionInternal</td></tr>
<tr><td>jit_options</td><td>OT_DICT</td><td>Options to be passed to the jit compiler.</td><td>casadi::FunctionInternal</td></tr>
<tr><td>monitor</td><td>OT_STRINGVECTOR</td><td>Monitors to be activated</td><td>casadi::FunctionInternal</td></tr>
<tr><td>output_scheme</td><td>OT_STRINGVECTOR</td><td>Custom output scheme</td><td>casadi::FunctionInternal</td></tr>
<tr><td>regularity_check</td><td>OT_BOOL</td><td>Throw exceptions when NaN or Inf appears during evaluation</td><td>casadi::FunctionInternal</td></tr>
<tr><td>user_data</td><td>OT_VOIDPTR</td><td>A user-defined field that can be used to identify the function or pass additional information</td><td>casadi::FunctionInternal</td></tr>
<tr><td>verbose</td><td>OT_BOOL</td><td>Verbose evaluation -- for debugging</td><td>casadi::FunctionInternal</td></tr>
</table>
*/
/// \endcond
/** \addtogroup plugin_Linsol_symbolicqr
\n
\par
<a name='options'></a><table>
<caption>List of available options</caption>
<tr><th>Id</th><th>Type</th><th>Description</th></tr>
<tr><td>codegen</td><td>OT_BOOL</td><td>C-code generation</td></tr>
<tr><td>compiler</td><td>OT_STRING</td><td>Compiler command to be used for compiling generated code</td></tr>
</table>
*/
/** \addtogroup general_SymbolicQr
\n
\par
<a name='options'></a><table>
<caption>List of available options</caption>
<tr><th>Id</th><th>Type</th><th>Description</th><th>Used in</th></tr>
<tr><td>ad_weight</td><td>OT_DOUBLE</td><td>Weighting factor for derivative calculation.When there is an option of either using forward or reverse mode directional derivatives, the condition ad_weight*nf&lt;=(1-ad_weight)*na is used where nf and na are estimates of the number of forward/reverse mode directional derivatives needed. By default, ad_weight is calculated automatically, but this can be overridden by setting this option. In particular, 0 means forcing forward mode and 1 forcing reverse mode. Leave unset for (class specific) heuristics.</td><td>casadi::FunctionInternal</td></tr>
<tr><td>ad_weight_sp</td><td>OT_DOUBLE</td><td>Weighting factor for sparsity pattern calculation calculation.Overrides default behavior. Set to 0 and 1 to force forward and reverse mode respectively. Cf. option \"ad_weight\".</td><td>casadi::FunctionInternal</td></tr>
<tr><td>codegen</td><td>OT_BOOL</td><td>C-code generation</td><td>casadi::SymbolicQr</td></tr>
<tr><td>compiler</td><td>OT_STRING</td><td>Compiler command to be used for compiling generated code</td><td>casadi::SymbolicQr</td></tr>
<tr><td>gather_stats</td><td>OT_BOOL</td><td>Flag to indicate whether statistics must be gathered</td><td>casadi::FunctionInternal</td></tr>
<tr><td>input_scheme</td><td>OT_STRINGVECTOR</td><td>Custom input scheme</td><td>casadi::FunctionInternal</td></tr>
<tr><td>inputs_check</td><td>OT_BOOL</td><td>Throw exceptions when the numerical values of the inputs don't make sense</td><td>casadi::FunctionInternal</td></tr>
<tr><td>jac_penalty</td><td>OT_DOUBLE</td><td>When requested for a number of forward/reverse directions,   it may be cheaper to compute first the full jacobian and then multiply with seeds, rather than obtain the requested directions in a straightforward manner. Casadi uses a heuristic to decide which is cheaper. A high value of 'jac_penalty' makes it less likely for the heurstic to chose the full Jacobian strategy. The special value -1 indicates never to use the full Jacobian strategy</td><td>casadi::FunctionInternal</td></tr>
<tr><td>jit</td><td>OT_BOOL</td><td>Use just-in-time compiler to speed up the evaluation</td><td>casadi::FunctionInternal</td></tr>
<tr><td>jit_options</td><td>OT_DICT</td><td>Options to be passed to the jit compiler.</td><td>casadi::FunctionInternal</td></tr>
<tr><td>monitor</td><td>OT_STRINGVECTOR</td><td>Monitors to be activated</td><td>casadi::FunctionInternal</td></tr>
<tr><td>output_scheme</td><td>OT_STRINGVECTOR</td><td>Custom output scheme</td><td>casadi::FunctionInternal</td></tr>
<tr><td>regularity_check</td><td>OT_BOOL</td><td>Throw exceptions when NaN or Inf appears during evaluation</td><td>casadi::FunctionInternal</td></tr>
<tr><td>user_data</td><td>OT_VOIDPTR</td><td>A user-defined field that can be used to identify the function or pass additional information</td><td>casadi::FunctionInternal</td></tr>
<tr><td>verbose</td><td>OT_BOOL</td><td>Verbose evaluation -- for debugging</td><td>casadi::FunctionInternal</td></tr>
</table>
*/
/// \cond INTERNAL
/** \class casadi::WorhpInterface
\n
\par
<a name='options'></a><table>
<caption>List of available options</caption>
<tr><th>Id</th><th>Type</th><th>Description</th><th>Used in</th></tr>
<tr><td>eval_errors_fatal</td><td>OT_BOOL</td><td>When errors occur during evaluation of f,g,...,stop the iterations</td><td>casadi::Nlpsol</td></tr>
<tr><td>expand</td><td>OT_BOOL</td><td>Replace MX with SX expressions in problem formulation [false]</td><td>casadi::Nlpsol</td></tr>
<tr><td>ignore_check_vec</td><td>OT_BOOL</td><td>If set to true, the input shape of F will not be checked.</td><td>casadi::Nlpsol</td></tr>
<tr><td>iteration_callback</td><td>OT_FUNCTION</td><td>A function that will be called at each iteration with the solver as input. Check documentation of Callback.</td><td>casadi::Nlpsol</td></tr>
<tr><td>iteration_callback_ignore_errors</td><td>OT_BOOL</td><td>If set to true, errors thrown by iteration_callback will be ignored.</td><td>casadi::Nlpsol</td></tr>
<tr><td>iteration_callback_step</td><td>OT_INT</td><td>Only call the callback function every few iterations.</td><td>casadi::Nlpsol</td></tr>
<tr><td>print_time</td><td>OT_BOOL</td><td>Print information about execution time</td><td>casadi::WorhpInterface</td></tr>
<tr><td>verbose_init</td><td>OT_BOOL</td><td>Print out timing information about the different stages of initialization</td><td>casadi::Nlpsol</td></tr>
<tr><td>warn_initial_bounds</td><td>OT_BOOL</td><td>Warn if the initial guess does not satisfy LBX and UBX</td><td>casadi::Nlpsol</td></tr>
<tr><td>worhp</td><td>OT_DICT</td><td>Options to be passed to WORHP</td><td>casadi::WorhpInterface</td></tr>
</table>
*/
/// \endcond
/** \addtogroup plugin_Nlpsol_worhp
\n
\par
<a name='options'></a><table>
<caption>List of available options</caption>
<tr><th>Id</th><th>Type</th><th>Description</th></tr>
<tr><td>print_time</td><td>OT_BOOL</td><td>Print information about execution time</td></tr>
<tr><td>worhp</td><td>OT_DICT</td><td>Options to be passed to WORHP</td></tr>
</table>
*/
/** \addtogroup general_WorhpInterface
\n
\par
<a name='options'></a><table>
<caption>List of available options</caption>
<tr><th>Id</th><th>Type</th><th>Description</th><th>Used in</th></tr>
<tr><td>eval_errors_fatal</td><td>OT_BOOL</td><td>When errors occur during evaluation of f,g,...,stop the iterations</td><td>casadi::Nlpsol</td></tr>
<tr><td>expand</td><td>OT_BOOL</td><td>Replace MX with SX expressions in problem formulation [false]</td><td>casadi::Nlpsol</td></tr>
<tr><td>ignore_check_vec</td><td>OT_BOOL</td><td>If set to true, the input shape of F will not be checked.</td><td>casadi::Nlpsol</td></tr>
<tr><td>iteration_callback</td><td>OT_FUNCTION</td><td>A function that will be called at each iteration with the solver as input. Check documentation of Callback.</td><td>casadi::Nlpsol</td></tr>
<tr><td>iteration_callback_ignore_errors</td><td>OT_BOOL</td><td>If set to true, errors thrown by iteration_callback will be ignored.</td><td>casadi::Nlpsol</td></tr>
<tr><td>iteration_callback_step</td><td>OT_INT</td><td>Only call the callback function every few iterations.</td><td>casadi::Nlpsol</td></tr>
<tr><td>print_time</td><td>OT_BOOL</td><td>Print information about execution time</td><td>casadi::WorhpInterface</td></tr>
<tr><td>verbose_init</td><td>OT_BOOL</td><td>Print out timing information about the different stages of initialization</td><td>casadi::Nlpsol</td></tr>
<tr><td>warn_initial_bounds</td><td>OT_BOOL</td><td>Warn if the initial guess does not satisfy LBX and UBX</td><td>casadi::Nlpsol</td></tr>
<tr><td>worhp</td><td>OT_DICT</td><td>Options to be passed to WORHP</td><td>casadi::WorhpInterface</td></tr>
</table>
*/
