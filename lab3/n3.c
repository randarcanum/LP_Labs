#include <stdio.h>

int main() {
    int a[10], d[10];
    int j;
    printf("10-number array, please:\n");
    for (int i = 0; i < 10; i++) {
        scanf("%d,", &a[i]);
    }
    int b[3] = {2147483647, 0, 0};
    int c[3] = {-2147483648, 0, 0};
    for (int i = 0; i < 10; i++) {
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
    for (int i = 0; i < 9; i++) {
        printf("%d, ", d[i]);
    }
    printf("%d\n", d[9]);
    printf("Array has %d even, %d odd numbers.\n", even, odd);
    printf("Array has %d numbers, divisible by 5.\n", mod_five);
    return 0;
}