#include <iostream>
#include <cstring>
using namespace std;
int src(int *m, int n, int *b, int bn) {
    int j = 0;
    for (int i = 0; i < n-bn+1; i++) {
        if (m[i] = b[0]) if (memcmp(m+i, b, 4*bn) == 0) j++;
    }
    return j;
}
int main() {
    int len, blen;
    cout << "Array length: ";
    cin >> len;
    int *arr = new int[len];
    cout << "Array: ";
    for (int i = 0; i < len; i++) {
        cin >> arr[i];
    }
    cout << "Block length: ";
    cin >> blen;
    int *bl = new int[blen];
    cout << "Block: ";
    for (int i = 0; i < blen; i++) {
        cin >> bl[i];
    }
    cout << "Found " << src(arr, len, bl, blen) << " times" << endl;
    return 0;
}