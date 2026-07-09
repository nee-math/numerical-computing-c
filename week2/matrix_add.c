#include <stdio.h>

void matrix_add(double *A, double *B, double *C, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            C[i * n + j] = A[i * n + j] + B[i * n + j];
        }
    }
}

void print_matrix(double *C, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("  | ");
        for (int j = 0; j < n; j++)
            printf("%8.4f ", C[i * n + j]);
        printf("|\n");
    }
    printf("\n");
}

int main()
{

    int n = 3;

    double A[9] = {
        1.0, 2.0, 3.0,
        4.0, 5.0, 6.0,
        7.0, 8.0, 9.0};

    double B[9] = {
        9.0, 8.0, 7.0,
        6.0, 5.0, 4.0,
        3.0, 2.0, 1.0};

    double result[9];

    matrix_add(A, B, result, n);

    printf("Matrix C:\n");
    print_matrix(result, n);

    return 0;
}