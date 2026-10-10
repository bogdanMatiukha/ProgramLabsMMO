#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f1(double x) {
    return x * x * cos(2 * x) + 0.2;
}

double f1_derivative(double x) {
    return 2 * x * cos(2 * x) - 2 * x * x * sin(2 * x);
}

double f2(double x) {
    return 1.0 / tan(x) - 0.1;
}

double f2_derivative(double x) {
    return -1.0 / (sin(x) * sin(x));
}

void solve(double (*f)(double), double (*df)(double), double x, double eps, const string& taskName) {
    double x_next;
    double fx, dfx, deltaX;
    int n = 0;

    cout << taskName << endl;

    do {
        fx = f(x);
        dfx = df(x);

        x_next = x - fx / dfx;
        deltaX = fabs(x_next - x);

        cout << "n = " << n << "; x" << n << " = " << x
            << "; x" << n + 1 << " = " << x_next << ";" << endl;
        cout << "f(x) = " << fx
            << "; f'(x) = " << dfx
            << "; dx = " << deltaX << endl << endl;

        x = x_next;
        n++;

    } while (deltaX > eps);

    cout << "Result: x = " << x
        << "; f(x) = " << f(x) << endl << endl;
}

int main() {
    double eps = 0.005;

    double x1 = 0.88;
    solve(f1, f1_derivative, x1, eps, "Task 1");

    double x2 = 4.6;
    solve(f2, f2_derivative, x2, eps, "Task 2");

    return 0;
}