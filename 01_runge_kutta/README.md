# Runge-Kutta 4th Order ODE Solver

A 4th order Runge-Kutta (RK4) solver implemented in C from scratch.

## What it solves

Given an ODE of the form:

    dy/dt = f(t, y),  y(t0) = y0

the solver numerically integrates from t0 to t_end using step size h.

## Algorithm

RK4 advances the solution using four slope estimates:

    k1 = h * f(t,       y        )
    k2 = h * f(t + h/2, y + k1/2 )
    k3 = h * f(t + h/2, y + k2/2 )
    k4 = h * f(t + h,   y + k3   )

    y_new = y + (k1 + 2*k2 + 2*k3 + k4) / 6

## Files

- rk4.h / rk4.c — solver implementation
- main.c — tests against exponential decay and logistic growth
- convergence.c — convergence analysis confirming 4th order accuracy

## Building

    make

## Running

    ./solver        # runs ODE tests with exact solution comparison
    ./convergence   # runs convergence analysis

## Convergence Results

Tested on dy/dt = -1.5\*y, y(0) = 2.0 over [0, 2]:

| Step size h | Global Error | Ratio |
| ----------- | ------------ | ----- |
| 0.2000      | 6.35e-05     | ---   |
| 0.1000      | 3.51e-06     | 18.07 |
| 0.0500      | 2.06e-07     | 17.02 |
| 0.0250      | 1.25e-08     | 16.50 |
| 0.0125      | 7.70e-10     | 16.25 |

Ratio consistently ≈ 16, confirming 4th order (O(h⁴)) convergence.

## Key Concepts Demonstrated

- Function pointers for generic ODE specification
- Dynamic memory allocation for output arrays
- Verification against exact analytical solutions
- Experimental convergence analysis
