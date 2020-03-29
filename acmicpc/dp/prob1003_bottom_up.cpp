//
// Created by Amos on 2020/03/30.
//
#include <iostream>
#include <vector>

using namespace std;

int T;
vector<vector<int>> cache;

void solve(int current) {
    cache.resize(41, vector<int>(2, 0));

    cache[0][0] = 1;
    cache[0][1] = 0;

    cache[1][0] = 0;
    cache[1][1] = 1;

    for (int i = 2; i <= current; i++) {
        cache[i][0] = cache[i - 1][0] + cache[i - 2][0];
        cache[i][1] = cache[i - 1][1] + cache[i - 2][1];
    }

    cout << cache[current][0] << ' ' << cache[current][1] << '\n';
}

int main() {
    cin >> T;

    for (int i = 0; i < T; i++) {
        int N;
        cin >> N;
        solve(N);
    }

    return 0;
}
