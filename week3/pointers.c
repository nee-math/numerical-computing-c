#include <stdio.h>

int main()
{
    double x = 42.5;
    double *p;
    p = &x;

    printf("Value of x:         %.1f\n", x);
    printf("Address of x:       %p\n", (void *)p);
    printf("Value via pointer:  %.1f\n", *p);

    *p = 99.9;
    printf("\nAfter *p = 99.9:\n");
    printf("Value of x is now:  %.1f\n", x);

    return 0;
}