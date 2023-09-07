#include <iostream>
using namespace std;
int main() {
    int m[5][5], min;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> m[i][j];
        }
    }
    min = m[0][0];
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (m[i][j] < min) min = m[i][j];
        }
    }
    cout << "Min = " << min << endl;
    return 0;
}