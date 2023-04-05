#include <stdio.h>

int main() {
	float f1, f2, f3, f4, f5;
    float abs_sum, abs_dif;
    float first_max, second_max, first_min, second_min;

    printf("5 numbers, please:\n");
    scanf("%f %f %f %f %f", &f1, &f2, &f3, &f4, &f5);

    abs_sum = f1 + f2 + f3 + f4 + f5;
    if (abs_sum < 0) {
        abs_sum *= -1;
    }
    abs_dif = f1 - f2 - f3 - f4 - f5;
    if (abs_dif < 0) {
        abs_dif *= -1;
    }

	if (f1 > f2) {
	    first_min = f2;
        first_max = f1;
	} else {
        first_min = f1;
        first_max = f2;
    }

    if (f3 > first_max) {
        second_max = first_max;
        second_min = first_max;
        first_max = f3;
    } else if (f3 > second_max) {
        second_max = f3;
        second_min = f3;
    } else {
        second_max = first_min;
        second_min = first_min;
        first_min = f3;
    }

    if (f4 > first_max) {
        second_max = first_max;
        first_max = f4;
    } else if (f4 > second_max) {
        second_max = f4;
    } else if (f4 < first_min) {
        second_min = first_min;
        first_min = f4;
    } else {
        second_min = f4;
    }

    if (f5 > first_max) {
        second_max = first_max;
        first_max = f5;
    } else if (f5 > second_max) {
        second_max = f5;
    } else if (f5 < first_min) {
        second_min = first_min;
        first_min = f5;
    } else if (f5 < second_min) {
        second_min = f5;
    }

    printf("Thank you, enjoy your result!\n");
	printf("Abs sum: %.2f\n", abs_sum);
    printf("Abs dif: %.2f\n", abs_dif);
	printf("Max sum: %.2f\n", first_max + second_max);
	printf("Min sum: %.2f\n", first_min + second_min);
    return 0;
}