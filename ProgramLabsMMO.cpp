#include <iostream>
#include <cmath>

using namespace std;

double det4(double mat[4][4]) {
    double a[4][4];
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            a[i][j] = mat[i][j];

    double det = 1.0;
    for (int k = 0; k < 4; k++) {
        for (int i = k + 1; i < 4; i++) {
            double koef = a[i][k] / a[k][k];
            for (int j = k; j < 4; j++) {
                a[i][j] -= koef * a[k][j];
            }
        }
        det *= a[k][k];
    }
    return det;
}

int main() {

    double m[4][5] = {
        { 10,  2, -1,  1,  15 },
        { 2, -8,  2, -1, -14 },
        { 1,  1,  9, -2,   8 },
        { -1,  1,  2,  7,  17 }
    };

    double eps = 0.0001;

    // 1. Метод Крамера
    double baseMat[4][4];
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            baseMat[i][j] = m[i][j];

    double dMain = det4(baseMat);
    double xCramer[4] = { 0 };

    for (int col = 0; col < 4; col++) {
        double tempMat[4][4];
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                tempMat[i][j] = (j == col) ? m[i][4] : m[i][j];
            }
        }
        xCramer[col] = det4(tempMat) / dMain;
    }

    cout << "1. Cramer's method: ";
    for (int i = 0; i < 4; i++) cout << xCramer[i] << "  ";
    cout << endl;

    // 2. Метод Гауса
    double a[4][5];
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 5; j++)
            a[i][j] = m[i][j];

    // Прямий хід
    for (int k = 0; k < 4; k++) {
        for (int i = k + 1; i < 4; i++) {
            double koef = a[i][k] / a[k][k];
            for (int j = k; j < 5; j++) {
                a[i][j] -= koef * a[k][j];
            }
        }
    }

    // Зворотний хід
    double xGauss[4] = { 0 };
    for (int i = 3; i >= 0; i--) {
        double sum = a[i][4];
        for (int j = i + 1; j < 4; j++) {
            sum -= a[i][j] * xGauss[j];
        }
        xGauss[i] = sum / a[i][i];
    }

    cout << "2. Gauss method: ";
    for (int i = 0; i < 4; i++) cout << xGauss[i] << "  ";
    cout << endl;

    // 3. Метод простих ітерацій
    double xOld[4] = { 0 }, xNew[4] = { 0 };
    int iter = 0;
    while (true) {
        iter++;
        for (int i = 0; i < 4; i++) {
            double sum = m[i][4];
            for (int j = 0; j < 4; j++) {
                if (i != j) sum -= m[i][j] * xOld[j];
            }
            xNew[i] = sum / m[i][i];
        }

        double maxDiff = 0;
        for (int i = 0; i < 4; i++) {
            if (fabs(xNew[i] - xOld[i]) > maxDiff)
                maxDiff = fabs(xNew[i] - xOld[i]);
            xOld[i] = xNew[i];
        }
        if (maxDiff < eps) break;
    }

    cout << "3. Simple iteration method (" << iter << " iter.): ";
    for (int i = 0; i < 4; i++) cout << xNew[i] << "  ";
    cout << endl;

    return 0;
}