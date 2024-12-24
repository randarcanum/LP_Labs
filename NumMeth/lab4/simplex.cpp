#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>
using namespace std;
int main() {
    ifstream input("simplex.txt");
    vector<vector<double>> massiv;
    string eq;
    while (getline(input, eq)) {
        vector<double> mi;
        stringstream seq(eq);
        double n;
        while(seq >> n) mi.push_back(n);
        massiv.push_back(mi);
    }
    input.close();
    int n = massiv.front().size()-1;
    transform(massiv.back().begin(), massiv.back().end(), massiv.back().begin(), [&](double x) {return -1*x;});
    massiv.back().push_back(0);
    for (int i = 0; i < massiv.size(); i++) {
        double t = massiv[i].back();
        massiv[i].pop_back();
        for (int j = 0; j < massiv.size()-1; j++)
            if (i == j) massiv[i].push_back(1);
            else massiv[i].push_back(0);
        massiv[i].push_back(t);
    }
    vector<double>::iterator col = min_element(massiv.back().begin(), massiv.back().end());
    vector<vector<int>> ji;
    do {
        vector<int> ji_k;
        ji_k.push_back(distance(massiv.back().begin(), col));
        vector<double> extract;
        for (vector<double> x : massiv) extract.push_back(x[ji_k.back()]/x.back());
        extract.pop_back();
        ji_k.push_back(distance(extract.begin(), max_element(extract.begin(), extract.end())));
        ji.push_back(ji_k);
        double el = massiv[ji_k.back()][ji_k.front()];
        transform(massiv[ji_k.back()].begin(), massiv[ji_k.back()].end(), massiv[ji_k.back()].begin(), [&](double x) {return x / el;});
        transform(massiv.begin(), massiv.end(), massiv.begin(), [&](vector<double> x) {
            double elx = x[ji_k.front()];
            if (x != massiv[ji_k.back()]) transform(x.begin(), x.end(), massiv[ji_k.back()].begin(), x.begin(), [&](double z, double y) {return z - y*elx;});
            return x;
        });
        col = min_element(massiv.back().begin(), massiv.back().end());
    } while (*col < 0);
    vector<double> res(n, 0);
    for (vector<double> i : massiv) res.push_back(i.back());
    for (vector<int> k : ji) swap(res[k.front()], res[k.back()+n]);
    ofstream output("simplex_res.txt");
    for (int i = 0; i < massiv.front().size()-1; i++) output << res[i] << " ";
    output << massiv.back().back();
    output.close();
}