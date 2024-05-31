//
// Created by Amos on 2020/03/07.
//
#include <iostream>
#include <vector>

#define DIV 1000000000

int N;

using namespace std;

vector<vector<long>> dp;

long solve() {
    for (int i = 0; i < 10; i++) {
        dp[0][i] = 1;
    }

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < 10; j++) {
            if (j > 0) {
                dp[i][j] = dp[i - 1][j - 1] % DIV;
            }

            if (j < 9) {
                dp[i][j] += dp[i - 1][j + 1] % DIV;
            }
        }
    }

    /*
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 10; j++) {
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }
    */

    long result = 0;
    for (int i = 1; i < 10; i++) {
        result += dp[N - 1][i] % DIV;
    }

    return result % DIV;
}

int main() {
    cin >> N;

    dp.resize(N, vector<long>(10, 0));

    cout << solve() << '\n';

    return 0;
}
