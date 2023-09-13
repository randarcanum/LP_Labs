#include <iostream>
#include <fstream>
using namespace std;
struct user {
    char fname[256], lname[256], mname[256];
    char age, sex, n;
    short uses;
    bool fl[6] = {0, 0, 0, 0, 0, 0};
public:
    void print() {
        cout << "User N" << +n << ":" << endl;
        if (fl[0]) cout << "Last name:    " << lname << endl;
        if (fl[1]) cout << "First name:   " << fname << endl;
        if (fl[2]) cout << "Middle name:  " << mname << endl;
        if (fl[3]) cout << "Age:          " << +age << endl;
        if (fl[4]) cout << "Sex:          " << sex << endl;
        if (fl[5]) cout << "Access times: " << uses << endl;
    }
};
char readfile(user *out) {
    char n, m, len, blen;
    ifstream data("UserData-LR-5.bin", ios::binary);
    data.read(&n, 1);
    for (char i = 0; i < n; i++) {
        data.read(&out[i].n, 1);
        data.read(&blen, 1);
        for (char j = 0; j < 6; j++) {
            data.read(&m, 1);
            data.read(&len, 1);
            blen -= len+2;
            switch(m) {
                case 1:
                    out[i].fl[0] = 1;
                    data.read(out[i].lname, len);
                    break;
                case 2:
                    out[i].fl[1] = 1;
                    data.read(out[i].fname, len);
                    break;
                case 3:
                    out[i].fl[2] = 1;
                    data.read(out[i].mname, len);
                    break;
                case 4:
                    out[i].fl[3] = 1;
                    data.read(&out[i].age, 1);
                    break;
                case 5:
                    out[i].fl[4] = 1;
                    data.read(&out[i].sex, 1);
                    break;
                case 6:
                    out[i].fl[5] = 1;
                    data.read((char*)&out[i].uses, 2);
                    break;
            }
            if (blen < 1) continue;
        }
    }
    data.close();
    return n;
}
int main() {
    char ch;
    user users[10];
    unsigned char total = readfile(users);
    while (1) {
        cin >> ch;
        switch (ch) {
            case 'a':
            case 'A':
                for (char i = 0; i < total; i++) {
                    users[i].print();
                }
                break;
            case '0' ... '9':
                if (ch-48 < total) users[ch-48].print();
                else cout << "User N" << ch-47 << " does not exist" << endl;
                break;
            case 'e':
            case 'E':
                return 0;
        }
    }
}