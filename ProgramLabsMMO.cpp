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

double phi1(double x) {
    return x + 0.4 * f1(x);
}

double phi2(double x) {
    return x + 0.5 * f2(x);
}

void solve(double (*f)(double), double (*phi)(double), double x, double eps, const string& taskName) {
    double x_next;
    int n = 0;

    cout << taskName << endl;

    do {
        x_next = phi(x);

        cout << n << ": x = " << x
            << "; x_next = " << x_next << endl;
        cout << "f(x) = " << f(x) << endl << endl;

        n++;

        if (abs(x_next - x) <= eps)
            break;

        x = x_next;

    } while (true);

    cout << "Result: x = " << x_next
        << "; f(x) = " << f(x_next) << endl << endl;
}

int main() {
    double eps = 0.005;

    double x1 = 0.88;
    solve(f1, phi1, x1, eps, "Task 1");

    double x2 = 4.6;
    solve(f2, phi2, x2, eps, "Task 2");

    return 0;
}