#include <iostream>
using namespace std;
void shift(int *m, int l, int sh, bool fl) {
    sh %= l;
    int *t = new int[sh];
    for (int i = 0; i < sh; i++) {
        t[i] = m[abs((l-1)*fl-i)];
    }
    for (int i = 0; i < l-sh; i++) {
        m[abs((l-1)*fl-i)] = m[abs((l-1)*fl-i-sh)];
    }
    for (int i = l-sh; i < l; i++) {
        m[abs((l-1)*fl-i)] = t[i-l+sh];
    }
    delete[] t;
}
int main() {
    int len, n;
    bool flag;
    cout << "Array length: ";
    cin >> len;
    cout << "Array: ";
    int *arr = new int[len];
    for (int i = 0; i < len; i++) {
        cin >> arr[i];
    }
    cout << "Shift: ";
    cin >> n;
    cout << "1: Right" << endl;
    cout << "0: Left" << endl;
    cin >> flag;
    shift(arr, len, n, flag);
    for (int i = 0; i < len; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
    delete[] arr;
    return 0;
}