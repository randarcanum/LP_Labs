#include <iostream>
using namespace std;
int mod(unsigned int b, short g) {
    if (g != 0) return b & (1 << g - 1) - 1;
    else return b;
}
int main() {
    unsigned int bit;
    short n;
    cout << "Number: ";
    cin >> bit;
    cout << "n: ";
    cin >> n;
    cout << bit << " % 2^" << n << " = " << mod(bit, n) << endl;
    return 0;
}