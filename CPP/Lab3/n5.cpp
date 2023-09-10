#include <iostream>
#include <cstring>
using namespace std;
void shuff(int *m, int n, int b) { //Memory efficient
    int mod = n % b;
    int *t = new int[b+mod];
    int *beg = m+mod, *end = m+n-b-mod;
    memcpy(t, m, 4*(b+mod));
    if (mod != 0) memcpy(m, end+b, 4*mod);
    for (int i = 0; i < n/b/2; i++, beg += b, end -= b) {
        memcpy(beg, end, 4*b);
        memcpy(end+mod, t, 4*b);
        memcpy(t, t+b, 4*mod);
        memcpy(t+mod, beg+b, 4*b);
    }
    delete[] t;
}
void shuff2(int *m, int n, int b) { //Second option, time efficient
    int *t = new int[n];
    int *beg = m, *end = t+n-b;
    for (int i = 0; i < n / b; i++, beg += b, end -= b) {
        memcpy(end, beg, 4*b);
    }
    if (n % b != 0) memcpy(t, beg, 4*(n%b));
    memcpy(m, t, 4*n);
    delete[] t;
}
int main() {
    int len, bl;
    cout << "Array length: ";
    cin >> len;
    int *arr = new int[len];
    cout << "Array: ";
    for (int i = 0; i < len; i++) {
        cin >> arr[i];
    }
    cout << "Block length: ";
    cin >> bl;
    shuff(arr, len, bl);
    cout << "New array: ";
    for (int i = 0; i < len; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
    delete[] arr;
    return 0;
}