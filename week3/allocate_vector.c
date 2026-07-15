#include <stdio.h>
#include <stdlib.h>

double *allocate_vector(int n)
{
    double *v = (double *)malloc(n * sizeof(double));
    if (v == NULL)
    {
        printf("Error: memory allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < n; i++)
        v[i] = (double)i;

    return v;
}

int main()
{

    int n = 6;

    double *v = allocate_vector(n);

    printf("Vector contents:\n");
    for (int i = 0; i < n; i++)
        printf("  v[%d] = %.1f\n", i, v[i]);

    free(v);
    v = NULL;

    printf("\nMemory freed.\n");

    return 0;
}