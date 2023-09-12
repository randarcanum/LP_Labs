#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
void fill(int x, int *m, int n) {
    switch(x) {
        case 0:
            for (int i = 0; i < n; i++) {
                cin >> m[i];
            }
            break;
        case 1:
            srand(time(0));
            for (int i = 0; i < n; i++) {
                m[i] = rand();
                cout << m[i] << ' ';
            }
            cout << endl;
            break;
        default:
            cout << "Invalid option. Exiting..." << endl;
            break;
    }
}
int minmax(int *m, int n) {
    int min = m[0], max = m[0];
    for (int i = 1; i < n; i++) {
        if (m[i] < min) min = m[i];
        if (m[i] > max) max = m[i];
    }
    return min + max;
}
void shuff(int *m, int n) {
    int *temp = new int[n];
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (m[i] % 2 != 0) {
            temp[j] = m[i];
            j++;
        }
    }
    for (int i = 0; i < n; i++) {
        if (m[i] % 2 == 0) {
            temp[j] = m[i];
            j++;
        }
        m[i] = temp[i];
    }
    delete[] temp;
}
int main() {
    int len, inp;
    cout << "Array length: ";
    cin >> len;
    int *arr = new int[len];
    cout << "Choose option:" << endl;
    cout << "0: Keyboard input" << endl;
    cout << "1: Random input" << endl;
    cin >> inp;
    fill(inp, arr, len);
    cout << minmax(arr, len) << endl;
    shuff(arr, len);
    for (int i = 0; i < len; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
    delete[] arr;
    return 0;
}