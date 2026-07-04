#include <stdio.h>
#include <math.h>

double f(double x)
{
    return x * x * sin(x);
}

double f_prime(double x)
{
    return 2.0 * x * sin(x) + x * x * cos(x);
}

int main()
{
    printf("%-10s %-15s %-15s\n", "x", "f(x)", "f'(x)");
    printf("%-10s %-15s %-15s\n", "---", "---", "---");

    double x = 0.0;
    double step = 0.5;
    int num_points = 10;

    for (int i = 0; i < num_points; i++)
    {
        printf("%-10.4f %-15.8f %-15.8f\n", x, f(x), f_prime(x));
        x = x + step;
    }

    return 0;
}