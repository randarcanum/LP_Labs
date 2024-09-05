#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;
int main() {
    float a0, b0, c0, a, b, c, delta;
    cout << "a = ";
    cin >> a0;
    cout << "b = ";
    cin >> b0;
    srand(time(0));
    c0 = rand() % 100 + 1;
    cout << "c = " << c0 << endl;
    a = c0;
    b = a0*c0 + b0*c0;
    c = a0*b0*c0;
    cout << "Equation: ";
    if (a != 1) cout << a;
    cout << "x^2 - " << b << "x + " << c << " = 0" << endl;
    delta = b*b - 4*a*c;
    cout << "x_1 = " << (b + sqrt(delta))/(2*a) << endl;
    cout << "x_2 = " << (b - sqrt(delta))/(2*a) << endl;
}