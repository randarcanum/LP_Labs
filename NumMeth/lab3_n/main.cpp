#include <iostream>
#include <iomanip>
using namespace std;
// Определитель матрицы 2х2
double det2(double m[2][2]) {
    return m[0][0]*m[1][1] - m[0][1]*m[1][0];
}
// Определитель матрицы 3х3
double det3(double m[3][3]) {
    return m[0][0]*m[1][1]*m[2][2] + m[0][1]*m[1][2]*m[2][0] + m[0][2]*m[1][0]*m[2][1] - m[0][2]*m[1][1]*m[2][0] - m[0][1]*m[1][0]*m[2][2] - m[0][0]*m[1][2]*m[2][1];
}
int main() {
    // Два массива данных
    double X[8] = {4.5, 5.0, 5.5, 6.0, 6.5, 7.0, 7.5, 8.0};
    double Y[8] = {7.7, 9.4, 11.4, 13.6, 15.6, 18.6, 21.2, 24.1};
    // Длина массивов
    int n = 8;
    // Переменные для сумм + вспомогательные
    double x = 0, y = 0, y2 = 0, x2 = 0, x3 = 0, x4 = 0, xy = 0, x2y = 0, det0, razn, otk1 = 0, otk2 = 0;
    // Массивы для коэффициентов функций
    // f1 - линейная
    // f2 - параболическая
    double f1[2], f2[3];
    // Вычисления сумм
    for (int i = 0; i < n; i++) {
        x += X[i];
        x2 += X[i]*X[i];
        x3 += X[i]*X[i]*X[i];
        x4 += X[i]*X[i]*X[i]*X[i];
        y += Y[i];
        xy += Y[i]*X[i];
        x2y += Y[i]*X[i]*X[i];
    }
    // Составление матрицы
    double a1[2][2] = {{x, x2}, {n, x}};
    // Составление столбца свободных членов
    double b1[2] = {xy, y};
    // Метод Крамера
    det0 = det2(a1);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            swap(a1[j][i], b1[j]);
        }
        // Вычисление коэффициентов линейной функции
        f1[i] = det2(a1) / det0;
        for (int j = 0; j < 2; j++) {
            swap(a1[j][i], b1[j]);
        }
    }
    // То же самое для параболической аппроксимации
    double a2[3][3] = {{x2, x3, x4}, {x, x2, x3}, {n, x, x2}};
    double b2[3] = {x2y, xy, y};
    det0 = det3(a2);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            swap(a2[j][i], b2[j]);
        }
        f2[i] = det3(a2) / det0;
        for (int j = 0; j < 3; j++) {
            swap(a2[j][i], b2[j]);
        }
    }
    // Вычисление суммы квадратов отклонений для обеих функций
    for (int i = 0; i < n; i++) {
        razn = f1[0] + f1[1]*X[i] - Y[i];
        otk1 += razn*razn;
        razn = f2[0] + f2[1]*X[i] + f2[2]*X[i]*X[i] - Y[i];
        otk2 += razn*razn;
    }
    cout << setprecision(3);
    cout << "lin: f1(x) = " << f1[0] << " + " << f1[1] << " x " << endl;
    cout << "summa kv. otkl.: " << otk1 << endl;
    cout << "par: f2(x) = " << f2[0] << " + " << f2[1] << " x " << " + " << f2[2] << " x^2 " << endl;
    cout << "summa kv. otkl.: " << otk2 << endl;
    return 0;
}