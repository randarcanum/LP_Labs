#include <stdio.h>

int main(){
    int a;
    float b;
    printf("Dec: ");
    scanf("%d", &a);
    printf("Float: ");
    scanf("%f", &b);
    printf("\nOct: %o\n", a);
    printf("Hex: %X\n", a);
    printf("New float: %.3f", b);
    return 0;
}