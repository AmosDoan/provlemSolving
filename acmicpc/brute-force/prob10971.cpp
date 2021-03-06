//
// Created by Amos on 2020/03/14.
//
#include <iostream>
#include <vector>

#define MAX 1000000 * 11

using namespace std;

int N;
vector<vector<int>> map;
vector<int> visit;

int traverse(int current, int level, int cost) {

    if (visit[current] != 0) {
        return MAX;
    }

    if (level == N - 1) {
        if (map[current][0] == 0) {
            return MAX;
        }
        return cost + map[current][0];
    }

    visit[current] = 1;

    int min = MAX;
    for (int i = 0; i < N; i++) {
        if (map[current][i] != 0 && visit[i] != 1) {
            int temp = traverse(i, level + 1, cost + map[current][i]);
            if (temp < min) {
                min = temp;
            }
        }
    }

    // Backtracking
    visit[current] = 0;
    return min;
}

int main() {
    cin >> N;
    map.resize(N, vector<int>(N, -1));
    visit.resize(N, 0);

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
