#include <iostream>
#include <cmath>
#include <functional>
using namespace std;
vector<double> add(vector<double> y, double k) {
    static vector<double> yk(y.size());
    for (int i = 0; i < y.size(); i++) {
        yk[i] = y[i] + k;
    }
    return yk;
}
int main() {
    double x = 0, h = 0.005;
    vector<double> y = {2, 0}, dy(y.size()), y1(y.size());
    const bool check = 1;
    vector<function <double(vector<double>)>> f = {
        [](vector<double> y){return -y[0] + 2*y[1];},
        [](vector<double> y){return 2*y[0] - y[1];}
        };
    vector<function <double(double)>> F = {
        [](double x){return exp(x) + exp(-3*x);},
        [](double x){return exp(x) - exp(-3*x);}
        };
    printf("x = %.3f, ", x);
    for (int i = 0; i < y.size(); i++) {
        printf("y_%i = %.5f\n           ", i+1, y[i]);
    }
    printf("\n");
    for (x; abs(x - 0.5) > 1e-5; x += h) {
        double k0, k1, k2, k3;
        for (int i = 0; i < y.size(); i++) {
            k0 = h * f[i](y);
            k1 = h * f[i](add(y, k0/2));
            k2 = h * f[i](add(y, k1/2));
            k3 = h * f[i](add(y, k2));
            y[i] = y[i] + (k0 + 2*k1 + 2*k2 + k3)/6;
            if (check) dy[i] = abs(F[i](x+h) - y[i]);
        }
        printf("x = %.3f, ", x+h);
        for (int i = 0; i < y.size(); i++) {
            printf("y_%i = %.5f", i+1, y[i]);
            if (check) printf(", dy_%i = %.5f", i+1, dy[i]);
            printf("\n           ");
        }
        printf("\n");
    }
}