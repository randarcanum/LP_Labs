#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ifstream m("C:/Users/cered/Documents/GitHub/LP_Labs/NM/matrix.txt");
    float t, *swp;
    int n, max, sol = 0;
    m >> n;
    int nz = n-1;
    float **a = new float*[n];
    float *b = new float[n];
    for (int i = 0; i < n; i++) {
        a[i] = new float[n];
        for (int j = 0; j < n; j++) {
            m >> a[i][j];
        }
        m >> b[i];
    }
    m.close();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%5.3g ", a[i][j]);
        }
        printf("%5.3g\n", b[i]);
    }
    printf("\n");
    for (int i = 0; i < n; i++, sol++) {
        do {
            max = i;
            for (int j = i+1; j < n; j++) {
                if (abs(a[max][i]) < abs(a[j][i])) max = j;
            }
            swp = a[i];
            a[i] = a[max];
            a[max] = swp;
            t = b[i];
            b[i] = b[max];
            b[max] = t;
            if (a[i][i] == 0 && nz > i) {
                for (int j = 0; j < n; j++) {
                    t = a[j][nz];
                    a[j][nz] = a[j][i];
                    a[j][i] = t;
                }
                nz--;
            }
        } while (a[i][i] == 0 && nz > i);
        if (a[i][i]) {
            for (int k = n-1; k > i; k--) {
                a[i][k] /= a[i][i];
            }
            b[i] /= a[i][i];
            if (abs(b[i]) < 1e-5) b[i] = 0;
            a[i][i] = 1;
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    t = a[j][i] / a[i][i];
                    a[j][i] = 0;
                    for (int k = i+1; k < n; k++) {
                        a[j][k] -= a[i][k] * t;
                    }
                    b[j] -= b[i] * t;
                }
            }
        } else {
            printf("Infinite solutions\n");
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%5.3g ", a[i][j]);
        }
        printf("%5.3g\n", b[i]);
    }
    for (int i = 0; i < n; i++) {
        delete[] a[i];
    }
    delete[] a;
    delete[] b;
    return 0;
}