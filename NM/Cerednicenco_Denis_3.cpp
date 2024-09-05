#include <iostream>
using namespace std;
float det(float **matrix, int size, bool *flag) {
    int k = 0, l = 0, q;
    float comb = 0;
    if (size % 2) q = 1; else q = -1;
    while (k < size) {
        if (flag[l]) {
            if (size == 1) return matrix[l][0];
            flag[l] = 0;
            comb += q * matrix[l][size-1] * det(matrix, size-1, flag);
            q = -q;
            flag[l] = 1;
            k++;
        }
        l++;
    }
    return comb;
}
float **x_gauss(float **matrix, float *coef, int size) {
    float del, **inverse = new float*[size];
    for (int i = 0; i < size; i++) {
        inverse[i] = new float[size];
        for (int j = 0; j < size; j++) {
            if (i == j) inverse[i][j] = 1;
            else inverse[i][j] = 0;
        }
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i != j) {
                del = matrix[j][i] / matrix[i][i];
                matrix[j][i] = 0;
                for (int k = i+1; k < size; k++) {
                    matrix[j][k] -= matrix[i][k] * del;
                }
                coef[j] -= coef[i] * del;
                for (int k = 0; k < size; k++) {
                    inverse[j][k] -= inverse[i][k] * del;
                }
            }
        }
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            inverse[i][j] /= matrix[i][i];
        }
        coef[i] /= matrix[i][i];
        matrix[i][i] = 1;
    }
    return inverse;
}
float *x_kramer(float **matrix, float *coef, int size) {
    float *x = new float[size];
    bool *f = new bool[size];
    for (int i = 0; i < size; i++) {
        f[i] = 1;
    }
    float t, delta = det(matrix, size, f);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            t = coef[j];
            coef[j] = matrix[j][i];
            matrix[j][i] = t;
        }
        x[i] = det(matrix, size, f) / delta;
        for (int j = 0; j < size; j++) {
            t = coef[j];
            coef[j] = matrix[j][i];
            matrix[j][i] = t;
        }
    }
    delete[] f;
    return x;
}
float *x_inverse(float **matrix, float *coef, int size){
    float *x = new float[size];
    for (int i = 0; i < size; i++) {
        x[i] = 0;
        for (int j = 0; j < size; j++) {
            x[i] += matrix[i][j] * coef[j];
        }
    }
    delete[] coef;
    return x;
}
float *x_zeidel(float **matrix, float *coef, int size) {
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
    } while (max_eps > 1e-3);
    return x_k;
}
int main() {
    int n = 3;
    float **a = new float*[n];
    float *b = new float[n];
    float *x, **ai;
    for (int i = 0; i < n; i++) {
        a[i] = new float[n];
    }
    cout << "Matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
        cin >> b[i];
    }
    x = x_zeidel(a, b, n);
    cout << "Zeidel:" << endl;
    for (int i = 0; i < n; i++) {
        printf("x_%d = %.3g\n", i+1, x[i]);
    }
    delete[] x;
    x = x_kramer(a, b, n);
    cout << "Kramer:" << endl;
    for (int i = 0; i < n; i++) {
        printf("x_%d = %.3g\n", i+1, x[i]);
    }
    for (int i = 0; i < n; i++) {
        x[i] = b[i];
    }
    ai = x_gauss(a, b, n);
    cout << "Gauss:" << endl;
    for (int i = 0; i < n; i++) {
        printf("x_%d = %.3g\n", i+1, b[i]);
    }
    x = x_inverse(ai, x, n);
    cout << "Inverse:" << endl;
    for (int i = 0; i < n; i++) {
        printf("x_%d = %.3g\n", i+1, x[i]);
    }
    delete[] x;
    for (int i = 0; i < n; i++) {
        delete[] a[i];
        delete[] ai[i];
    }
    delete[] a;
    delete[] b;
    delete[] ai;
    return 0;
}