//
// Created by Amos on 2020/02/04.
//
#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

int N;
vector<string> orig_map;
set<pair<int, int>> visit;
int d_row[4] = {0, 0, 1, -1};
int d_col[4] = {1, -1, 0, 0};


void dfs(vector<string> &map, int row, int col, char color) {
    if (visit.find({row, col}) != visit.end()) {
        return;
    }

    if (map[row][col] != color) {
        return;
    }

    visit.insert({row, col});

    for (int i = 0; i < 4; i++) {
        int next_row = row + d_row[i];
        int next_col = col + d_col[i];

        if (next_row < 0 || next_row >= N || next_col < 0 || next_col >= N) {
            continue;
        }

        if (visit.find({next_row, next_col}) != visit.end()) {
            continue;
        }

        if (map[next_row][next_col] != color) {
            continue;
        }

        dfs(map, next_row, next_col, color);
    }
}

int solve_normal() {
    int group = 0;
    vector<string> map = orig_map;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (visit.find({i, j}) == visit.end()) {
                dfs(map, i , j, map[i][j]);
                group++;
            }
        }
    }
    return group;
}

int solve_abnormal() {
    visit.clear();

    int group = 0;
    vector<string> map = orig_map;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == 'G') {
                map[i][j] = 'R';
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (visit.find({i, j}) == visit.end()) {
                dfs(map, i , j, map[i][j]);
                group++;
            }
        }
    }
    return group;
}


int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        orig_map.push_back(s);
    }

    cout << solve_normal() << ' ' << solve_abnormal();

    return 0;
}
