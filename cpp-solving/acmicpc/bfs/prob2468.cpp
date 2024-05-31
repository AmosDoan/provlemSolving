//
// Created by Amos on 2020/01/18.
//
#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

int N;
int max_height = 0;
vector<vector<int>> map;
set<pair<int, int>> visit;
queue<pair<int, int>> q;

void bfs(vector<vector<int>>& temp_map) {

    while(!q.empty()) {
        int start_row = q.front().first;
        int start_col = q.front().second;
        q.pop();

        // visit 체크는 넣기 전에 해야 메모리 초과를 막을 수 잇음 (Stack overflow를 막자)
        if (start_row + 1 < N && visit.find({start_row + 1, start_col}) == visit.end() &&
            temp_map[start_row + 1][start_col] != 1000) {
            visit.insert({start_row + 1, start_col});
            q.push({start_row + 1, start_col});
        }

        if (start_row - 1 >= 0 && visit.find({start_row - 1, start_col}) == visit.end() &&
            temp_map[start_row - 1][start_col] != 1000) {
            visit.insert({start_row - 1, start_col});
            q.push({start_row - 1, start_col});
        }

        if (start_col + 1 < N && visit.find({start_row, start_col + 1}) == visit.end() &&
            temp_map[start_row][start_col + 1] != 1000) {
            visit.insert({start_row, start_col + 1});
            q.push({start_row, start_col + 1});
        }

        if (start_col - 1 >= 0 && visit.find({start_row, start_col - 1}) == visit.end() &&
            temp_map[start_row][start_col - 1] != 1000) {
            visit.insert({start_row, start_col - 1});
            q.push({start_row, start_col - 1});
        }
    }
}

int solve() {
    int max_number = 0;
    for (int rain = 1; rain < max_height; rain++) {
        vector<vector<int>> temp_map = map;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (temp_map[i][j] <= rain) {
                    temp_map[i][j] = 1000;
                }
            }
        }

        int count = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (visit.find({i, j}) == visit.end() &&
                    temp_map[i][j] != 1000) {
                    count++;
                    visit.insert({i, j});
                    q.push({i, j});
                    bfs(temp_map);
                }
            }
        }

        if (max_number < count) {
            max_number = count;
        }

        visit.clear();
        temp_map.clear();
    }

    return max_number;
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        vector<int> v;
        for (int j = 0; j < N; j++) {
            int number;
            cin >> number;
            if (number > max_height) {
                max_height = number;
            }
            v.push_back(number);
        }
        map.push_back(v);
    }

    cout << solve();

    return 0;
}

