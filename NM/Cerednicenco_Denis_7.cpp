#include <iostream>
using namespace std;
double x[] {0.451, 0.452, 0.453, 0.454, 0.455};
double y[] {0.43587, 0.43677, 0.43766, 0.43856, 0.43945};
double h = x[1]-x[0];
double dy1(int i) {
    switch (i) {
        case 0:
            return (-y[2]+4*y[1]-3*y[0])/(2*h);
        case 1:
            return (y[2]-y[0])/(2*h);
        case 2:
            return (-y[4]+8*y[3]-8*y[1]+y[0])/(12*h);
        case 3:
            return (y[4]-y[2])/(2*h);
        case 4:
            return (3*y[4]-4*y[3]+y[2])/(2*h);
        default:
            return 0;
    }
}
double dy2(int i) {
    switch (i) {
        case 0:
            return (-y[3]+4*y[2]-5*y[1]+2*y[0])/(h*h);
        case 1:
            return (y[2]-2*y[1]+y[0])/(h*h);
        case 2:
            return (-y[4]+16*y[3]-30*y[2]+16*y[1]-y[0])/(12*h*h);
        case 3:
            return (y[4]-2*y[3]+y[2])/(h*h);
        case 4:
            return (2*y[4]-5*y[3]+4*y[2]-y[1])/(h*h);
        default:
            return 0;
    }
}
double dy3(int i) {
    switch (i) {
        case 0:
            return (-3*y[4]+14*y[3]-24*y[2]+18*y[1]-5*y[0])/(2*h*h*h);
        case 1:
            return (y[4]-3*y[3]+3*y[2]-y[1])/(h*h*h);
        case 2:
            return (y[4]-2*y[3]+2*y[1]-y[0])/(2*h*h*h);
        case 3:
            return (y[3]-3*y[2]+3*y[1]-y[0])/(h*h*h);
        case 4:
            return (5*y[4]-18*y[3]+24*y[2]-14*y[1]+3*y[0])/(2*h*h*h);
        default:
            return 0;
    }
}
int main() {
    for (int i = 0; i < 5; i++) {
        printf("x = %.3f\n", x[i]);
        printf("y = %.5f\n", y[i]);
        printf("dy/dx = %.5f\n", dy1(i));
        printf("d2y/dx2 = %.5f\n", dy2(i));
        printf("d3y/dx3 = %.5f\n\n", dy3(i));
    }
}