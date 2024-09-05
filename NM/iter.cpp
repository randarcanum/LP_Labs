#include <iostream>
#include <cmath>
using namespace std;
int main() {
    float x1 = 0, y1 = 0, eps = 1e-3, x, y;
    do {
        x = x1;
        y = y1;
        x1 = x*x + y*y + 0.194;
        y1 = x*y + 0.13;
    } while(x1-x>eps && y1-y>eps);
    cout << x1 << endl;
    cout << y1 << endl;
}