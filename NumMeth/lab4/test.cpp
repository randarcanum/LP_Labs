#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>
using namespace std;
int main() {
    vector<double> m = {1,2,3};
    double r = 2;
    double* row = &(r);
    transform(m.begin(), m.end(), m.begin(), [&](double x) {return x / m.back();});
    cout << m[0] << m[1] << m[2] << endl;
}