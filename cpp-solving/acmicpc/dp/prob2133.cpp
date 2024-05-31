//
// Created by Amos on 2020/02/28.
//
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> dp;

int solve() {
    dp[2] = 3;
    for (int i = 4; i < N + 1; i += 2) {
        dp[i] = 3 * dp[i - 2] + 2;

        for (int j = 4; j < i; j += 2) {
            dp[i] += 2 * dp[i -j];
        }
    }

    /*
    for (int i = 0; i < N + 1; i++) {
        cout << dp[i] << ' ';
    }
    cout << '\n';
    */

    return dp[N];
}

int main() {
    cin >> N;
    dp.resize(N + 1, 0);

    cout << solve() << '\n';

    return 0;
}
