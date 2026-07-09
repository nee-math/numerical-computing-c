#include <stdio.h>
#include <math.h>

int main()
{
    int n = 5;

    double a[5] = {1.0, 2.0, 3.0, 4.0, 5.0};
    double b[5] = {10.0, 20.0, 30.0, 40.0, 50.0};
    double result[5];

    for (int i = 0; i < n; i++)
        result[i] = a[i] + b[i];

    printf("Vector addition:\n");
    for (int i = 0; i < n; i++)
        printf("  result[%d] = %.1f\n", i, result[i]);

    double dot = 0.0;
    for (int i = 0; i < n; i++)
        dot += a[i] * b[i];

    printf("\nDot product = %.1f\n", dot);

    double norm = 0.0;
    for (int i = 0; i < n; i++)
        norm += a[i] * a[i];
    norm = sqrt(norm);

    printf("Norm of a = %.6f\n", norm);

    double scalar = 3.0;
    printf("\nScaling a by %.1f:\n", scalar);
    for (int i = 0; i < n; i++)
        printf(" %.1f * a[%d] = %.1f\n", scalar, i, scalar * a[i]);

    return 0;
}