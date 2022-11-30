#include <stdio.h>

double f(double x)
{
    return 4 / (1 + x * x);
}

double trar(double (*f)(double), double a, double b, long int N)
{
    double delta = (b - a) / N;
    double result = (a + b) * delta / 2;
    for (int interval = 1; interval < N; interval++)
    {
        result += f(interval * delta + a) * delta;
    }
    return result;
}

int main(void)
{
    long int N = 1000000;
    int ub = 1;
    int lb = 0;
    printf("The result is %f\n", trar(f, lb, ub, N));
}