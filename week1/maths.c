#include <stdio.h>
#include <math.h>

int main()
{
    double a = 10.0;
    double b = 3.0;

    double sum = a + b;
    double difference = a - b;
    double product = a * b;
    double quotient = a / b;
    double remainder = fmod(a, b);
    double power = pow(a, b);
    double root = sqrt(a);

    printf("a + b = %.4f\n", sum);
    printf("a - b = %.4f\n", difference);
    printf("a * b = %.4f\n", product);
    printf("a / b = %.4f\n", quotient);
    printf("a mod b = %.4f\n", remainder);
    printf("a ^ b = %.4f\n", power);
    printf("sqrt(a) = %.4f\n", root);

    return 0;
}