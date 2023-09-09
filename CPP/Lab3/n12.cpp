#include <iostream>
using namespace std;
char *glue(char *s1, int l1, char *s2, int l2) {
    static char str[255];
    for (int i = 0; i < l1; i++) {
        str[i] = s1[i];
    }
    for (int i = l1; i < l1+l2; i++) {
        str[i] = s2[i-l1];
    }
    return str;
}
int len(char *s) {
    int j = 0;
    do {
        j++;
    } while (s[j] != '\0');
    return j;
}
int main() {
    char str1[255], str2[255];
    cout << "First string: ";
    cin >> str1;
    int i1 = len(str1);
    cout << "Length = " << i1 << endl;
    cout << "Second string: ";
    cin >> str2;
    int i2 = len(str2);
    cout << "Length = " << i2 << endl;
    cout << "Concat string: " << glue(str1, i1, str2, i2) << endl;
    return 0;
}