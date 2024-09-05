#include <iostream>
#include <cmath>
using namespace std;
double f(double x) {
    return x*x*x + 3*x*x + 5*x +2;
}
double fp(double x) {
    return 3*x*x + 6*x + 5;
}
int main() {
    double h = 0.01, x = 2, xp = x-h, xn = x+h;
    cout << (f(xn) - f(xp))/(2*h) << ' ' << abs((f(xn) - f(xp))/(2*h) - fp(x)) << endl;
    cout << (f(xn) - f(x))/h << ' ' << abs((f(xn) - f(x))/h - fp(x)) << endl;
    cout << (f(x) - f(xp))/h << ' ' << abs((f(x) - f(xp))/h - fp(x)) << endl;
    cout << (3*f(x) - 4*f(xp) + f(x - 2*h))/(2*h) << ' ' << abs((3*f(x) - 4*f(xp) + f(x - 2*h))/(2*h) - fp(x)) << endl;
    cout << (-f(x+2*h) + 8*f(x+h) - 8*f(x-h) + f(x-2*h))/(12*h) << ' ' << abs((-f(x+2*h) + 8*f(x+h) - 8*f(x-h) + f(x-2*h))/(12*h) - fp(x)) << endl;
}