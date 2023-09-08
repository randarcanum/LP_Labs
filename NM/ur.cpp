#include <iostream>
#include <cmath>
using namespace std;
int main() {
    float a, b, c, delta;
    int x;
    cout << "Choose equation order: ";
    cin >> x;
    switch(x) {
        case 1:
            cout << "a = ";
            cin >> a;
            cout << "b = ";
            cin >> b;
            if (b >= 0) cout << "Equation: " << a << "x + " << b << " = 0" << endl;
            else cout << "Equation: " << a << "x - " << -b << " = 0" << endl;
            if (a == 0) {
                if (b == 0) cout << "Infinite roots" << endl;
                else cout << "No roots" << endl;
            }
            else cout << "x = " << -b/a << endl;
            break;
        case 2:
            cout << "a = ";
            cin >> a;
            cout << "b = ";
            cin >> b;
            cout << "c = ";
            cin >> c;
            cout << "Equation: ";
            if (a != 1) cout << a;
            cout << "x^2";
            if (b >= 0) {
                cout << " + ";
                if (b != 1) cout << b;
            } else {
                cout << " - ";
                if (b != 1) cout << -b;
            }
            if (c >= 0) cout << " + " << c << " = 0" << endl; else cout << " - " << -c << " = 0" << endl;
            if (a == 0) {
                if (b == 0) {
                    if (c == 0) cout << "Infinite roots" << endl;
                    else cout << "No roots" << endl;
                }
                else cout << "x = " << -c/b << endl;
            } else {
                delta = b*b - 4*a*c;
                if (delta < 0) cout << "No real roots" << endl;
                else if (delta == 0) cout << "x = " << -b/(2*a) << endl;
                else {
                    cout << "x_1 = " << (-b + sqrt(delta))/(2*a) << endl;
                    cout << "x_2 = " << (-b - sqrt(delta))/(2*a) << endl;
                }
            }
            break;
        default:
            cout << "Error. Exiting..." << endl;
    }
    
}