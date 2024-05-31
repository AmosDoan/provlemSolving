//
// Created by Amos on 2020/04/03.
//
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<int>> cost;
vector<vector<int>> cache;

int solve() {

    for (int i = 1; i <= N; i++) {
        cache[i][0] = min(cache[i - 1][1], cache[i - 1][2]) + cost[i][0];
        cache[i][1] = min(cache[i - 1][0], cache[i - 1][2]) + cost[i][1];
        cache[i][2] = min(cache[i - 1][0], cache[i - 1][1]) + cost[i][2];
    }

    int ret = min(cache[N][0], cache[N][1]);
    ret = min(ret, cache[N][2]);

    return ret;
}

int main() {
    cin >> N;
    cache.resize(N + 1, vector<int>(3 , 0));
    cost.resize(N + 1, vector<int>(3, 0));

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < 3; j++) {
            int c;
            cin >> c;
            cost[i][j] = c;
        }
    }

    cout << solve() << '\n';

    return 0;
}

