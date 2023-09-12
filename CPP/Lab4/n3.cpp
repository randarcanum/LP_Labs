#include <iostream>
#include <cstring>
using namespace std;
void crypt(int *pin, int *pout, int size) {
    pout[0] = pin[0];
    for (int i = 1; i < size; i++) {
        pout[i] = pout[i-1] ^ pin[i];
    }
}
void decrypt(int *pin, int *pout, int size) {
    pout[0] = pin[0];
    for (int i = 1; i < size; i++) {
        pout[i] = pin[i-1] ^ pin[i];
    }
}
int main() {
    int n;
    cout << "Array size: ";
    cin >> n;
    int *arrin = new int[n], *arrcr = new int[n], *arrdecr = new int[n];
    cout << "    Array: ";
    for (int i = 0; i < n; i++) {
        cin >> arrin[i];
    }
    crypt(arrin, arrcr, n);
    cout << "Encrypted: ";
    for (int i = 0; i < n; i++) {
        cout << arrcr[i] << ' ';
    }
    cout << endl;
    cout << "Decrypted: ";
    decrypt(arrcr, arrdecr, n);
    for (int i = 0; i < n; i++) {
        cout << arrdecr[i] << ' ';
    }
    cout << endl;
    if (memcmp(arrin, arrdecr, 4*n)) cout << "Decription error" << endl;
    else cout << "Decription success" << endl;
    delete[] arrin;
    delete[] arrcr;
    delete[] arrdecr;
    return 0;
}