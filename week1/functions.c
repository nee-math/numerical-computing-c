#include <stdio.h>
#include <math.h>

double circle_area(double radius)
{
    double pi = 3.14159265358979;
    return pi * radius * radius;
}

double distance(double x1, double y1, double x2, double y2)
{
    double dx = x2 - x1;
    double dy = y2 - y1;
    return sqrt(pow(dx, 2) + pow(dy, 2));
}
void print_result(double value)
{
    printf("Result: %.6f\n", value);
}

int main()
{
    double r = 5.0;
    double area = circle_area(r);
    printf("Area of circle with radius %.1f = %.6f\n", r, area);

    double d = distance(0.0, 0.0, 3.0, 4.0);
    printf("Distance from (0,0) to (3,4) = %.6f\n", d);

    print_result(circle_area(2.5));

    return 0;
}