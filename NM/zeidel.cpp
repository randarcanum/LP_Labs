#include <iostream>
#include <fstream>
using namespace std;
const float eps = 1e-3;
float *x_zeid(float **matrix, float *coef, int size) {
    float *x_k = new float[size];
    float x_k1, x_k0, max_eps;
    for (int i = 0; i < size; i++) {
        x_k[i] = 0;
    }
    do {
        max_eps = 0;
        for (int i = 0; i < size; i++) {
            x_k1 = 0;
            x_k0 = x_k[i];
            x_k[i] = -coef[i] / matrix[i][i];
            for (int j = 0; j < size; j++) {
                x_k1 -= matrix[i][j] * x_k[j];
            }
            x_k[i] = x_k1 / matrix[i][i];
            if (abs(x_k[i] - x_k0) > max_eps) max_eps = abs(x_k[i] - x_k0);
        }
    } while (max_eps > eps);
    return x_k;
}
int main() {
    ifstream m("C:/Users/cered/Documents/GitHub/LP_Labs/NM/matrix.txt");
    int n;
    m >> n;
    float **a = new float*[n];
    float *b = new float[n];
    float *x;
    for (int i = 0; i < n; i++) {
        a[i] = new float[n];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            m >> a[i][j];
        }
        m >> b[i];
    }
    m.close();
    x = x_zeid(a, b, n);
    for (int i = 0; i < n; i++) {
        printf("x_%d = %.3g\n", i+1, x[i]);
    }
    delete[] x;
    for (int i = 0; i < n; i++) {
        delete[] a[i];
    }
    delete[] a;
    delete[] b;
    return 0;
}