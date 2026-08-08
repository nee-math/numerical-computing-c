#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "lu.h"

void generate_matrix(double *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        double row_sum = 0.0;
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                A[i * n + j] = ((double)rand() / RAND_MAX) - 0.5;
                row_sum += fabs(A[i * n + j]);
            }
        }

        A[i * n + i] = row_sum + 1.0;
    }
}

void generate_rhs(double *b, int n)
{
    for (int i = 0; i < n; i++)
        b[i] = (double)(i + 1);
}

double time_lu(int n)
{

    double *A = (double *)malloc(n * n * sizeof(double));
    double *b = (double *)malloc(n * sizeof(double));
    double *x = (double *)malloc(n * sizeof(double));
    int *piv = (int *)malloc(n * sizeof(int));

    if (!A || !b || !x || !piv)
    {
        printf("Memory allocation failed for n=%d\n", n);
        exit(1);
    }

    generate_matrix(A, n);
    generate_rhs(b, n);

    clock_t start = clock();

    lu_decompose(A, piv, n);
    lu_solve(A, piv, b, x, n);

    clock_t end = clock();

    double elapsed = (double)(end - start) / CLOCKS_PER_SEC;

    free(A);
    free(b);
    free(x);
    free(piv);

    return elapsed;
}

int main()
{

    srand(42);

    int sizes[] = {50, 100, 200, 400, 800};
    int num_sizes = 5;

    printf("LU Decomposition Scaling Analysis\n");
    printf("Expected complexity: O(n^3)\n");
    printf("Doubling n should increase time by factor ~8\n\n");

    printf("%-8s %-15s %-12s %-12s\n",
           "n", "Time (s)", "Ratio", "Expected");
    printf("%-8s %-15s %-12s %-12s\n",
           "--------", "---------------",
           "------------", "------------");

    double prev_time = 0.0;

    for (int i = 0; i < num_sizes; i++)
    {

        int n = sizes[i];

        int runs = (n <= 100) ? 5 : 1;
        double total = 0.0;

        for (int r = 0; r < runs; r++)
            total += time_lu(n);

        double avg_time = total / runs;

        if (i == 0)
        {
            printf("%-8d %-15.6f %-12s %-12s\n",
                   n, avg_time, "---", "---");
        }
        else
        {
            double ratio = avg_time / prev_time;
            printf("%-8d %-15.6f %-12.2f %-12.1f\n",
                   n, avg_time, ratio, 8.0);
        }

        prev_time = avg_time;
    }

    printf("\nRatio ≈ 8 confirms O(n^3) scaling.\n");

    return 0;
}