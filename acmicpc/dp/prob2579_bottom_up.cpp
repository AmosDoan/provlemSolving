//
// Created by Amos on 2020/05/24.
//
#include <iostream>
#include <climits>
#include <vector>

using namespace std;

int N;
vector<int> stairs;
vector<vector<int>> dp;

int solve() {
    dp.resize(N, vector<int>(2, -1));

    dp[0][0] = 0;
    dp[0][1] = stairs[0];
    dp[0][2] = stairs[0];

    for (int i = 1; i < N; i++) {
        dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] = dp[i - 1][0] + stairs[i];
        dp[i][2] = dp[i - 1][1] + stairs[i];
    }

    return max(dp[N - 1][1], dp[N - 1][2]);
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        int stair;
        cin >> stair;
        stairs.push_back(stair);
    }

    cout << solve() << '\n';

    return 0;
}
