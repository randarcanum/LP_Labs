#include <iostream>
#include <cmath>
using namespace std;
int a, b, c, d, e, f, k;
double fx(double x, double y) {
    return (-1)*(k%2*2-1)*(a + b*0.1)*y + (c + d*0.1)*x*x + (e + f*0.01);
}
int main() {
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    cout << "c = ";
    cin >> c;
    cout << "d = ";
    cin >> d;
    e = a/b;
    f = a+b+c+d;
    k = 6;
    double x = 0, y = 1, h = 0.1, k1, k2, k3, k4;
    printf("x = %.1f, y = %.3f\n", x, y);
    for (x; x < 2; x += h) {
        y = y + fx(x, y) * h;
        printf("x = %.1f, y = %.3f\n", x+h, y);
    }
    x = 0;
    y = 1;
    printf("x = %.1f, y = %.3f\n", x, y);
    for (x; x < 2; x += h) {
        k1 = h * fx(x, y);
        k2 = h * fx(x + h/2, y + k1/2);
        k3 = h * fx(x + h/2, y + k2/2);
        k4 = h * fx(x + h, y + k3);
        y = y + (k1 + 2*k2 + 2*k3 + k4)/6;
        printf("x = %.1f, y = %.3f\n", x+h, y);
    }
}