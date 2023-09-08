#include <iostream>
#include <cmath>
using namespace std;
int main() {
    float x = 10;
    float t;
    do {
        t = x;
        x = sqrt(sqrt(10000 - 2*x));
    } while(abs(x - t) > 0.00001);
    cout << x << endl;
    cout << (x*x*x*x + 2*x - 10000) << endl;
}