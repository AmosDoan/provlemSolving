//
// Created by Amos on 2020/03/14.
//
#include <iostream>
#include <vector>

#define DIV_NUM 10007

using namespace std;

int N;
vector<vector<int>> dp;

int solve() {
    if (N == 0) {
        return 0;
    }

    for (int i = 0; i < 10; i++) {
        dp[1][i] = 1;
    }

    for (int i = 2; i <= N; i++) {
        for (int j = 0; j < 10; j++) {
            dp[i][j] = dp[i - 1][j] % DIV_NUM + dp[i][j - 1] % DIV_NUM;
        }
    }

    int sum = 0;
    for (int i = 0; i < 10; i++) {
        sum += dp[N][i] % DIV_NUM;
    }
    return sum % DIV_NUM;
}

int main() {
    cin >> N;

    dp.resize(N + 1, vector<int>(10, 0));

    cout << solve() << '\n';

    return 0;
}
