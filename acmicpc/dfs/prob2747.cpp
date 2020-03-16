//
// Created by Amos on 2020/03/16.
//
#include <iostream>
#include <vector>

using namespace std;

vector<int> dp;

int solve(int n) {
    if (n == 0) {
        return 0;
    }

    if (n == 1 || n == 2) {
        return 1;
    }

    int &ret = dp[n];

    if (ret != -1) {
        return ret;
    }

    return ret = solve(n - 1) + solve(n - 2);
}

int main() {
    int N;

    cin >> N;
    dp.resize(N + 1, -1);

    cout << solve(N) << '\n';

    return 0;
}
