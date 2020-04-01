//
// Created by Amos on 2020/04/01.
//
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    vector<int> v;

    int N;

    cin >> N;

    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    sort(v.begin(), v.end());

    for (auto elem : v) {
        cout << elem << '\n';
    }

    return 0;
}
