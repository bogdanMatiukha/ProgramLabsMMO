#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

double f(double x, double y) {
    return 5.0 * x - 3.0 * y;
}

double exactSolution(double x) {
    return (5.0 / 3.0) * x - (5.0 / 9.0) + (14.0 / 9.0) * exp(-3.0 * x);
}

int main() {
    const double x0 = 0.0;
    const double xEnd = 0.2;
    const double y0 = 1.0;
    const double h = 0.05;

    int n = static_cast<int>(llround((xEnd - x0) / h));

    double x = x0;
    double y = y0;

    cout << fixed << setprecision(6);
    cout << "i   x         k1          k2          k3          k4          dy          y_rk4       y_exact     err\n";
    cout << "------------------------------------------------------------------------------------------------------------\n";

    for (int i = 0; i < n; ++i) {
        double k1 = h * f(x, y);
        double k2 = h * f(x + 0.5 * h, y + 0.5 * k1);
        double k3 = h * f(x + 0.5 * h, y + 0.5 * k2);
        double k4 = h * f(x + h, y + k3);
        double dy = (k1 + 2.0 * k2 + 2.0 * k3 + k4) / 6.0;

        double yEx = exactSolution(x);
        double err = fabs(y - yEx);

        cout << setw(2) << i << "  "
            << setw(7) << setprecision(2) << x << "  "
            << setprecision(6)
            << setw(10) << k1 << "  "
            << setw(10) << k2 << "  "
            << setw(10) << k3 << "  "
            << setw(10) << k4 << "  "
            << setw(10) << dy << "  "
            << setw(10) << y << "  "
            << setw(10) << yEx << "  "
            << scientific << setprecision(2) << err
            << fixed << "\n";

        y += dy;
        x = x0 + (i + 1) * h;
    }

    double yExEnd = exactSolution(x);
    double errEnd = fabs(y - yExEnd);
    cout << setw(2) << n << "  "
        << setw(7) << setprecision(2) << x << "  "
        << setprecision(6)
        << "     -           -           -           -           -      "
        << setw(10) << y << "  "
        << setw(10) << yExEnd << "  "
        << scientific << setprecision(2) << errEnd << "\n";

    return 0;
}