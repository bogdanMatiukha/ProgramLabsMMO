#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f1(double x) {
    return x * x * cos(2 * x) + 0.2;
}

double df1(double x) {
    return 2 * x * cos(2 * x) - 2 * x * x * sin(2 * x);
}

double f2(double x) {
    return 1.0 / tan(x) - 0.1;
}

double df2(double x) {
    return -1.0 / (sin(x) * sin(x));
}

void solveCombined(double (*f)(double), double (*df)(double), double a, double b, double eps, const string& taskName) {
    double z_prev, z_cur = a;
    double x_prev, x_cur = a;
    double dx;
    int n = 0;

    cout << "=== " << taskName << " ===" << endl;
    cout << fixed << setprecision(6);

    do {
        x_prev = x_cur;
        z_prev = z_cur;

        x_cur = x_prev - f(x_prev) / df(x_prev);

        z_cur = z_prev - (f(z_prev) * (b - z_prev)) / (f(b) - f(z_prev));

        dx = fabs(x_cur - z_cur);

        cout << "n = " << n
            << " | x (dotychni) = " << x_cur
            << " | z (khordy) = " << z_cur
            << " | dx = " << dx << endl;

        n++;
    } while (dx > eps);

    double root = (x_cur + z_cur) / 2.0;
    cout << "Result: x = " << root << "; f(x) = " << f(root) << endl << endl;
}

int main() {
    const double eps = 0.005;

    solveCombined(f1, df1, 0.88, 0.98, eps, "Task 1");
    solveCombined(f2, df2, 4.6, 4.65, eps, "Task 2");

    return 0;
}