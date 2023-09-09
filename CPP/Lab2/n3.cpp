#include <iostream>
#include <cmath>
using namespace std;
float tsin(float x, int n) {
    float func = x, it = x;
    for (int i = 1; i < n; i++) {
        it *= -x*x/(2*i*(2*i+1));
        func += it;
    }
    return func;
}
int main() {
    float ang;
    int term;
    cout << "x: ";
    cin >> ang;
    cout << "Terms: ";
    cin >> term;
    if (term <= 0) exit;
    cout << "sin(x) = " << tsin(ang, term) << endl;
    cout << "(math.h) sin(x) = " << sin(ang) << endl;
    return 0;
}