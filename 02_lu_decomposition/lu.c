#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "lu.h"
int lu_decompose(double *A, int *piv, int n)
{

    for (int k = 0; k < n; k++)
    {

        int pivot_row = k;
        double pivot_max = fabs(A[k * n + k]);

        for (int i = k + 1; i < n; i++)
        {
            if (fabs(A[i * n + k]) > pivot_max)
            {
                pivot_max = fabs(A[i * n + k]);
                pivot_row = i;
            }
        }

        piv[k] = pivot_row;

        if (pivot_row != k)
        {
            for (int j = 0; j < n; j++)
            {
                double tmp = A[k * n + j];
                A[k * n + j] = A[pivot_row * n + j];
                A[pivot_row * n + j] = tmp;
            }
        }

        if (fabs(A[k * n + k]) < 1e-14)
        {
            return -1;
        }

        for (int i = k + 1; i < n; i++)
        {

            A[i * n + k] /= A[k * n + k];

            for (int j = k + 1; j < n; j++)
            {
                A[i * n + j] -= A[i * n + k] * A[k * n + j];
            }
        }
    }

    return 0;
}

void lu_solve(const double *LU, const int *piv,
              const double *b, double *x, int n)
{

    double *y = (double *)malloc(n * sizeof(double));
    if (!y)
    {
        printf("Memory error\n");
        exit(1);
    }
    memcpy(y, b, n * sizeof(double));

    for (int k = 0; k < n; k++)
    {
        double tmp = y[k];
        y[k] = y[piv[k]];
        y[piv[k]] = tmp;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            y[i] -= LU[i * n + j] * y[j];
        }
    }

    memcpy(x, y, n * sizeof(double));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i + 1; j < n; j++)
        {
            x[i] -= LU[i * n + j] * x[j];
        }
        x[i] /= LU[i * n + i];
    }

    free(y);
}

double residual_norm(const double *A_orig, const double *x,
                     const double *b, int n)
{
    double norm = 0.0;
    for (int i = 0; i < n; i++)
    {
        double Ax_i = 0.0;
        for (int j = 0; j < n; j++)
            Ax_i += A_orig[i * n + j] * x[j];
        double diff = Ax_i - b[i];
        norm += diff * diff;
    }
    return sqrt(norm);
}

void print_matrix(const char *label, const double *A, int n)
{
    printf("%s:\n", label);
    for (int i = 0; i < n; i++)
    {
        printf("  | ");
        for (int j = 0; j < n; j++)
            printf("%10.5f ", A[i * n + j]);
        printf("|\n");
    }
    printf("\n");
}

void print_vector(const char *label, const double *v, int n)
{
    printf("%s:\n", label);
    for (int i = 0; i < n; i++)
        printf("  v[%d] = %10.5f\n", i, v[i]);
    printf("\n");
}