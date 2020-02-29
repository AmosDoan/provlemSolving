//
// Created by Amos on 2020/02/29.
//

#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<int>> dp;
vector<int> p;

int solve() {
    for (int i = 1; i < N + 1; i++) {
        for (int j = 0; j < N + 1; j++) {
            dp[i][j] = dp[i - 1][j];

            if (i <= j) {
                int number_of_current = j / i;
                int when_current_using = number_of_current * p[i - 1] + dp[i - 1][j - number_of_current * i];

                dp[i][j] = max(dp[i][j], when_current_using);
            }
        }
    }

    /*
    for (int i = 0; i < N + 1; i++) {
        for (int j = 0; j < N + 1; j++) {
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }
    */

    return dp[N][N];
}

int main() {
    cin >> N;

    for(int i = 0; i < N; i++) {
        int cost;
        cin >> cost;
        p.push_back(cost);
    }

    dp.resize(N + 1, vector<int>(N + 1, 0));

    cout << solve() << '\n';

    return 0;
}
