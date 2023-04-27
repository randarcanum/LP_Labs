#include <stdio.h>

int main() {
    printf("10 numbers, please:\n");
    float f[10], t;
    float min, max;
    float sum = 0, sum_pos = 0, sum_10 = 0;
    for (int i = 0; i < 10; i++) {
        scanf("%f", &f[i]);
        if (i == 0) {
            min = f[i];
            max = f[i];
        } else if (f[i] > max) {
            max = f[i];
        } else if (f[i] < min) {
            min = f[i];
        }
        sum += f[i];
        if (f[i] > 0) {
            sum_pos += f[i];
        }
        if (f[i] > 10 || f[i] < -10) {
            sum_10 += f[i];
        }
    }
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9 - i; j++) {
            if (f[j] < f[j+1]) {
                t = f[j];
                f[j] = f[j+1];
                f[j+1] = t;
            }
        }
    }
    printf("Max: %.2f\n", max);
    printf("Min: %.2f\n", min);
    printf("Sum: %.2f\n", sum);
    printf("Sum of positives: %.2f\n", sum_pos);
    printf("Sum of numbers greater than 10: %.2f\n", sum_10);
    printf("Descending array:\n");
    for (int i = 0; i < 10; i++) {
        printf("%.2f\n", f[i]);
    }
    return 0;
}