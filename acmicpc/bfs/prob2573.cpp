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

void melt(vector<vector<int>> &visit) {

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

            if (next_val == 0) {
                current_val = current_val > 0 ?  current_val - 1 : current_val;
            } else {
                visit[next_row][next_col] = 1;
                q.push({next_row, next_col});
            }
        }
    }
}

void bfs2(int start_row, int start_col, vector<vector<int>> &visit) {

    visit[start_row][start_col] = 1;
    q.push({start_row, start_col});

    while (!q.empty()) {
        int current_row = q.front().first;
        int current_col = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++) {
            int next_row = current_row + d_row[i];
            int next_col = current_col + d_col[i];
            int next_val = map[next_row][next_col];

            if (next_row < 0 || next_row > N - 1 || next_col < 0 || next_col > M - 1) {
                continue;
            }

            if (visit[next_row][next_col] != 0) {
                continue;
            }

            if (next_val == 0) {
                continue;
            }

            visit[next_row][next_col] = 1;
            q.push({next_row, next_col});
        }
    }
}

int find() {
    int level = 0;
    vector<vector<int>> visit = vector<vector<int>>(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] != 0 && visit[i][j] == 0) {
                level++;
                if (level == 2) {
                    return level;
                }
                bfs2(i, j, visit);
            }
        }
    }
    return level;
}

void findStart() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] != 0) {
                start = {i, j};
                return;
            }
        }
    }
}

int solve() {
    int time = 0;
    while (true) {
        findStart();
        vector<vector<int>> visit = vector<vector<int>>(N, vector<int>(M, 0));
        q.push({start.first, start.second});

        time++;
        melt(visit);

        /*
        cout << "time : " << time << '\n';
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cout << map[i][j] << " ";
            }
            cout << '\n';
        }
        cout << '\n';
        */

        int num_ice = find();
        if (num_ice > 1) {
            return time;
        }

        if (num_ice == 0) {
            return 0;
        }
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        vector<int> row;
        for (int j = 0; j < M; j++) {
            int elem;
            cin >> elem;
            row.push_back(elem);
        }
        map.push_back(row);
    }

    cout << solve() << '\n';

    return 0;
}