#include <iostream>
using namespace std;
double a = 25, b = 1 + 35, c = 5, d = 4, e = a/b;
double f(double x) {
    return c*x*x+d*x+e;
}
int main() {
    int n = 10;
    double h = (b-a)/n, rim = 0;
    for (int i = 0; i < n; i++) {
        rim += f(a+i*h+h/2)*h;
    }
    printf("rectang: int(%g, %g) = %.5g\n", a, b, rim);
    rim = (f(a) + f(b))*h/2;
    for (int i = 1; i < n; i++) {
        rim += f(a+i*h)*h;
    }
    printf("trapez:  int(%g, %g) = %.5g\n", a, b, rim);
    h /= 2;
    rim = (f(a) + f(b))*h/3;
    for (int i = 1; i < 2*n; i++) {
        rim += 2*f(a+i*h)*h/3;
    }
    for (int i = 1; i < 2*n; i+=2) {
        rim += 2*f(a+i*h)*h/3;
    }
    printf("parabol: int(%g, %g) = %.5g", a, b, rim);
}