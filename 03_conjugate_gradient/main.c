#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "cg.h"

void poisson_matvec(const double *x, double *y, int n, void *data)
{
    double h = 1.0 / (n + 1);
    double h2 = h * h;

    for (int i = 0; i < n; i++)
    {
        y[i] = 2.0 * x[i] / h2;
        if (i > 0)
            y[i] -= x[i - 1] / h2;
        if (i < n - 1)
            y[i] -= x[i + 1] / h2;
    }

    (void)data;
}

double exact(double x)
{
    return sin(M_PI * x);
}

double rhs(double x)
{
    return M_PI * M_PI * sin(M_PI * x);
}

int main()
{

    printf("==============================================\n");
    printf(" Conjugate Gradient Solver\n");
    printf(" Problem: -u'' = pi^2*sin(pi*x) on [0,1]\n");
    printf(" Exact solution: u(x) = sin(pi*x)\n");
    printf("==============================================\n\n");

    int grid_sizes[] = {10, 50, 100, 500};
    int num_tests = 4;

    printf("%-8s %-10s %-12s %-12s %-10s\n",
           "n", "Iters", "Rel Res", "Max Error", "Status");
    printf("%-8s %-10s %-12s %-12s %-10s\n",
           "--------", "----------",
           "------------", "------------", "----------");

    for (int t = 0; t < num_tests; t++)
    {

        int n = grid_sizes[t];
        double h = 1.0 / (n + 1);

        double *b = (double *)malloc(n * sizeof(double));
        double *x = (double *)calloc(n, sizeof(double));

        for (int i = 0; i < n; i++)
        {
            double xi = (i + 1) * h;
            b[i] = rhs(xi);
        }

        CG_Result res = cg_solve(poisson_matvec, b, x, n,
                                 10 * n, 1e-10, NULL);

        double max_err = 0.0;
        for (int i = 0; i < n; i++)
        {
            double xi = (i + 1) * h;
            double err = fabs(x[i] - exact(xi));
            if (err > max_err)
                max_err = err;
        }

        printf("%-8d %-10d %-12.2e %-12.2e %-10s\n",
               n,
               res.iterations,
               res.final_residual,
               max_err,
               res.converged ? "CONVERGED" : "FAILED");

        free(b);
        free(x);
    }

    printf("\n--- Detailed solution for n=10 ---\n\n");

    int n = 10;
    double h = 1.0 / (n + 1);

    double *b = (double *)malloc(n * sizeof(double));
    double *x = (double *)calloc(n, sizeof(double));

    for (int i = 0; i < n; i++)
    {
        double xi = (i + 1) * h;
        b[i] = rhs(xi);
    }

    cg_solve(poisson_matvec, b, x, n, 1000, 1e-10, NULL);

    printf("%-10s %-15s %-15s %-12s\n",
           "x", "CG Solution", "Exact", "Error");
    printf("%-10s %-15s %-15s %-12s\n",
           "----------", "---------------",
           "---------------", "------------");

    for (int i = 0; i < n; i++)
    {
        double xi = (i + 1) * h;
        double err = fabs(x[i] - exact(xi));
        printf("%-10.4f %-15.8f %-15.8f %-12.2e\n",
               xi, x[i], exact(xi), err);
    }

    free(b);
    free(x);

    return 0;
}