#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f1(double x) {
    return x * x * cos(2 * x) + 0.2;
}

double f2(double x) {
    return 1.0 / tan(x) - 0.1;
}

void solveChord(double (*f)(double), double a, double b, double eps, const string& taskName) {
    double x = a;
    double deltaX;
    int n = 0;

    cout << taskName << endl;

    do {
        a = x;
        x = a - (f(a) * (b - a)) / (f(b) - f(a));
        deltaX = fabs(x - a);

        cout << "n = " << n << "; x" << n << " = " << a
            << "; x" << (n + 1) << " = " << x << ";" << endl;
        cout << "f(x" << n << ") = " << f(a)
            << "; dx = " << deltaX << endl << endl;

        n++;
    } while (deltaX > eps);

    cout << "Result: x = " << x
        << "; f(x) = " << f(x) << endl << endl;
}

int main() {
    double eps = 0.005;

    solveChord(f1, 0.88, 0.98, eps, "Task 1");

    solveChord(f2, 4.6, 4.65, eps, "Task 2");

    return 0;
}