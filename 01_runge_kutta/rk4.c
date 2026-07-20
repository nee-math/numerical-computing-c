#include <stdlib.h>
#include "rk4.h"

void rk4_solve(ODE_func f,
               double y0,
               double t0, double t_end,
               double h,
               double *t_out, double *y_out,
               int *n_steps,
               void *params)
{
    double t = t0;
    double y = y0;
    int step = 0;

    t_out[step] = t;
    y_out[step] = y;

    while (t < t_end - 1e-12)
    {

        double k1 = h * f(t, y, params);
        double k2 = h * f(t + h / 2.0, y + k1 / 2.0, params);
        double k3 = h * f(t + h / 2.0, y + k2 / 2.0, params);
        double k4 = h * f(t + h, y + k3, params);

        y = y + (k1 + 2.0 * k2 + 2.0 * k3 + k4) / 6.0;
        t = t + h;
        step++;

        t_out[step] = t;
        y_out[step] = y;
    }

    *n_steps = step + 1;
}