//
// Created by Amos on 2020/02/21.
//
#include <iostream>
#include <vector>

using namespace std;

int N, K, min_unit;
vector<int> coins;
vector<int> dp;

int solve() {
    dp[0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K + 1; j++) {
            if (j - coins[i] >= 0) {
                dp[j] += dp[j - coins[i]];
            }
        }
    }
    return dp[K];
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

    dp.resize(K + 1, 0);

    cout << solve() << '\n';

    return 0;
}
