#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cout << "Введите количество уравнений: ";
    cin >> n;

    // объявляем исходную систему уравнений
    double a[n][n+1];
    for (int i = 0; i < n; i++) {
        cout << "Введите коэффициенты для " << i + 1 << " уравнения:" << endl;
        for (int j = 0; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    // прямой ход метода Гаусса
    for (int k = 0; k < n; k++) {
        for (int i = k + 1; i < n; i++) {
            double coeff = a[i][k] / a[k][k];
            for (int j = k + 1; j <= n; j++) {
                a[i][j] = a[i][j] - coeff * a[k][j];
            }
        }
    }
    // обратный ход метода Гаусса
    double x[n];
    for (int i = n - 1; i >= 0; i--) {
        x[i] = a[i][n];
        for (int j = i + 1; j < n; j++) {
            x[i] = x[i] - a[i][j] * x[j];
        }
        x[i] = x[i] / a[i][i];
    }

    // вывод решения на экран
    for (int i = 0; i < n; i++) {
        cout << "x" << i << " = " << x[i] << endl;
    }
    return 0;
}