#include <stdio.h>

void print_matrix(double *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" | ");
        for (int j = 0; j < n; j++)
        {
            printf("%8.4f ", A[i * n + j]);
        }
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

    printf("MatrixA:\n");
    print_matrix(A, n);

    printf("A[0][0] = %.1f\n", A[0 * n + 0]); // row 0, col 0
    printf("A[1][2] = %.1f\n", A[1 * n + 2]); // row 1, col 2
    printf("A[2][1] = %.1f\n", A[2 * n + 1]); // row 2, col 1

    // Create the identity matrix (1s on diagonal, 0s everywhere else)
    double I[9];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            I[i * n + j] = (i == j) ? 1.0 : 0.0;

    printf("\nIdentity matrix:\n");
    print_matrix(I, n);

    return 0;
};