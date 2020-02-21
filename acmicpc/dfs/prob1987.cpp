//
// Created by Amos on 2020/02/22.
//
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int R,C;
vector<string> map;
set<char> memo;

int d_row[4] = {1, -1, 0, 0};
int d_col[4] = {0 ,0, 1, -1};
int max_distance = 1;

void solve(int row, int col, int distance) {

    cout << "visit - row : " << row << ", col : " << col << ", distance : " << distance << ", current : " << map[row][col] << '\n';

    for (int i = 0; i < 4; i++) {
        int next_row = row + d_row[i];
        int next_col = col + d_col[i];

        if (next_row < R && next_row >= 0 && next_col < C && next_col >= 0) {
            if (memo.find(map[next_row][next_col]) == memo.end()) {
                memo.insert(map[next_row][next_col]);
                solve(next_row, next_col, distance + 1);
                memo.erase(map[next_row][next_col]);
            } else {
                if (distance > max_distance) {
                    max_distance = distance;
                }
            }
        }
    }
}

int main() {
    cin >> R >> C;

    for (int i = 0; i < R; i++) {
        string s;
        cin >> s;
        map.push_back(s);
    }

    memo.insert(map[0][0]);
    solve(0, 0, 1);

    cout << max_distance << '\n';

    return 0;
}
