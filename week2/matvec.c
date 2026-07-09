#include <stdio.h>

void matvec(double *A, double *x, double *y, int n)
{
    for (int i = 0; i < n; i++)
    {
        y[i] = 0.0;
        for (int j = 0; j < n; j++)
        {
            y[i] += A[i * n + j] * x[j];
        }
    }
}

void print_vector(double *v, int n)
{
    for (int i = 0; i < n; i++)
        printf("  v[%d] = %.4f\n", i, v[i]);
    printf("\n");
}

void print_matrix(double *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("  | ");
        for (int j = 0; j < n; j++)
            printf("%8.4f ", A[i * n + j]);
        printf("|\n");
    }
    printf("\n");
}

int main()
{

    int n = 3;

    double A[9] = {
        2.0, 1.0, 0.0,
        1.0, 3.0, 1.0,
        0.0, 1.0, 2.0};

    double x[3] = {1.0, 2.0, 3.0};

    double y[3];

    matvec(A, x, y, n);

    printf("Matrix A:\n");
    print_matrix(A, n);

    printf("Vector x:\n");
    print_vector(x, n);

    printf("Result y = A*x:\n");
    print_vector(y, n);

    return 0;
}