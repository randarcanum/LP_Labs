#include <stdio.h>

int main() {
    int a, b, c;
    printf("3 numbers, please:\n");
    scanf("%d %d %d", &a, &b, &c);
    int max = a;
    int min = a;
    if (b < a) {
        min = b;
        if (c < b) {
            min = c;
        };
    } else {
        max = b;
        if (c > b) {
            max = c;
        };
    };
    printf("\nSum = %d\n", a + b + c);
    printf("Max^2 = %d\n", max * max);
    printf("2*Min = %d\n", min * 2);
    if (a + b > c) {
        printf("A + B > C, so A + B = %d\n", a + b);
    } else {
        printf("A + B <<= C, so A - B = %d\n", a - b);
    };
    return 0;
}