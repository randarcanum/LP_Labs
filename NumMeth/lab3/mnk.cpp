#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>
using namespace std;
vector<double> x = {0.5, 1.0, 1.5, 2.0, 2.5, 3.0, 3.5, 4.0};
vector<double> y = {0.4, 0.3, 1.0, 1.7, 2.1, 3.4, 4.1, 5.8};
vector<double> res;
double sum_x, sum_y, sum_y2, sum_x2, sum_x3, sum_x4, sum_yx, sum_yx2;
vector<double> gauss(vector<vector<double>> a, vector<double> b) {
    // transform(a.begin(), a.end(), b.begin(), a.begin(), [](vector<double> x, double y) {x.push_back(y);});
    transform(a.begin(), a.end(), a.begin(), [](vector<double> i) {
        transform(i.begin()+);
        for (int k = b.size()-1; k > i; k--)
            i[k] /= i[i];
        i[i.size()-1] /= i[i];
        i[i] = 1;
        for (int l = 0; l < b.size(); l++) {
            double t = j[i] / i[i];
            j[i] = 0;
            for (int k = i+1; k < b.size(); k++) {
                j[k] -= i[k] * t;
            }
            j[j.size()-1] -= i[i.size()-1] * t;
        }
    });
        transform(a.begin(), a.end(), a.begin(), [](vector<double> x) {
            double t = x[i] / a[i][i];
            x[i] = 0;
            for (int k = i+1; k < b.size(); k++) {
                x[k] -= a[i][k] * t;
            }
            x[x.size()-1] -= b[i] * t;
                
        });


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
void print_func() {
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
}
void print_coef() {
    double tss = transform_reduce(x.begin(), x.end(), y.begin(), 0.0, plus<>{}, [](double x, double y){
        double var = 0;
        for (int i = res.size()-1; i >= 0; i--) {
            double part = res[res.size()-i-1];
            for (int j = 0; j < i; j++) {
                part *= x;
            }
            var += part;
        }
        return (var - y)*(var - y);
    });
    printf("TSS = %.3g\n", tss);
}
int main() {
    sum_x = accumulate(x.begin(), x.end(), 0.0);
    sum_y = accumulate(y.begin(), y.end(), 0.0);
    sum_y2 = transform_reduce(y.begin(), y.end(), 0.0, plus<>{}, [](double y){return y*y;});
    sum_x2 = transform_reduce(x.begin(), x.end(), 0.0, plus<>{}, [](double x){return x*x;});
    sum_x3 = transform_reduce(x.begin(), x.end(), 0.0, plus<>{}, [](double x){return x*x*x;});
    sum_x4 = transform_reduce(x.begin(), x.end(), 0.0, plus<>{}, [](double x){return x*x*x*x;});
    sum_yx = transform_reduce(x.begin(), x.end(), y.begin(), 0.0, plus<>{}, [](double x, double y){return y*x;});
    sum_yx2 = transform_reduce(x.begin(), x.end(), y.begin(), 0.0, plus<>{}, [](double x, double y){return y*x*x;});
    vector<vector<double>> a = {
        {sum_x2, sum_x},
        {sum_x, (double) x.size()}
    };
    vector<double> b = {sum_yx, sum_y};
    res = gauss(a, b);
    print_func();
    print_coef();

    a = {
        {sum_x4, sum_x3, sum_x2},
        {sum_x3, sum_x2, sum_x},
        {sum_x2, sum_x, (double) x.size()}
    };
    b = {sum_yx2, sum_yx, sum_y};
    res = gauss(a, b);
    print_func();
    print_coef();
    return 0;
}