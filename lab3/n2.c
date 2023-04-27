#include <stdio.h>

int main() {
    unsigned int p;
    char bits[32];
    printf("Your number: ");
    scanf("%u", &p);
    int q = 0;
    while (p > 0) {
        bits[q] = p % 2;
        p = p / 2;
        q++;
    }
    printf("Binary: ");
    for (int i = q - 1; i >= 0; --i) {
        printf("%d", bits[i]);
    }
    printf("\n");
    return 0;
}