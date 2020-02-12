//
// Created by Amos on 2020/02/02.
//

#include <iostream>
#include <climits>
#include <vector>
#include <utility>

using namespace std;

int N;
vector<vector<int>> dp;
vector<pair<int, int>> matrix;

int solve(int start, int end) {
    if (dp[start][end] != -1) {
        return dp[start][end];
    }

    if (start == end) {
        return 0;
    }

    if (start + 1 == end) {
        return matrix[start].first * matrix[start].second * matrix[end].second;
    }

    int min = INT_MAX;
    for (int k = start; k < end; k++) {
        dp[start][k] = solve(start, k);
        dp[k + 1][end] = solve(k + 1, end);

        dp[start][end] = dp[start][k] + dp[k + 1][end] + matrix[start].first * matrix[k].second * matrix[end].second;

        if (min > dp[start][end]) {
            min = dp[start][end];
        }
    }

    return min;
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        int row, col;
        cin >> row >> col;
        matrix.push_back(make_pair(row, col));
    }

    dp = vector<vector<int>>(N, vector<int>(N, -1));

    cout << solve(0, N - 1) << '\n';

    return 0;
}
