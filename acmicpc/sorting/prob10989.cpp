//
// Created by Amos on 2020/04/05.
//
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    vector<int> ret;
    ret.reserve(N);
    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;
        ret.push_back(n);
    }

    sort(ret.begin(), ret.end());

    for (auto elem : ret) {
        cout << elem << '\n';
    }
    return 0;
}
