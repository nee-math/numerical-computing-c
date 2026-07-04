#include <stdio.h>
#include <math.h>

double hyp(double a, double b)
{
    return sqrt(a * a + b * b);
}

int main()
{
    double a = 3;
    double b = 6;

    printf("%.4f\n", hyp(a, b));
    printf("hyp(3, 4) = %.4f\n", hyp(3, 4));
    printf("hyp(5, 12) = %.4f\n", hyp(5, 12));
    printf("hyp(8, 15) = %.4f\n", hyp(8, 15));
    return 0;
}