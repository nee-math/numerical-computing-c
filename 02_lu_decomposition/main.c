#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "lu.h"

int main()
{

    printf("==============================================\n");
    printf(" Test 1: 3x3 Linear System\n");
    printf("==============================================\n\n");

    int n1 = 3;

    double A1[9] = {
        2.0, 1.0, 1.0,
        4.0, 3.0, 3.0,
        8.0, 7.0, 9.0};

    double b1[3] = {1.0, 1.0, 1.0};

    double A1_orig[9];
    memcpy(A1_orig, A1, 9 * sizeof(double));

    print_matrix("Matrix A", A1, n1);
    print_vector("Vector b", b1, n1);

    int *piv1 = (int *)malloc(n1 * sizeof(int));

    int status = lu_decompose(A1, piv1, n1);

    if (status == -1)
    {
        printf("Error: matrix is singular\n");
        return 1;
    }

    double x1[3];
    lu_solve(A1, piv1, b1, x1, n1);

    print_vector("Solution x", x1, n1);

    double res1 = residual_norm(A1_orig, x1, b1, n1);
    printf("Residual ||Ax - b|| = %.2e\n", res1);
    printf("(Should be close to machine epsilon ~1e-15)\n\n");

    free(piv1);

    printf("==============================================\n");
    printf(" Test 2: 4x4 System with Known Solution\n");
    printf("==============================================\n\n");

    int n2 = 4;

    double A2[16] = {
        4.0, 3.0, 2.0, 1.0,
        3.0, 4.0, 3.0, 2.0,
        2.0, 3.0, 4.0, 3.0,
        1.0, 2.0, 3.0, 4.0};

    double x_known[4] = {1.0, 2.0, 3.0, 4.0};

    double b2[4] = {0.0, 0.0, 0.0, 0.0};
    for (int i = 0; i < n2; i++)
        for (int j = 0; j < n2; j++)
            b2[i] += A2[i * n2 + j] * x_known[j];

    double A2_orig[16];
    memcpy(A2_orig, A2, 16 * sizeof(double));

    print_matrix("Matrix A", A2, n2);
    print_vector("Vector b (= A * [1,2,3,4])", b2, n2);
    print_vector("Known solution x", x_known, n2);

    int *piv2 = (int *)malloc(n2 * sizeof(int));
    lu_decompose(A2, piv2, n2);

    double x2[4];
    lu_solve(A2, piv2, b2, x2, n2);

    print_vector("Computed solution x", x2, n2);

    double res2 = residual_norm(A2_orig, x2, b2, n2);
    printf("Residual ||Ax - b|| = %.2e\n", res2);
    printf("(Should be close to machine epsilon ~1e-15)\n\n");

    double max_err = 0.0;
    for (int i = 0; i < n2; i++)
    {
        double err = fabs(x2[i] - x_known[i]);
        if (err > max_err)
            max_err = err;
    }
    printf("Max error vs known solution = %.2e\n\n", max_err);

    free(piv2);

    return 0;
}