//
// Created by Amos on 2020/01/30.
//

#include <iostream>
#include <vector>
#include <set>

#define MAX_APP 100
#define MAX_COST 100
#define MAX_TOTAL_COST MAX_APP * MAX_COST

#define MAX(a, b) a > b ? a : b

using namespace std;

int N;
int M;
int app_memory[MAX_APP];
int app_cost[MAX_APP];
vector<vector<int>> dp;

int solve() {
    int min_cost = MAX_COST;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < MAX_TOTAL_COST; j++) {
            dp[i][j] = MAX(app_memory[i] + dp[i - 1][j - app_cost[i]],
                           dp[i - 1][j]);

            if (dp[i][j] >= M && j < min_cost) {
                min_cost = j;
            }
        }
    }

    return min_cost;
}

int main() {
    cin >> N >> M;

    dp = vector<vector<int>>(N, vector<int>(MAX_TOTAL_COST, -1));

    for (int i = 1; i <= N; i++) {
        int memory;
        cin >> memory;
        app_memory[i] = memory;
    }

    int total_cost = 0;
    for (int i = 1; i <= N; i++) {
        int cost;
        cin >> cost;
        app_cost[i] = cost;
    }

    cout << solve() << '\n';

    return 0;
}
