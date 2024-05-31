//
// Created by Amos on 2020/02/10.
//

#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> dp;

int solve() {
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i < N + 1; i++) {
        dp[i] = dp[i - 1] % 10007 + dp[i - 2] % 10007;
    }

    return dp[N] % 10007;
}

int main() {
    cin >> N;

    dp.resize(N + 1, 0);

    cout << solve() << '\n';

    return 0;
}


