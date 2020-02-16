//
// Created by Amos on 2020/02/16.
//
#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

// N : 세로, Row
// M : 가로, Col
// H : 높이, Height
int N, M, H;
vector<vector<vector<int>>> map;
set<pair<int, pair<int, int>>> visit;
queue<pair<pair<int, pair<int, int>>, int>> q;

int dx[6] = {0, 0, 1, -1, 0, 0};
int dy[6] = {0, 0, 0, 0, 1, -1};
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
            int next_row = current_row + dy[i];
            int next_col = current_col + dx[i];
            int next_h = current_h + dz[i];

            if (isValidRange(next_row, N) && isValidRange(next_col, M) &&
                isValidRange(next_h, H)) {
                if (visit.find({next_h, {next_row, next_col}}) == visit.end() &&
                    map[next_h][next_row][next_col] == 0) {
                    map[next_h][next_row][next_col] = 1;
                    visit.insert({next_h, {next_row, next_col}});
                    q.push({{next_h, {next_row, next_col}}, current_level + 1});
                }
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
                    visit.insert({i, {j, k}});
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
