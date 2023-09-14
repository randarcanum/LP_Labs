#include <iostream>
#include <cstdlib>
using namespace std;
int main() {
    int m[200], t, x;
    cout << "Seed: ";
    cin >> x;
    srand(x);
    for (int i = 0; i < 200; i++) {
        m[i] = i + 1;
    }
    for (int i = 0; i < 200; i++) {
        x = rand() % 200;
        t = m[i];
        m[i] = m[x];
        m[x] = t;
    }
    for (int i = 0; i < 200; i++) {
        cout << m[i] << ' ';
    }
    cout << endl << endl;
    for (int i = 1; i < 200; i++) {
        if (abs(m[i-1] - m[i]) < 5) {
            int j = i + 1;
            while (abs(m[j] - m[i-1]) < 5 && j < 200) j++;
            if (j == 200) {
                j = 1;
                while (abs(m[j] - m[i-1]) < 5 || abs(m[j-1] - m[i]) < 5 || abs(m[j+1] - m[i]) < 5) j++;
            }
            t = m[i];
            m[i] = m[j];
            m[j] = t;
        }
    }
    for (int i = 0; i < 200; i++) {
        cout << m[i] << ' ';
    }
    cout << endl;
    return 0;
}