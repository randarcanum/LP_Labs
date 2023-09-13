#include <iostream>
#include <fstream>
using namespace std;
struct user {
    char *lname = nullptr, *fname = nullptr, *mname = nullptr, *sex = nullptr;
    unsigned char *age = nullptr;
    unsigned short *uses = nullptr;
    void print() {
        if (lname) cout << "Last name:   " << lname << endl;
        if (fname) cout << "First name:  " << fname << endl;
        if (mname) cout << "Middle name: " << mname << endl;
        if (age)   cout << "Age:         " << *age << endl;
        if (sex)   cout << "Sex:         " << *sex << endl;
        if (uses)  cout << "Uses number: " << *uses << endl;
    }
    void release() {
        delete[] lname;
        delete[] fname;
        delete[] mname;
        delete age;
        delete sex;
        delete uses;
    }
};
char readfile(user *&out) {
    char n, m, len, blen;
    ifstream data("UserData-LR-5.bin", ios::binary);
    data.read(&n, 1);
    out = new user[n];
    for (char i = 0; i < n; i++) {
        data.read(&m, 1);
        data.read(&blen, 1);
        for (char j = 0; j < 6; j++) {
            if (blen <= 0) break;
            data.read(&m, 1);
            data.read(&len, 1);
            blen -= len+2;
            switch(m) {
                case 1:
                    out[i].lname = new char[len];
                    data.read(out[i].lname, len);
                    break;
                case 2:
                    out[i].fname = new char[len];
                    data.read(out[i].fname, len);
                    break;
                case 3:
                    out[i].mname = new char[len];
                    data.read(out[i].mname, len);
                    break;
                case 4:
                    out[i].age = new unsigned char;
                    data.read((char*)out[i].age, 1);
                    break;
                case 5:
                    out[i].sex = new char;
                    data.read(out[i].sex, 1);
                    break;
                case 6:
                    out[i].uses = new unsigned short;
                    data.read((char*)out[i].uses, 2);
                    break;
            }
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
                    users[i].release();
                }
                delete[] users;
                return 0;
        }
    }
}