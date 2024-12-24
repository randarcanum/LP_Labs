#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>
using namespace std;
int main() {
    vector<double> arr, bank, random, alt;
    srand(time(0));
    for (int i = 0; i < 5000; i++) arr.push_back(rand()/10.0);
    for (double x : arr) {
        static bool flag = true;
        if (x-trunc(x) == 0.5) {
            if ((int) trunc(x) % 2) bank.push_back(ceil(x));
            else bank.push_back(floor(x));
            if (rand() % 2) random.push_back(ceil(x));
            else random.push_back(floor(x));
            if (flag) {
                flag = false;
                alt.push_back(ceil(x));
            } else {
                flag = true;
                alt.push_back(floor(x));
            }
        } else {
            bank.push_back(round(x));
            random.push_back(round(x));
            alt.push_back(round(x));
        }
    }
    ofstream f_arr("array.txt"), f_bank("bank.txt"), f_random("random.txt"), f_alt("alt.txt");
    for (double x : arr) f_arr << x << endl;
    for (double x : bank) f_bank << x << endl;
    for (double x : random) f_random << x << endl;
    for (double x : alt) f_alt << x << endl;
    f_arr.close();
    f_bank.close();
    f_random.close();
    f_alt.close();
    sort(arr.begin(), arr.end());
    vector<double> quant {0.25, 0.5, 0.75};
    transform(quant.begin(), quant.end(), quant.begin(), [&](double x) {
        double k = (arr.size()-1)*x;
        if (ceil(k) == floor(k)) return arr[(int) k];
        else return arr[(int) ceil(k)]*(ceil(k)-k) - arr[(int) floor(k)]*(floor(k)-k);
    });
    double av = reduce(arr.begin(), arr.end()) / arr.size();
    double av_b = reduce(bank.begin(), bank.end()) / bank.size();
    double av_r = reduce(random.begin(), random.end()) / random.size();
    double av_a = reduce(alt.begin(), alt.end()) / alt.size();
    printf("%-13s%.2f\n", "Average:", av);
    printf("%-13s%.2f\n", "Range:", arr.back()-arr.front());
    printf("%-13s%.2f\n", "25% quant.:", quant[0]);
    printf("%-13s%.2f\n", "Median:", quant[1]);
    printf("%-13s%.2f\n", "75% quant.:", quant[2]);
    printf("%-13s%.5f\n", "d(Bank av.):", abs(av-av_b));
    printf("%-13s%.5f\n", "d(Rand av.):", abs(av-av_r));
    printf("%-13s%.5f\n", "d(Alt. av.):", abs(av-av_a));
}