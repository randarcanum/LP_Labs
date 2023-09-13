#include <iostream>
using namespace std;
int len(char *s) {
    int j = 0;
    do {
        j++;
    } while (s[j] != '\0');
    return j;
}
int main() {
    char str[256];
    cout << "Enter string: ";
    cin >> str;
    cout << "String length = " << len(str) << endl;
    return 0;
}