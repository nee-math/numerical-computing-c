#ifndef RK4_H
#define RK4_H

typedef double (*ODE_func)(double t, double y, void *params);
void rk4_solve(ODE_func f,
               double y0,
               double t0, double t_end,
               double h,
               double *t_out, double *y_out,
               int *n_steps,
               void *params);

#endif