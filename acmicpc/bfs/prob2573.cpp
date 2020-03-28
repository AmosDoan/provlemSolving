//
// Created by Amos on 2020/03/28.
//
#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int N, M;
vector<vector<int>> map;
pair<int, int> start = {0, 0};
queue<pair<int, int>> q;

int d_row[4] = {-1, 1, 0, 0};
int d_col[4] = {0, 0, -1, 1};

int bfs() {
    vector<vector<int>> visit = vector<vector<int>>(N, vector<int>(M, 0));

    visit[start.first][start.second] = 1;

    while (!q.empty()) {
        int current_row = q.front().first;
        int current_col = q.front().second;
        int &current_val = map[current_row][current_col];

        q.pop();

        for (int i = 0; i < 4; i++) {
            int next_row = current_row + d_row[i];
            int next_col = current_col + d_col[i];

            if (next_row < 0 || next_row > N - 1 || next_col < 0 || next_col > M - 1) {
                continue;
            }

            if (visit[next_row][next_col] != 0) {
                continue;
            }

            int next_val = map[next_row][next_col];

            if (next_val == 0 && current_val > 0) {
                current_val--;
            } else {
                visit[next_row][next_col] = 1;
                q.push({next_row, next_col});
            }
        }
    }
}

int find() {

}

int solve() {
    q.push({start.first, start.second});
    bfs();
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        vector<int> row;
        for (int j = 0; j < M; j++) {
            int elem;
            cin >> elem;
            if (elem != 0 && start == make_pair(0, 0)) {
                start = {i, j};
            }

            row.push_back(elem);
        }
        map.push_back(row);
    }

    solve();

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}