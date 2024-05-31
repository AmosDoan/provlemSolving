//
// Created by Amos on 2020/02/16.
//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 회고 set을 visit으로 사용하면 시간 초과남

// N : 세로, Row
// M : 가로, Col
// H : 높이, Height
int N, M, H;
vector<vector<vector<int>>> map;
queue<pair<pair<int, pair<int, int>>, int>> q;

int d_row[6] = {0, 0, 1, -1, 0, 0};
int d_col[6] = {0, 0, 0, 0, 1, -1};
int dz[6] = {1, -1, 0, 0, 0, 0};

bool isValidRange(int next_value, int limit) {
    return next_value >= 0 && next_value < limit;
}

int bfs() {
    int current_level = 0;
    while(!q.empty()) {
        pair<pair<int, pair<int, int>>, int> current = q.front();
        q.pop();

        int current_h = current.first.first;
        int current_row = current.first.second.first;
        int current_col = current.first.second.second;
        current_level = current.second;

        for (int i = 0; i < 6; i++) {
            int next_row = current_row + d_col[i];
            int next_col = current_col + d_row[i];
            int next_h = current_h + dz[i];

            if (isValidRange(next_row, N) && isValidRange(next_col, M) &&
                isValidRange(next_h, H) && map[next_h][next_row][next_col] == 0) {
                map[next_h][next_row][next_col] = 1;
                q.push({{next_h, {next_row, next_col}}, current_level + 1});
            }
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                int current = map[i][j][k];
                if (current == 0) {
                    return -1;
                }
            }
        }
    }

    return current_level;
}

int main() {
    cin >> M >> N >> H;

    map.resize(H, vector<vector<int>>(N, vector<int>(M, 0)));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                int element;
                cin >> element;
                map[i][j][k] = element;
                if (element == 1) {
                    q.push({{i, {j, k}}, 0});
                }
            }
        }
    }

    cout << bfs() << '\n';
    /*
    for (int i = 0; i < H; i++) {
        cout << "step " << i << '\n';
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                cout << map[i][j][k] << ' ';
            }
            cout << '\n';
        }
    }
    */

    return 0;
}
