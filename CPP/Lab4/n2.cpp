#include <iostream>
using namespace std;
int main() {
    short a;
    float b;
    cout << "Short: ";
    cin >> a;
    for (int i = 15; i >= 0; i--) {
        cout << ((a >> i) & 1);
    }
    cout << endl;
    cout << "Float: ";
    cin >> b;
    int c = *(int*)&b;
    for (int i = 31; i >= 0; i--) {
        cout << ((c >> i) & 1);
        if (i == 31 || i == 24) cout << ' ';
    }
    cout << endl << "s eeeeeee mmmmmmmmmmmmmmmmmmmmmmmm" << endl;
    return 0;
}