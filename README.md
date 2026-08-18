# Numerical Computing in C

Three numerical methods implemented from scratch in C, built as
preparation for graduate study in High Performance Computing.

## Projects

### 1. Runge-Kutta 4th Order ODE Solver

`01_runge_kutta/`

Solves ODEs of the form dy/dt = f(t, y) using the classical RK4
algorithm. Verified against exact solutions with confirmed O(h^4)
convergence.

### 2. LU Decomposition Solver

`02_lu_decomposition/`

Solves linear systems Ax = b via Gaussian elimination with partial
pivoting. Residuals at machine precision (~1e-15). Confirmed O(n^3)
scaling.

### 3. Conjugate Gradient Solver

`03_conjugate_gradient/`

Iterative solver for SPD systems using a matrix-free design. Tested
on the 1D Poisson equation. Confirmed O(h^2) discretisation
convergence.

## Build

Each project has its own Makefile. From any project directory:

    make        # build
    make clean  # remove compiled files

## Skills Demonstrated

- Numerical methods: RK4, LU decomposition, Conjugate Gradient
- C programming: pointers, dynamic memory, function pointers, structs
- Software engineering: header files, Makefiles, modular design
- Verification: convergence analysis, scaling analysis, exact solution
  comparison
