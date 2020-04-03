//
// Created by Amos on 2020/04/03.
//
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<int>> numbers;
vector<vector<int>> cache;

int solve(int y, int x) {
    if (y == N) {
        return numbers[y][x];
    }

    int &ret = cache[y][x];
    if (ret != -1) {
        return ret;
    }

    return ret = max(solve(y + 1, x), solve(y + 1, x + 1)) + numbers[y][x];
}

int main() {
    cin >> N;
    numbers.resize(N + 1, vector<int>(N + 1, 0));
    cache.resize(N + 1, vector<int>(N + 1, -1));

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j < i + 1; j++) {
            int c;
            cin >> c;
            numbers[i][j] = c;
        }
    }

    cout << solve(0, 0) << '\n';

    return 0;
}
