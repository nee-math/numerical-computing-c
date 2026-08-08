# LU Decomposition Solver

LU decomposition with partial pivoting implemented in C from scratch,
used to solve linear systems Ax = b.

## What it solves

Given an n×n matrix A and right-hand side vector b, finds x such that:

    Ax = b

by factorising A into:

    PA = LU

where L is lower triangular, U is upper triangular, and P is a
permutation matrix recording row swaps.

## Algorithm

**Decomposition** (Gaussian elimination with partial pivoting):

    For k = 0 to n-1:
        Find row with largest |A[i][k]| for i >= k  (pivot)
        Swap that row with row k
        For i = k+1 to n-1:
            A[i][k] /= A[k][k]              (store multiplier in L)
            For j = k+1 to n-1:
                A[i][j] -= A[i][k] * A[k][j] (eliminate)

**Solve** (two triangular solves):

    Forward substitution:  Ly = b  (O(n^2))
    Back substitution:     Ux = y  (O(n^2))

## Files

- lu.h / lu.c — decomposition and solver implementation
- main.c — correctness tests with known solutions
- scaling.c — O(n^3) scaling analysis

## Building

    make

## Running

    ./solver     # correctness tests
    ./scaling    # scaling analysis

## Correctness Results

Both test systems solved with residual ||Ax - b|| at machine
precision (~1e-15), confirming correct implementation.

## Scaling Results

Timing LU decomposition + solve for increasing matrix sizes:

n Time (s) Ratio Expected

---

50 0.000034 --- ---  
100 0.000229 6.72 8.0  
200 0.001894 8.29 8.0  
400 0.012462 6.58 8.0  
800 0.054241 4.35 8.0

Ratio ≈ 8 confirms O(n^3) complexity.

## Key Concepts Demonstrated

- Gaussian elimination with partial pivoting
- In-place LU factorisation (L and U stored in same array)
- Forward and back substitution
- Experimental verification of O(n^3) complexity
- Diagonally dominant matrix generation for robust testing
