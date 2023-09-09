#include <iostream>
using namespace std;
int rep(char *s, int l, char *s1, int l1, char *s2, int l2) {
    int j, q = 0, r = 0, i = 0;
    char snew[255];
    while (i < l) {
        snew[q] = s[i];
        if (s[i] == s1[0]) {
            j = 0;
            while (s[i+j] == s1[j] && j < l1 && i+j < l) {
                j++;
            }
            if (j == l1) {
                for (int k = 0; k < l2; k++) {
                    snew[k+q] = s2[k];
                }
                i += l1-1;
                q += l2-1;
                r++;
            }
        }
        i++;
        q++;
    }
    for (int i = 0; i < q; i++) {
        s[i] = snew[i];
    }
    return r;
}
int len(char *s) {
    int j = 0;
    do {
        j++;
    } while (s[j] != '\0');
    return j;
}
int main() {
    char str[255], str1[255], str2[255];
    cout << "String: ";
    cin >> str;
    cout << "Find: ";
    cin >> str1;
    cout << "Replace: ";
    cin >> str2;
    cout << "Replaced " << rep(str, len(str), str1, len(str1), str2, len(str2)) << " times" << endl;
    cout << "Result string: " << str << endl;
    return 0;
}