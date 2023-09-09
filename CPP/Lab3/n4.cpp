#include <iostream>
using namespace std;
int len(char *s) {
    int j = 0;
    do {
        j++;
    } while (s[j] != '\0');
    return j;
}
bool comp(char *s1, char *s2) {
    int j = len(s1);
    if (j == len(s2)) {
        for (int i = 0; i < j; i++) {
            if (s1[i] != s2[i]) return 0;
        }
        return 1;
    } else return 0;
}
int main() {
    char str1[255], str2[255];
    cout << "First string: ";
    cin >> str1;
    cout << "Second string: ";
    cin >> str2;
    if (comp(str1, str2)) cout << "Strings are equal" << endl;
    else cout << "Strings are not equal" << endl;
    return 0;
}