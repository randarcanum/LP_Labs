#include <iostream>
#include <cstdlib>
using namespace std;
void fill(int x, int *m, int n) {
    switch(x) {
        case 0:
            for (int i = 0; i < n; i++) {
                cin >> m[i];
            }
            break;
        case 1:
            srand(time(0));
            for (int i = 0; i < n; i++) {
                m[i] = rand();
                cout << m[i] << ' ';
            }
            cout << endl;
            break;
        default:
            cout << "Invalid option. Exiting..." << endl;
            break;
    }
}
int minmax(int *m, int n) {

}
int main() {
    int len, inp;
    cout << "Array length: ";
    cin >> len;
    int *arr = new int[len];
    cout << "Choose option:" << endl;
    cout << "0: Keyboard input" << endl;
    cout << "1: Random input" << endl;
    cin >> inp;
    fill(inp, arr, len);
    cout << minmax(arr, len) << endl;
    delete[] arr;
}