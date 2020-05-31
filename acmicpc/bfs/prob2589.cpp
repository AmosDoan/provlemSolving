//
// Created by Amos on 2020/05/31.
//
#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int n_row, n_col;
vector<string> map;
int d_row[4] = {1, -1, 0, 0};
int d_col[4] = {0, 0, 1, -1};

int bfs(int i, int j) {
    queue<pair<pair<int, int>, int>> q;
    q.push({{i, j}, 0});
    vector<vector<int>> visit(n_row, vector<int>(n_col, 0));

    visit[i][j] = 1;

    int ret = 0;
    while (!q.empty()) {
        pair<pair<int, int>, int> current_elem = q.front();
        pair<int, int> current = current_elem.first;
        int level = current_elem.second;
        if (level > ret) {
            ret = level;
        }

        q.pop();
        for (int i = 0; i < 4; i++) {
            int next_row = current.first + d_row[i];
            int next_col = current.second + d_col[i];

            if (next_row < 0 || next_row >= n_row || next_col < 0 || next_col >= n_col) {
                continue;
            }

            if (map[next_row][next_col] != 'L') {
                continue;
            }

            if (visit[next_row][next_col] == 1) {
                continue;
            }

            visit[next_row][next_col] = 1;
            q.push({{next_row, next_col}, level + 1});
        }
    }

    return ret;
}

int solve() {
    int ret = 0;
    for (int i = 0; i < n_row; i++) {
        for (int j = 0; j < n_col; j++) {
            if (map[i][j] == 'L') {
                int temp = bfs(i, j);
                if (temp > ret) {
                    ret = temp;
                }
            }
        }
    }

    return ret;
}

int main() {
    cin >> n_row >> n_col;

    map.resize(n_row);
    for (int i = 0; i < n_row; i++) {
        string s;
        cin >> s;
        map[i] = s;
    }

    cout << solve() << '\n';

    return 0;
}
