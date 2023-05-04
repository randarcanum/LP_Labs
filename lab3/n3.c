#include <stdio.h>

int main() {
    int a[10], b[3], d[10];
    int j;
    printf("10-number array, please:\n");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &a[i]);
    }
    if (a[0] < a[1]) {
        b[0] = a[0];
        b[2] = a[1];
    } else {
        b[0] = a[1];
        b[2] = a[0];
    }
    if (a[2] < b[0]) {
        b[1] = b[0];
        b[0] = a[2];
    } else if (a[2] > b[2]) {
        b[1] = b[2];
        b[2] = a[2];
    } else {
        b[1] = a[2];
    }
    int c[3] = {b[2], b[1], b[0]};
    for (int i = 3; i < 10; i++) {
        j = 0;
        while (j < 3) {
            if (a[i] <= b[j]) {
                for (int k = 2; k > j; k--) {
                    b[k] = b[k-1];
                }
                b[j] = a[i];
                break;
            } else j++;
        }
        j = 0;
        while (j < 3) {
            if (a[i] >= c[j]) {
                for (int k = 2; k > j; k--) {
                    c[k] = c[k-1];
                }
                c[j] = a[i];
                break;
            } else j++;
        }
    }
    int odd = 0, even = 0, mod_five = 0;
    for (int i = 0; i < 10; i++) {
        if (a[i] % 2 == 0) {
            d[even] = a[i];
            even++;
        }
        if (a[i] % 5 == 0) mod_five++;
    }
    for (int i = 0; i < 10; i++) {
        if (a[i] % 2 != 0) {
            d[even+odd] = a[i];
            odd++;
        }
    }
    printf("  3 mins    3 maxes\n");
    for (int i = 0; i < 3; i++) {
        printf("%6d %10d\n", b[i], c[i]);
    }
    printf("Even-odd array:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d\n", d[i]);
    }
    printf("Array has %d even, %d odd numbers.\n", even, odd);
    printf("Array has %d numbers, divisible by 5.\n", mod_five);
    return 0;
}