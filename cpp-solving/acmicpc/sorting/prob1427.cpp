//
// Created by Amos on 2020/04/05.
//
#include <iostream>
#include <algorithm>

using namespace std;

string N;

int main() {
    cin >> N;
    sort(N.begin(), N.end(), greater<int>());
    cout << N << '\n';
}
