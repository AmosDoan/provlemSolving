//
// Created by Amos on 2020/05/31.
//
#include <iostream>
#include <vector>

#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

using namespace std;

int N, M;
int start_row, start_col, start_direction;
int next_direction_map[4] = {/* North -> West */ 3, /* East -> North */ 0, /* South -> East */ 1, /* West -> South */ 2};
int d_row[4] = {0, -1, 0, 1};
int d_col[4] = {-1, 0, 1, 0};
int back_row[4] = {1, 0, -1, 0};
int back_col[4] = {0, -1, 0, 1};
vector<vector<int>> map;

void dfs(int current_row, int current_col, int current_direction) {
    if (map[current_row][current_col] == 1) {
        return;
    }

    map[current_row][current_col] = 2;

    int next_row = 0;
    int next_col = 0;
    int no_clean = 0;
    for (int i = 0; i < 4; i++) {
        next_row = current_row + d_row[i];
        next_col = current_col + d_col[i];
        if (map[next_row][next_col] == 0) {
            break;
        }
        no_clean++;
    }

    if (no_clean == 4) {
        next_row = current_row + back_row[current_direction];
        next_col = current_col + back_col[current_direction];

        if (map[next_row][next_col] == 0) {
            dfs(next_row, next_col, current_direction);
        } else {
            return;
        }
    }

    int next_direction = next_direction_map[current_direction];
    next_row = current_row + d_row[current_direction];
    next_col = current_col + d_col[current_direction];

    if (map[next_row][next_col] == 0) {
        return dfs(next_row, next_col, next_direction);
    } else {
        return dfs(current_row, current_col, next_direction);
    }
}

int solve() {
    dfs(start_row, start_col, start_direction);
    int nr_clean = 0;

    /*
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << map[i][j] << " ";
        }
        cout << '\n';
    }
    */

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 2) {
                nr_clean++;
            }
        }
    }

    return nr_clean;
}

int main() {
    cin >> N >> M;
    map.resize(N, vector<int>(M, 0));

    cin >> start_row >> start_col >> start_direction;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int current;
            cin >> current;
            map[i][j] = current;
        }
    }

    cout << solve() << '\n';

    return 0;
}
