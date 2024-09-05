#include <iostream>
#include <cmath>
using namespace std;
double f(double x, double y) {
    return y - x*y;
}
double F(double x, double y) {
    return exp(x - x*x/2);
}
int main() {
    double x = 0, y = 1, h = 0.005, ry, k1, k2, k3, k4;
    printf("x = %.2f, y = %.5f\n", x, y);
    while (x + h < 0.5) {
        ry = F(x+h, y);
        k1 = h * f(x, y);
        k2 = h * f(x + h, y + k1);
        k3 = h * f(x + h/2, y + k1/4 + k2/4);
        y = y + (k1 + 4*k2 + k3)/6;
        x += h;
        printf("x = %.2f, y = %.5f; delta = %.5f\n", x, y, abs(ry - y));
    }
    printf("\n\n");
    x = 0;
    y = 1;
    while (x < 0.5) {
        ry = F(x+h, y);
        k1 = h * f(x, y);
        k2 = h * f(x + h/2, y + k1/2);
        k3 = h * f(x + h/2, y + k2/2);
        k4 = h * f(x + h, y + k3);
        y = y + (k1 + 2*k2 + 2*k3 + k4)/6;
        x += h;
        printf("x = %.2f, y = %.5f; delta = %.15f\n", x, y, abs(ry - y));
    }
}