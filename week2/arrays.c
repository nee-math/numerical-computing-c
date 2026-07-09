#include <stdio.h>

int main()
{
    double v[5] = {2.0, 4.0, 6.0, 8.0, 10.0};

    printf("First element: v[0] = %.1f\n", v[0]);
    printf("Second element: v[1] = %.1f\n", v[1]);
    printf("Last element: v[4] = %.1f\n", v[4]);

    printf("\nAll elements:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("v[%d] = %.1f\n", i, v[i]);
    }

    v[2] = 99.0;
    printf("\nAfter changing v[2]:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("v[%d] = %.1f\n", i, v[i]);
    }

    return 0;
}