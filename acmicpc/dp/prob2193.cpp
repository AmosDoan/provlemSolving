//
// Created by Amos on 2020/04/03.
//
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<long long>> cache;

long long solve() {
    if (N <= 2) {
        return 1;
    }

    cache[1][1] = 1;
    cache[2][0] = 1;

    for (int i = 3; i <= N; i++) {
        cache[i][0] = cache[i - 1][0] + cache[i - 1][1];
        cache[i][1] = cache[i - 1][0];
    }

    return cache[N][0] + cache[N][1];
}

int main() {
    cin >> N;
    cache.resize(N + 1, vector<long long>(2, 0));

    cout << solve() << '\n';

    return 0;
}
