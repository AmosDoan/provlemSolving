//
// Created by Amos on 2020/02/21.
//
#include <iostream>
#include <vector>

using namespace std;

int N, K, nr_dp_unit, min_unit;
vector<int> coins;
// dp[i][j] : j번째 Coin까지 사용하여 i원을 만들 수 있는 가짓수
vector<vector<int>> dp;

int solve() {
    // Initialize
    for (int i = 1; i < N + 1; i++) {
        dp[0][i] = 1;
    }

    // DP
    for (int i = 1; i < nr_dp_unit + 1; i++) {
        for (int j = 1; j < N + 1; j++) {
            int current_cost = i * min_unit;
            int left_cost = current_cost - coins[j - 1];

            dp[i][j] = dp[i][j - 1];

            if (left_cost >= 0) {
                dp[i][j] += dp[left_cost / min_unit][j];
            }
        }
    }

    /*
    for (int i = 1; i < nr_dp_unit + 1; i++) {
        for (int j = 1; j < N + 1; j++) {
            cout << dp[i][j] << " ";
        }
        cout << '\n';
    }
    */

    return dp[nr_dp_unit][N];
}

int main() {

    cin >> N >> K;

    min_unit = 100001;
    for(int i = 0; i < N; i++) {
        int coin;
        cin >> coin;
        coins.push_back(coin);

        if (coin < min_unit) {
            min_unit = coin;
        }
    }

    if (min_unit > K) {
        cout << 0 << '\n';
        return 0;
    }

    nr_dp_unit = K / min_unit;
    dp.resize(nr_dp_unit + 1, vector<int>(N + 1, 0));

    cout << solve() << '\n';

    return 0;
}
