#include <iostream>
using namespace std;
float f(float x) {
    return x*x*x*x + 2*x - 10000;
}
int main() {
    float a = 9, b = 10, c;
    do {
        c = (a+b)/2;
        if (f(c)*f(a) < 0) b = c; else a = c;
    } while(abs(a-b) > 1e-5);
    cout << c << endl;
}