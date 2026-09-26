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

void solve(double (*f)(double), double a, double b, double eps, const string& taskName) {
    double c;
    double beg_value, end_value;
    int n = 0;

    cout << "---" << taskName << "---" << endl;

    do {
        c = (a + b) / 2.0;
        beg_value = f(a);
        end_value = f(c);

        if (beg_value * end_value <= 0)
            b = c;
        else
            a = c;

        cout << n << ": a = " << a << "; b = " << b << "; c = " << c << endl;
        cout << "beg: " << beg_value << " end: " << end_value << endl << endl;
        n++;
    } while (abs(a - b) > eps);

    cout << "Result: " << end_value << "; c = " << c << endl << endl;
}

int main() {
    double eps = 0.005;

    double a1 = 0.88;
    double b1 = 0.98;
    solve(f1, a1, b1, eps, "Task 1");

    double a2 = 4.6;
    double b2 = 4.65;
    solve(f2, a2, b2, eps, "Task 2");

    return 0;
}