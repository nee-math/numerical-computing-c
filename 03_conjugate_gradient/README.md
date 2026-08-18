# Conjugate Gradient Solver

An iterative Conjugate Gradient (CG) solver implemented in C from
scratch, tested on the 1D Poisson equation.

## What it solves

Given a symmetric positive definite (SPD) system Ax = b, finds x
iteratively without ever storing or factorising A.

## Algorithm

Starting from x0 = 0:

    r0 = b,  p0 = r0

    For k = 0, 1, 2, ...:
        alpha = (rk · rk) / (pk · A*pk)
        x     = x + alpha * p
        r     = r - alpha * A*p
        beta  = (r_new · r_new) / (rk · rk)
        p     = r + beta * p

    Stop when ||r|| / ||r0|| < tolerance

## Test Problem: 1D Poisson Equation

    -u''(x) = pi^2 * sin(pi*x)  on [0,1]
    u(0) = u(1) = 0
    Exact solution: u(x) = sin(pi*x)

The matrix A is never stored — its action is computed directly
(matrix-free design).

## Files

- cg.h / cg.c — CG solver and vector utilities
- main.c — solver tests across multiple grid sizes
- convergence.c — O(h^2) discretisation convergence analysis

## Building

    make

## Running

    ./solver        # solution tests with exact comparison
    ./convergence   # convergence analysis

## Convergence Results

n h Max Error Ratio Expected

---

10 0.090909 6.76e-03 --- ---  
20 0.047619 1.86e-03 3.63 4.0  
40 0.024390 4.89e-04 3.81 4.0  
80 0.012346 1.25e-04 3.90 4.0  
160 0.006211 3.17e-05 3.95 4.0

Ratio ≈ 4 confirms O(h^2) convergence of the finite difference
discretisation.

## Key Concepts Demonstrated

- Iterative solver design with convergence tolerance
- Matrix-free implementation using function pointers
- Verification against exact analytical solution
- O(h^2) convergence analysis of PDE discretisation
- Krylov subspace methods for SPD systems
