#include <stdio.h>
#include <stdlib.h>

double *allocate_matrix(int n)
{
    double *A = (double *)malloc(n * n * sizeof(double));
    if (A == NULL)
    {
        printf("Error: matrix allocation failed\n");
        exit(1);
    }
    return A;
}

void free_matrix(double *A)
{
    free(A);
}

void zero_matrix(double *A, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            A[i * n + j] = 0.0;
}

void print_matrix(double *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" | ");
        for (int j = 0; j < n; j++)
            printf("%8.4f", A[i * n + j]);
        printf("|\n");
    }
    printf("\n");
}

void fill_matrix(double *A, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            A[i * n + j] = (double)(i * n + j + 1);
}

int main()
{
    int n = 4;
    printf("Creating a %d x %d matrix dynamically...\n\n", n, n);

    double *A = allocate_matrix(n);

    zero_matrix(A, n);
    printf("Zero matrix:\n");
    print_matrix(A, n);

    fill_matrix(A, n);
    printf("Filled matrix:\n");
    print_matrix(A, n);

    double *C = allocate_matrix(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i * n + j] = A[i * n + j] + A[j * n + i];

    printf("A + transpose of A (symmetric):\n");
    print_matrix(C, n);

    free_matrix(A);
    free_matrix(C);

    printf("All memory freed.\n");

    return 0;
}