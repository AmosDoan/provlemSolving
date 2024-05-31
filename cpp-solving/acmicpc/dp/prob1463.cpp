//
// Created by Amos on 2020/02/09.
//

#include <iostream>
#include <vector>

#define MAX 9876543210

using namespace std;

int N;
vector<int> dp;

long solve(int current) {
    if (current == 1) {
        return dp[1];
    }

    long min = MAX;
    if (current % 2 == 0) {
        if (dp[current / 2] == 0) {
            dp[current / 2] = solve(current / 2);
        }
        if (dp[current / 2] < min) {
            min = dp[current / 2];
        }
    }

    if (current % 3 == 0) {
        if (dp[current / 3] == 0) {
            dp[current / 3] = solve(current / 3);
        }
        if (dp[current / 3] < min) {
            min = dp[current / 3];
        }
    }

    if (current - 1 > 0) {
        if (dp[current - 1] == 0) {
            dp[current - 1] = solve(current - 1);
        }
        if (dp[current - 1] < min) {
            min = dp[current - 1];
        }
    }

    return min + 1;
}

int main() {
    cin >> N;

    dp.resize(N + 1, 0);
    dp[1] = 0;

    cout << solve(N) << '\n';

    return 0;
}