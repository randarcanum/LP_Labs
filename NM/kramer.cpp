#include <iostream>
#include <fstream>
using namespace std;
float det(float **matrix, int size, bool *flag) {
    int k = 0, l = 0;
    float comb = 1;
    if (size) {
        comb = 0;
        while (k < size) {
            if (flag[l]) {
                flag[l] = 0;
                comb += ((size + k) % 2 * 2 - 1) * matrix[l][size-1] * det(matrix, size-1, flag);
                flag[l] = 1;
                k++;
            }
            l++;
        }
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
    float delta = det(a, n, f);
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
        printf("%.3g\n", det(a, n, f) / delta);
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