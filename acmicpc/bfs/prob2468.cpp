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

int bfs(vector<vector<int>>& temp_map, int rain) {


    while(!q.empty()) {
        int start_row = q.front().first;
        int start_col = q.front().second;
        q.pop();

        visit.insert({start_row, start_col});

        if (temp_map[start_row][start_col] <= rain) {
            temp_map[start_row][start_col] = 1000;
        }

        if (start_row + 1 < N && visit.find({start_row + 1, start_col}) == visit.end() &&
            temp_map[start_row][start_col] != 1000) {
            q.push({start_row + 1, start_col});
        }

        if (start_row - 1 >= 0 && visit.find({start_row - 1, start_col}) == visit.end() &&
            temp_map[start_row][start_col] != 1000) {
            q.push({start_row - 1, start_col});
        }

        if (start_col + 1 < N && visit.find({start_row, start_col + 1}) == visit.end() &&
            temp_map[start_row][start_col] != 1000) {
            q.push({start_row, start_col + 1});
        }

        if (start_col - 1 >= 0 && visit.find({start_row, start_col - 1}) == visit.end() &&
            temp_map[start_row][start_col] != 1000) {
            q.push({start_row, start_col - 1});
        }
    }

    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << temp_map[i][j] << ' ';
            if (temp_map[i][j] == 1000) {
                count++;
            }
        }
        cout << '\n';
    }
    cout << '\n';

    return count;
}

int solve() {
    int max_number = -1;
    /*
    for (int i = 2; i < 101; i++) {

    }
    */

    int count = 0;
    vector<vector<int>> temp_map = map;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (visit.find({i, j}) == visit.end()) {
                count++;
                q.push({i, j});
                bfs(temp_map, 4);
            }
        }
    }
    return count;

    //return max_number;
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

    //cout << max_height;
    cout << solve();
    /*
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }
    */

    return 0;
}

