#include <stdio.h>
void try_to_double_copy(double x)
{
    x = x * 2.0;
    printf("Inside copy function : x = %.1f\n", x);
}

void double_in_place(double *x)
{
    *x = *x * 2.0;
    printf("Inside pointer function: *x = %.1f\n", *x);
}

void fill_array(double *v, int n, double value)
{
    for (int i = 0; i < n; i++)
        v[i] = value;
}

int main()
{
    double a = 5.0;

    printf("Before copy function: a = %.1f\n", a);
    try_to_double_copy(a);
    printf("After copy function:  a = %.1f\n\n", a);

    printf("Before pointer function: a = %.1f\n", a);
    double_in_place(&a);
    printf("After pointer function:  a = %.1f\n\n", a);

    double v[5];
    fill_array(v, 5, 7.0);

    printf("Filled array:\n");
    for (int i = 0; i < 5; i++)
        printf("  v[%d] = %.1f\n", i, v[i]);
}