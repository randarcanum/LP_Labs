#include <iostream>
#include <cmath>
#include <functional>
using namespace std;
double a, b, c, d;
vector<double> add(vector<double> y, double k) {
    static vector<double> yk(y.size());
    for (int i = 0; i < y.size(); i++) {
        yk[i] = y[i] + k;
    }
    return yk;
}
int main() {
    double x = 1, h = 0.1;
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    cout << "c = ";
    cin >> c;
    cout << "d = ";
    cin >> d;
    vector<double> y = {a, b};
    vector<function <double(vector<double>)>> f = {
        [](vector<double> y){return a*y[0] + b*y[1];},
        [](vector<double> y){return c*y[0] + d*y[1];}
        };
    printf("t = %.3f, ", x);
    printf("x = %.3f\n", y[0]);
    printf("           ");
    printf("y = %.3f\n", y[1]);
    for (x; abs(x - 2) > 1e-5; x += h) {
        double k0, k1, k2, k3;
        for (int i = 0; i < y.size(); i++) {
            k0 = h * f[i](y);
            k1 = h * f[i](add(y, k0/2));
            k2 = h * f[i](add(y, k1/2));
            k3 = h * f[i](add(y, k2));
            y[i] += (k0 + 2*k1 + 2*k2 + k3)/6;
        }
        printf("t = %.3f, ", x+h);
        printf("x = %.3f\n", y[0]);
        printf("           ");
        printf("y = %.3f\n", y[1]);
    }
}