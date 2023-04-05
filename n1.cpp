#include <iostream>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int max = a;
    int min = a;
    if (b < a) {
        min = b;
        if (c < b) {
            min = c;
            };
    } else {
        max = b;
        if (c > b) {
            max = c;
        };
    };
    cout << a + b + c << endl;
    cout << max * max << endl;
    cout << min * 2 << endl;
    if (a + b > c) {
        cout << a + b << endl;
    } else {
        cout << a - b << endl;
    };
    return 0;
}