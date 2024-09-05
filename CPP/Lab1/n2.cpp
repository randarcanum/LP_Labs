#include <iostream>
using namespace std;
int main() {
    float m[3][3], t;
    int a, b, c, d;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> m[i][j];
        }
    }
    //for (int i = 0; i < 9; i++) {
    //    for (int j = 0; j < 8 - i; j++) {
    //        a = j / 3;
    //        b = j % 3;
    //        c = (j + 1) / 3;
    //        d = (j + 1) % 3;
    //        if (m[c][d] < m[a][b]) {
    //            t = m[a][b];
    //            m[a][b] = m[c][d];
    //            m[c][d] = t;
    //        }
    //    }
    //}
    for (float *klo = &m[2][2]; klo > m[0]; klo--) {
        for (float *flo = m[0]; flo < klo; flo++) {
            if (*flo > *(flo+1)) {
                t = *flo;
                *flo = *(flo+1);
                *(flo+1) = t;
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}