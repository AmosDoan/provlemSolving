//
// Created by Amos on 2020/01/13.
//
#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int M, N;
vector<vector<int>> map;
// x, y, level
queue<pair<pair<int, int>, int>> q;
vector<pair<int, int>> tomato;

int d_row[4] = {1, -1, 0, 0};
int d_col[4] = {0, 0, 1, -1};

int solve() {
    int current_time = 0;
    while (!q.empty()){
        pair<pair<int, int>, int> current = q.front();
        q.pop();

        int current_row = current.first.first;
        int current_col = current.first.second;
        current_time = current.second;

        for (int i = 0; i < 4; i++) {
            int next_row = current_row + d_row[i];
            int next_col = current_col + d_col[i];

            if (next_row >= 0 && next_row < N && next_col < M && next_col >= 0
                && map[next_row][next_col] == 0) {
                q.push(make_pair(make_pair(next_row, next_col), current_time + 1));
                map[next_row][next_col] = 1;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 0) {
                current_time = -1;
                break;
            }
        }
    }

    return current_time;
}

int main() {
    cin >> M >> N;

    for (int i = 0; i < N; i++) {
        vector<int> v = vector<int>();
        for (int j = 0; j < M; j++) {
            int number;
            cin >> number;
            v.push_back(number);

            if (number == 1) {
                tomato.push_back(make_pair(i, j));
            }
        }
        map.push_back(v);
    }

    for (auto it : tomato) {
        q.push(make_pair(make_pair(it.first, it.second), 0));
    }

    cout << solve() << '\n';

    return 0;
}