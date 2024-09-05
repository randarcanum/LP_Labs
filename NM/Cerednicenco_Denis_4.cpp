#include <iostream>
#include <cmath>
using namespace std;
double a,b,c;
double f(double x){
    return -x*x*x + (a+b+c)*x*x - (a*b + b*c + a*c - 77)*x + a*b*c - 6*a - 63*b - 8*c + 136; 
}
double dfdx(double x){
    return -3*x*x + 2*(a+b+c)*x - a*b - b*c - a*c + 77;
}
int main() {
    double x = 0, eps;
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    cout << "c = ";
    cin >> c;
    do {
        eps = f(x) / dfdx(x);
        x -= eps;
    } while (abs(eps) > 1e-3);
    printf("Eigenvalue = %.3g\n", x);
    printf("Eigenvector = (%.3g, %.3g, 1)", ((12-56/(a-x))/((b-x)-8/(a-x))-7)/(a-x), (28/(a-x)-6)/((b-x)-8/(a-x)));
}