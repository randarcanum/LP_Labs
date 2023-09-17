#include <iostream>
#include <fstream>
using namespace std;
struct user {
    char *lname, *fname, *mname, *sex;
    char *block;
    unsigned char *age;
    unsigned short *uses;
    void print() {
        if (lname) cout << "Last name:   " << lname << endl;
        if (fname) cout << "First name:  " << fname << endl;
        if (mname) cout << "Middle name: " << mname << endl;
        if (age)   cout << "Age:         " << *age << endl;
        if (sex)   cout << "Sex:         " << *sex << endl;
        if (uses)  cout << "Uses number: " << *uses << endl;
    }
};
char readfile(user *&out) {
    char n, blen, *p;
    ifstream data("UserData-LR-5.bin", ios::binary);
    data.read(&n, 1);
    out = new user[n];
    for (char i = 0; i < n; i++) {
        data.seekg(1, ios::cur);
        data.read(&blen, 1);
        out[i].block = new char[blen];
        data.read(out[i].block, blen);
        p = out[i].block;
        while (p < out[i].block + blen) {
            switch(*p) {
                case 1:
                    out[i].lname = p+2;
                    break;
                case 2:
                    out[i].fname = p+2;
                    break;
                case 3:
                    out[i].mname = p+2;
                    break;
                case 4:
                    out[i].age = (unsigned char*)p+2;
                    break;
                case 5:
                    out[i].sex = p+2;
                    break;
                case 6:
                    out[i].uses = (unsigned short*)p+2;
                    break;
            }
            p += *(p+1)+2;
        }
    }
    data.close();
    return n;
}
int main() {
    char ch;
    user *users;
    char total = readfile(users);
    while (1) {
        cin >> ch;
        switch (ch) {
            case 'a':
            case 'A':
                for (char i = 0; i < total; i++) {
                    cout << "User N" << i+1 << ":" << endl;
                    users[i].print();
                }
                break;
            case '0' ... '9':
                if (ch-48 < total) {
                    cout << "User N" << ch-47 << ":" << endl;
                    users[ch-48].print();
                }
                else cout << "User N" << ch-47 << " does not exist" << endl;
                break;
            case 'e':
            case 'E':
                for (char i = 0; i < total; i++) {
                    delete[] users[i].block;
                }
                delete[] users;
                return 0;
        }
    }
}