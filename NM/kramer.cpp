#include <iostream>
#include <fstream>
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
int main() {
    ifstream m("C:/Users/cered/Documents/GitHub/LP_Labs/NM/matrix.txt");
    int n;
    m >> n;
    float **a = new float*[n];
    float *b = new float[n], *t;
    bool *f = new bool[n];
    for (int i = 0; i < n; i++) {
        a[i] = new float[n];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            m >> a[j][i];
        }
        m >> b[i];
        f[i] = 1;
    }
    m.close();
    float delta = det(a, n, f), x_i;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%5.3g ", a[j][i]);
        }
        printf("%5.3g\n", b[i]);
    }
    if (abs(delta) > 1e-5) for (int i = 0; i < n; i++) {
        t = a[i];
        a[i] = b;
        b = t;
        x_i = det(a, n, f) / delta;
        if (abs(x_i) < 1e-5) x_i = 0;
        printf("%.3g\n", x_i);
        t = a[i];
        a[i] = b;
        b = t;
    } else printf("No solutions\n");
    for (int i = 0; i < n; i++) {
        delete[] a[i];
    }
    delete[] a;
    delete[] b;
    delete[] f;
    return 0;
}