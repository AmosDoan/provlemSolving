//
// Created by Amos on 2020/02/22.
//
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int R,C;
vector<string> map;
set<pair<int, int>> visit;

int d_row[4] = {1, -1, 0, 0};
int d_col[4] = {0 ,0, 1, -1};

int solve(int row, int col, int distance, set<char> memo) {

    cout << "visit - row : " << row << ", col : " << col << ", distance : " << distance << '\n';

    if (visit.find({row, col}) != visit.end()) {
        return distance - 1;
    }

    if (memo.find(map[row][col]) != memo.end()) {
        return distance - 1;
    }

    visit.insert({row, col});
    memo.insert(map[row][col]);

    int max_distance = distance;
    for (int i = 0; i < 4; i++) {
        int next_row = row + d_row[i];
        int next_col = col + d_col[i];

        if (next_row >= R || next_row < 0) {
            continue;
        }

        if (next_col >= C || next_col < 0) {
            continue;
        }

        if (visit.find({next_row, next_col}) != visit.end()) {
            continue;
        }

        int sub_distance = 0;
        sub_distance = solve(next_row, next_col, distance + 1, memo);

        if (sub_distance > max_distance) {
            max_distance = sub_distance;
        }
    }

    memo.erase(map[row][col]);

    return max_distance;
}

int main() {
    cin >> R >> C;

    for (int i = 0; i < R; i++) {
        string s;
        cin >> s;
        map.push_back(s);
    }

    set<char> memo;
    cout << solve(0, 0, 1, memo) << '\n';

    return 0;
}
