//
// Created by Amos on 2020/03/14.
//
#include <iostream>
#include <vector>

#define MAX 1000000 * 11

using namespace std;

int N;
vector<vector<int>> map;
vector<vector<int>> dp;

int traverse(unsigned int current, unsigned int visit) {
    if (visit == (1u << N) - 1) {
        if (map[current][0] == 0) {
            return MAX;
        }
        return map[current][0];
    }

    int &ret = dp[current][visit];
    if (ret != -1) {
        return ret;
    }

    int min = MAX;
    for (int i = 0; i < N; i++) {
        if (map[current][i] != 0 && (visit & (1u << i)) == 0) {
            int temp = traverse(i, visit | (1u << i)) + map[current][i];
            if (temp < min) {
                min = temp;
            }
        }
    }

    return ret = min;
}

int main() {
    cin >> N;
    map.resize(N, vector<int>(N, -1));

    int visit_size = (1 << N) - 1;
    dp.resize(N, vector<int>(visit_size, -1));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int w;
            cin >> w;
            map[i][j] = w;
        }
    }

    cout << traverse(0, 1) << '\n';

    return 0;
}
