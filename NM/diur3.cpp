#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
double dy2dx(double x, double y, double dydx) {
    return 2*dydx + 3*y + exp(4*x);
}
double p(double x) {
    return -2;
}
double q(double x) {
    return -3;
}
double f(double x) {
    return exp(4*x);
}
int main() {
    int n = 20;
    double h = 1/n, x = 0;
    vector<double> yn;
    vector<vector<double>> abcd;
    for (int i = 0; i <= n; i++) {
        abcd.push_back({1/h-q(x)/2, h*p(x)-2/h, 1/h+q(x)/2, h*f(x)});
        x += h;
    }
    return 0;
}

// y'(0) - y(0) = 0.6
// y'(1) + y(1) = 4*e^3 + e^4
// y = e^-x + e^3x + 0.2*e^4x