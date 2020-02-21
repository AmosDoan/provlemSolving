//
// Created by Amos on 2020/02/21.
//
#include <iostream>
#include <vector>

using namespace std;

int N, K, min_unit;
vector<int> coins;
// dp[i][j] : j번째 Coin 까지 사용하여 i원을 만들 수 있는 가짓수
vector<vector<int>> dp;

// 메모리 초과
int solve() {
    // Initialize
    for (int i = 0; i < N + 1; i++) {
        dp[0][i] = 1;
    }

    // DP
    for (int i = 1; i < K + 1; i++) {
        for (int j = 1; j < N + 1; j++) {
            // j 번째 Coin 사용 X
            dp[i][j] = dp[i][j - 1];

            // j 번째 Coin 사용 O
            if (i - coins[j - 1] >= 0) {
                dp[i][j] += dp[i - coins[j - 1]][j];
            }
        }
    }

    /*
    for (int i = 1; i < K; i++) {
        for (int j = 1; j < N + 1; j++) {
            cout << dp[i][j] << " ";
        }
        cout << '\n';
    }
    */

    return dp[K][N];
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

    dp.resize(K + 1, vector<int>(N + 1, 0));

    cout << solve() << '\n';

    return 0;
}
