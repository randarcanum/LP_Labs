#include <iostream>
#include <cmath>
using namespace std;
float f(float x, float y) {
    return 5 - x - 3 * y + cos(x - 3.14 / 9);
}
float F(float x, float y) {
    return 0;
}
int main() {
    float x = 7, y = 6, h = 0.08, ry;
    printf("x = %.2f, y = %.5f\n", x, y);
    while (x < 15) {
        ry = F(x+h, y);
        y = y + f(x, y) * h;
        x += h;
        printf("x = %.2f, y = %.5f; delta = %.5f\n", x, y, abs(ry - y));
    }
    printf("\n");
    x = 7;
    y = 6;
    while (x < 15) {
        ry = F(x+h, y);
        y = y + (f(x, y) + f(x+h, y+h*f(x, y))) * (h/2);
        x += h;
        printf("x = %.2f, y = %.5f; delta = %.5f\n", x, y, abs(ry - y));
    }
}