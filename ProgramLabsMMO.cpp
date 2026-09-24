#include <iostream>
#include <cmath>

using namespace std;

double f1(double x)
{
    return x * x * cos(2 * x) + 0.2;
}

double f2(double x)
{
    return 1.0 / tan(x) - 0.1;
}

double bisection(double (*f)(double), double a, double b, double eps)
{
    double c;

    while ((b - a) > eps)
    {
        c = (a + b) / 2;

        if (f(a) * f(c) <= 0)
            b = c;
        else
            a = c;
    }

    return (a + b) / 2;
}

int main()
{
    double eps = 0.005;

    // Task 1
    double a1 = 0.88;
    double b1 = 0.98;

    double root1 = bisection(f1, a1, b1, eps);

    cout << "Task 1:" << endl;
    cout << "Root = " << root1 << endl;
    cout << "f(root) = " << f1(root1) << endl;

    cout << endl;

    // Task 2
    double a2 = 4.6;
    double b2 = 4.65;

    double root2 = bisection(f2, a2, b2, eps);

    cout << "Task 2:" << endl;
    cout << "Root = " << root2 << endl;
    cout << "f(root) = " << f2(root2) << endl;

    return 0;
}