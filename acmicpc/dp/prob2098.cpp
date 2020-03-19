//
// Created by Amos on 2020/03/19.
//
#include <iostream>
#include <vector>

#define MAX 1000000 * 11

using namespace std;

int N;
vector<vector<int>> map;
int visit;
vector<vector<int>> dp;

int traverse(int current, int level, int cost) {

    if ((visit & (1 << current)) != 0) {
        return MAX;
    }

    if (level == N - 1) {
        if (map[current][0] == 0) {
            return MAX;
        }
        return cost + map[current][0];
    }

    visit |= (1 << current);

    int &ret = dp[current][visit];
    if (ret != -1) {
        return ret;
    }

    int min = MAX;
    for (int i = 0; i < N; i++) {
        if (map[current][i] != 0 && (visit & (1 << i)) != 1) {
            int temp = traverse(i, level + 1, cost + map[current][i]);
            if (temp < min) {
                min = temp;
            }
        }
    }

    // Backtracking
    visit |= (0 << current);
    return ret = min;
}

int main() {
    cin >> N;
    map.resize(N, vector<int>(N, 0));
    visit = 0;
    dp.resize(N, vector<int>(1 << (N + 1), -1));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int w;
            cin >> w;
            map[i][j] = w;
        }
    }

    cout << traverse(0, 0, 0) << '\n';

    return 0;
}

