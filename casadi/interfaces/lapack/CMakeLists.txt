cmake_minimum_required(VERSION 2.8.6)
include_directories(../)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CLANG_CXX_FLAGS}")

# Linear solver using dense LU factorization in LAPACK
casadi_plugin(LinearSolver lapacklu
  lapack_lu_dense.hpp
  lapack_lu_dense.cpp
  lapack_lu_dense_meta.cpp)
casadi_plugin_link_libraries(LinearSolver lapacklu ${LAPACK_LIBRARIES})

# Linear solver using dense QR factorization in LAPACK
casadi_plugin(LinearSolver lapackqr
  lapack_qr_dense.hpp
  lapack_qr_dense.cpp
  lapack_qr_dense_meta.cpp
  )
casadi_plugin_link_libraries(LinearSolver lapackqr ${LAPACK_LIBRARIES})
