#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;
double f(double x, double xk, double a, double b, double c, double d) {
    float h = x - xk;
    return a + h * b + h * h * c + h * h * h * d;
}
int main() {
    ifstream xy("xy2.txt");
    vector<double> x, y;
    stringstream ss;
    string s;
    double n;
    getline(xy, s);
    ss.str(s);
    while(ss >> n) x.push_back(n);
    ss.clear();
    getline(xy, s);
    ss.str(s);
    while(ss >> n) y.push_back(n);
    xy.close();
    const int N = x.size();
    printf("x\t");
    for (double k : x) printf("%.3f\t", k);
    printf("\ny\t");
    for (double k : y) printf("%.3f\t", k);
    printf("\n==================\n");
    double delta[N], lambda[N], b[N], c[N], d[N], h[N], l[N];
    for (int k = 1; k < N; k++) {
        h[k] = x[k] - x[k - 1];
        l[k] = (y[k] - y[k - 1]) / h[k];
    }
    delta[1] = -h[2] / (2 * (h[1] + h[2]));
    lambda[1] = 1.5 * (l[2] - l[1]) / (h[1] + h[2]);
    c[0] = 0;
    c[N - 1] = 0;
    for (int k = N - 1; k >= 2; k--) {
        c[k - 1] = delta[k - 1] * c[k] + lambda[k - 1];
    }
    for (int k = 1; k < N; k++) {
        d[k] = (c[k] - c[k - 1]) / (3 * h[k]);
        b[k] = l[k] + (2 * c[k] * h[k] + h[k] * c[k - 1]) / 3;
    }
    printf(" A\t B\t C\t D\n");
    for (int k = 1; k < N; k++) {
        printf("%.3f\t%.3f\t%.3f\t%.3f\n", y[k], b[k], c[k], d[k]);
    }
    printf("==================\n");
    double inter;
    for (int k = 0; k < N; k++) {
        if (k != 0) {
            inter = f(x[k], x[k], y[k], b[k], c[k], d[k]);
            printf("x_%d = %.3f\ny_%d_left = %.3f\n", k, x[k], k, inter);
            if (abs(inter - y[k]) > 1e-5) {
                printf("The main condition is not met.\n");
                return 0;
            }
        }
        if (k != N - 1) {
            inter = f(x[k], x[k + 1], y[k + 1], b[k + 1], c[k + 1], d[k + 1]);
            printf("x_%d = %.3f\ny_%d_right = %.3f\n", k, x[k], k, inter);
            if (abs(inter - y[k]) > 1e-5) {
                printf("The main condition is not met.\n");
                return 0;
            }
        }
    }
    printf("The main condition is met.\n");
    printf("==================\n");
    double xtest;
    for (int k = 1; k < N; k++)
    {
        xtest = (x[k] + x[k - 1]) / 2;
        inter = f(xtest, x[k], y[k], b[k], c[k], d[k]);
        printf("x_%d%d = %.3f\ny = %.3f\n", k - 1, k, xtest, inter);
    }
    return 0;
}