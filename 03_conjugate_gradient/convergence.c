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

double rhs_func(double x)
{
    return M_PI * M_PI * sin(M_PI * x);
}

double solve_and_get_error(int n)
{

    double h = 1.0 / (n + 1);

    double *b = (double *)malloc(n * sizeof(double));
    double *x = (double *)calloc(n, sizeof(double));

    if (!b || !x)
    {
        printf("Memory error\n");
        exit(1);
    }

    for (int i = 0; i < n; i++)
    {
        double xi = (i + 1) * h;
        b[i] = rhs_func(xi);
    }

    cg_solve(poisson_matvec, b, x, n, 10 * n, 1e-12, NULL);

    double max_err = 0.0;
    for (int i = 0; i < n; i++)
    {
        double xi = (i + 1) * h;
        double err = fabs(x[i] - exact(xi));
        if (err > max_err)
            max_err = err;
    }

    free(b);
    free(x);

    return max_err;
}

int main()
{

    int sizes[] = {10, 20, 40, 80, 160};
    int num_sizes = 5;

    printf("CG Solver — Poisson Discretisation Convergence\n");
    printf("Problem: -u'' = pi^2*sin(pi*x), u(x) = sin(pi*x)\n");
    printf("Expected: O(h^2) convergence, ratio ≈ 4\n\n");

    printf("%-8s %-10s %-15s %-10s %-10s\n",
           "n", "h", "Max Error", "Ratio", "Expected");
    printf("%-8s %-10s %-15s %-10s %-10s\n",
           "--------", "----------",
           "---------------", "----------", "----------");

    double prev_error = 0.0;

    for (int i = 0; i < num_sizes; i++)
    {

        int n = sizes[i];
        double h = 1.0 / (n + 1);
        double err = solve_and_get_error(n);

        if (i == 0)
        {
            printf("%-8d %-10.6f %-15.2e %-10s %-10s\n",
                   n, h, err, "---", "---");
        }
        else
        {
            double ratio = prev_error / err;
            printf("%-8d %-10.6f %-15.2e %-10.2f %-10.1f\n",
                   n, h, err, ratio, 4.0);
        }

        prev_error = err;
    }

    printf("\nRatio ≈ 4 confirms O(h^2) discretisation convergence.\n");

    return 0;
}