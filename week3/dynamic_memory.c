#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 5;
    double *v = (double *)malloc(n * sizeof(double));
    if (v == NULL)
    {
        printf("Error: memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
        v[i] = (double)i * 3.0;

    printf("Dynamic array:\n");
    for (int i = 0; i < n; i++)
        printf("  v[%d] = %.1f\n", i, v[i]);

    free(v);
    v = NULL;

    printf("\nMemory freed successfully.\n");

    return 0;
}