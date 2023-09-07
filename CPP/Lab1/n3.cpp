#include <iostream>
using namespace std;
int main() {
    short m[5][5], t;
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> m[i][j];
        }
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (m[i][j] < 10) sum += m[i][j];
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 5; j++) {
            t = m[i][j];
            m[i][j] = m[j][i];
            m[j][i] = t;
        }
    }
    cout << "Sum < 10 = " << sum << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}