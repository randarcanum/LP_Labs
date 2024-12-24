#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ifstream xy("xy.txt");
    vector<double> x, y, xtest;
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
    ss.clear();
    getline(xy, s);
    ss.str(s);
    while(ss >> n) xtest.push_back(n);
    xy.close();
    const int N = x.size(), M = 4;
    printf("x\t");
    for (double k : x) printf("%.3f\t", k);
    printf("\ny\t");
    for (double k : y) printf("%.3f\t", k);
    printf("\n==================\n");
    printf("x\t");
    for (double k : xtest) printf("%.4f\t", k);
    printf("\ny\t");
    ofstream ytest("xytest.txt");
    for (double k : xtest) ytest << k << " ";
    ytest << endl;
    for (double test : xtest) {
        vector<double> a(y);
        double t, sum = 0, coef = 1;
        bool fl = false;
        if (abs(test - x[0]) < abs(test - x[N-1])) {
            t = (test - x[0]) / (x[1] - x[0]);
            fl = true;
        } else {
            t = (test - x[N-1]) / (x[1] - x[0]);
            reverse(a.begin(), a.end());
        }
        for (int k = 1; k < M; k++) {
            for (int i = N-1; i >= k; i--) {
                a[i] -= a[i-1];
                a[i] = fl ? a[i] : -a[i];
            }
        }
        for (int j = 0; j < M; j++) {
            sum += coef * a[j];
            coef *= (fl ? t - j : t + j) / (j + 1);
        }
        printf("%.4f\t", sum);
        ytest << sum << " ";
    }
    printf("\n");
    ytest << endl;
    return 0;
}