#include <iostream>
#include <cmath>
using namespace std;
float f(float x) {
    return 2*log(x) - x*x + 5;
}
float dfdx(float x) {
    return 2/x - 2*x;
}
float d2fdx2(float x) {
    return -2/(x*x) - 2;
}
int main() {
    float a = 1, b = 4, x, eps;
    do {
        x = (a+b)/2;
        if (f(x)*f(a) < 0) b = x; else a = x;
    } while(abs(a-b) > 1e-2);
    printf("x_0 = %.3g\n", x);
    x = 4;
    do {
        eps = f(x) / dfdx(x);
        x -= eps;
    } while (abs(eps) > 1e-2);
    printf("x_0 = %.3g\n", x);
    a = 1;
    b = 3;
    if (f(a)*d2fdx2(a) < 0) {
        x = b;
        b = a;
    } else {
        x = a;
    }
    do {
        eps = f(x) * (b-x) / (f(b)-f(x));
        x -= eps;
    } while (abs(eps) > 1e-2);
    printf("x_0 = %.3g\n", x);
}