//
// Created by Amos on 2020/01/30.
//

#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <set>

using namespace std;

vector<vector<int>> map;
int N;
int L;
int d_row[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int d_col[8] = {2, -1, 1, -2, -2, -1, 1, 2};
set<pair<int, int>> visit;

int solve(pair<int, int> target, queue<pair<pair<int, int>, int>> &q) {
    while (!q.empty()) {
        pair<pair<int, int>, int> current = q.front();
        q.pop();

        int current_row = current.first.first;
        int current_col = current.first.second;
        int current_level = current.second;

        if (current_row == target.first && current_col == target.second) {
            return current_level;
        }

        for (int i = 0; i < 8; i++) {
            int next_row = current_row + d_row[i];
            int next_col = current_col + d_col[i];

            if (visit.find({next_row, next_col}) == visit.end() &&
                next_row < L && next_row >= 0 && next_col < L && next_col >= 0) {
                // 여기서 Visit하지 않으면 다른 노드에서 중복으로 넣을 수 있음
                visit.insert({next_row, next_col});
                q.push({{next_row, next_col}, current_level + 1});
            }
        }
    }

    return 0;
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> L;

        int start_row, start_col;
        cin >> start_row >> start_col;

        int target_row, target_col;
        cin >> target_row >> target_col;

        queue<pair<pair<int, int>, int>> q;
        visit.insert({start_row, start_col});
        q.push({{start_row, start_col}, 0});
        cout << solve({target_row, target_col}, q) << '\n';

        visit.clear();
    }


    return 0;
}
