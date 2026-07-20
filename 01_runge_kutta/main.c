#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "rk4.h"

double exponential_decay(double t, double y, void *params)
{
    double k = *(double *)params;
    (void)t;
    return -k * y;
}

double logistic_growth(double t, double y, void *params)
{
    double *p = (double *)params;
    double r = p[0];
    double K = p[1];
    (void)t;
    return r * y * (1.0 - y / K);
}

void print_table(double *t_out, double *y_out,
                 double *exact, int n_steps)
{
    printf("%-10s %-15s %-15s %-12s\n",
           "t", "RK4", "Exact", "Error");
    printf("%-10s %-15s %-15s %-12s\n",
           "----------", "---------------",
           "---------------", "------------");
    for (int i = 0; i < n_steps; i++)
    {
        double error = fabs(y_out[i] - exact[i]);
        printf("%-10.4f %-15.8f %-15.8f %-12.2e\n",
               t_out[i], y_out[i], exact[i], error);
    }
    printf("\n");
}
int main()
{

    double h = 0.1;
    double t0 = 0.0;
    double t_end = 2.0;
    int max_steps = (int)((t_end - t0) / h) + 2;

    double *t_out = (double *)malloc(max_steps * sizeof(double));
    double *y_out = (double *)malloc(max_steps * sizeof(double));
    double *exact = (double *)malloc(max_steps * sizeof(double));

    if (!t_out || !y_out || !exact)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    int n_steps;

    printf("=== Test 1: Exponential Decay ===\n");
    printf("dy/dt = -k*y,  y(0) = 2.0,  k = 1.5\n\n");

    double k = 1.5;
    double y0_1 = 2.0;

    rk4_solve(exponential_decay, y0_1, t0, t_end, h,
              t_out, y_out, &n_steps, &k);

    for (int i = 0; i < n_steps; i++)
        exact[i] = y0_1 * exp(-k * t_out[i]);

    print_table(t_out, y_out, exact, n_steps);

    printf("=== Test 2: Logistic Growth ===\n");
    printf("dy/dt = r*y*(1 - y/K),  y(0) = 10.0,  r = 0.5,  K = 100.0\n\n");

    double logistic_params[2] = {0.5, 100.0};
    double y0_2 = 10.0;
    double r = logistic_params[0];
    double K = logistic_params[1];

    rk4_solve(logistic_growth, y0_2, t0, t_end, h,
              t_out, y_out, &n_steps, logistic_params);

    for (int i = 0; i < n_steps; i++)
    {
        double C = (K - y0_2) / y0_2;
        exact[i] = K / (1.0 + C * exp(-r * t_out[i]));
    }

    print_table(t_out, y_out, exact, n_steps);

    free(t_out);
    free(y_out);
    free(exact);

    return 0;
}