#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
vector<double> gauss(vector<vector<double>> a, vector<double> b) {
    for (int i = 0; i < b.size(); i++) {
        for (int k = b.size()-1; k > i; k--)
            a[i][k] /= a[i][i];
        b[i] /= a[i][i];
        a[i][i] = 1;
        for (int j = 0; j < b.size(); j++) {
            if (i != j) {
                double t = a[j][i] / a[i][i];
                a[j][i] = 0;
                for (int k = i+1; k < b.size(); k++) {
                    a[j][k] -= a[i][k] * t;
                }
                b[j] -= b[i] * t;
            }
        }
    }
    return b;
}
int main() {
    vector<double> x = {0.5, 1.0, 1.5, 2.0, 2.5, 3.0, 3.5, 4.0};
    vector<double> y = {0.4, 0.3, 1.0, 1.7, 2.1, 3.4, 4.1, 5.8};
    double sum_x = accumulate(x.begin(), x.end(), 0.0);
    double sum_y = accumulate(y.begin(), y.end(), 0.0);
    double sum_x2 = transform_reduce(x.begin(), x.end(), 0.0, plus<>{}, [](double x){return x*x;});
    double sum_x3 = transform_reduce(x.begin(), x.end(), 0.0, plus<>{}, [](double x){return x*x*x;});
    double sum_x4 = transform_reduce(x.begin(), x.end(), 0.0, plus<>{}, [](double x){return x*x*x*x;});
    double sum_yx = transform_reduce(x.begin(), x.end(), y.begin(), 0.0, plus<>{}, [](double x, double y){return y*x;});
    double sum_yx2 = transform_reduce(x.begin(), x.end(), y.begin(), 0.0, plus<>{}, [](double x, double y){return y*x*x;});
    vector<vector<double>> a = {
        {sum_x2, sum_x},
        {sum_x, (double) x.size()}
    };
    vector<double> b = {sum_yx, sum_y};
    vector<double> res = gauss(a, b);
    printf("y = ");
    for (int i = 0; i < res.size(); i++) {
        if (abs(res[i]) > 1e-3) {
            if (i != 0) printf(" %c %.3g", res[i] > 0 ? '+' : '-', abs(res[i]));
            else printf("%.3g", res[i]);
            if (i < res.size()-1) printf("x");
            if (i < res.size()-2) printf("^%d", (int) res.size()-i-1);
        }
    }
    printf("\n");
    a = {
        {sum_x4, sum_x3, sum_x2},
        {sum_x3, sum_x2, sum_x},
        {sum_x2, sum_x, (double) x.size()}
    };
    b = {sum_yx2, sum_yx, sum_x};
    res = gauss(a, b);
    printf("y = ");
    for (int i = 0; i < res.size(); i++) {
        if (abs(res[i]) > 1e-3) {
            if (i != 0) printf(" %c %.3g", res[i] > 0 ? '+' : '-', abs(res[i]));
            else printf("%.3g", res[i]);
            if (i < res.size()-1) printf("x");
            if (i < res.size()-2) printf("^%d", (int) res.size()-i-1);
        }
    }
    printf("\n");
    return 0;
}