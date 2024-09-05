#include <iostream>
#include <cmath>
#include <functional>
using namespace std;
const int N = 2;
double *add(double *y, double k) {
    static double yk[N];
    for (int i = 0; i < N; i++) {
        yk[i] = y[i] + k;
    }
    return yk;
}
int main() {
    double x = 0, y[N] = {2, 0}, h = 0.005, dy[N];
    const bool check = 1;
    function <double(double, double*)> f[N] = {
        [](double x, double *y){return -y[0] + 2*y[1];},
        [](double x, double *y){return 2*y[0] - y[1];}
        };
    function <double(double)> F[N] = {
        [](double x){return exp(x) + exp(-3*x);},
        [](double x){return exp(x) - exp(-3*x);}
        };
    printf("x = %.3f, ", x);
    for (int i = 0; i < N; i++) {
        printf("y_%i = %.5f\n           ", i+1, y[i]);
    }
    printf("\n");
    for (x; x < 0.5; x += h) {
        double k0, k1, k2, k3;
        for (int i = 0; i < N; i++) {
            k0 = h * f[i](x, y);
            k1 = h * f[i](x + h/2, add(y, k0/2));
            k2 = h * f[i](x + h/2, add(y, k1/2));
            k3 = h * f[i](x + h, add(y, k2));
            y[i] += (k0 + 2*k1 + 2*k2 + k3)/6;
            if (check) dy[i] = abs(F[i](x+h) - y[i]);
        }
        printf("x = %.3f, ", x+h);
        for (int i = 0; i < N; i++) {
            printf("y_%i = %.5f", i+1, y[i]);
            if (check) printf(", dy_%i = %.5f", i+1, dy[i]);
            printf("\n           ");
        }
        printf("\n");
    }
}