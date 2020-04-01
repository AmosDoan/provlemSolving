//
// Created by Amos on 2020/04/01.
//
#include <iostream>
#include <vector>

using namespace std;

int T;

long long solve(int num, vector<long long> &cache) {
    if (num <= 0) {
        return 0;
    }

    if (num == 1 || num == 2) {
        return 1;
    }

    long long &ret = cache[num];
    if (ret != -1) {
        return ret;
    }

    return ret = solve(num - 2, cache) + solve(num - 3, cache);
}

int main() {
    cin >> T;

    for (int i = 0; i < T; i++) {
        int n;
        cin >> n;
        vector<long long> cache(n + 1, -1);
        cout << solve(n, cache) << '\n';
    }

    return 0;
}
