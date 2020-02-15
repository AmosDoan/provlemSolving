//
// Created by Amos on 2020/02/15.
//
#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<string> map;
vector<vector<int>> dp;

int solve() {
    int max_square = 0;
    for (int col = 0; col < M; col++) {
        dp[0][col] = map[0][col] - '0';
        if (dp[0][col] > max_square) {
            max_square = dp[0][col];
        }
    }

    for (int row = 0; row < N; row++) {
        dp[row][0] = map[row][0] - '0';
        if (dp[row][0] > max_square) {
            max_square = dp[row][0];
        }
    }

    for (int row = 1; row < N; row++) {
        for (int col = 1; col < M; col++) {
            if (map[row][col] == '0') {
                dp[row][col] = 0;
            } else {
                int candidate_1 = dp[row - 1][col - 1];
                int candidate_2 = dp[row - 1][col];
                int candidate_3 = dp[row][col - 1];

                if (candidate_1 == candidate_2 && candidate_1 == candidate_3) {
                    dp[row][col] = candidate_1 + 1;
                } else if (candidate_1 == 0 || candidate_2 == 0 || candidate_3 == 0) {
                    dp[row][col] = 1;
                } else {
                    int min = candidate_2 < candidate_3 ? candidate_2 : candidate_3;
                    min = min < candidate_1 ? min : candidate_1;
                    dp[row][col] = min + 1;
                }

                if (dp[row][col] > max_square) {
                    max_square = dp[row][col];
                }
            }
        }
    }

    /*
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }
    */

    return max_square * max_square;
}

int main() {
    cin >> N >> M;

    dp.resize(N, vector<int>(M, 0));

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        map.push_back(s);
    }

    cout << solve() << '\n';

    return 0;
}
