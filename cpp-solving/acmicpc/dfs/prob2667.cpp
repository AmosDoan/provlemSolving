//
// Created by Amos on 2019/12/27.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <utility> // for pair

using namespace std;

vector<int> result;

void detect(vector<string> &map, pair<int, int> start, int group,
            vector<vector<bool>> &visit) {
    int row = start.first;
    int col = start.second;

    visit[row][col] = true;
    result[group]++;

    if (row - 1 >= 0) {
        if (map[row - 1][col] == '1' && !visit[row - 1][col]) {
            detect(map, make_pair(row - 1, col), group, visit);
        }
    }

    if (row + 1 < map.size()) {
        if (map[row + 1][col] == '1' && !visit[row + 1][col]) {
            detect(map, make_pair(row + 1, col), group, visit);
        }
    }

    if (col + 1 < map.size()) {
        if (map[row][col + 1] == '1' && !visit[row][col + 1]) {
            detect(map, make_pair(row, col + 1), group, visit);
        }
    }

    if (col - 1 >= 0) {
        if (map[row][col - 1] == '1' && !visit[row][col - 1]) {
            detect(map, make_pair(row, col - 1), group, visit);
        }
    }
}

void find(vector<string> &map, vector<vector<bool>> &visit) {
    int group = 0;
    for (int i = 0; i < map.size(); i++) {
        for (int j = 0; j < map.size(); j++) {
            if(map[i][j] == '1' && !visit[i][j]) {
                result.push_back(0);
                detect(map, make_pair(i, j), group, visit);
                group++;
            }
        }
    }
}

// 지도를 입력받을 때에는 vector<string>으로 받으면 편하다.
int main() {
    int N;
    cin >> N;

    vector<string> map;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        map.push_back(s);
    }

    vector<vector<bool>> visit;
    for (int i = 0; i < N; i++) {
        vector<bool> v(N, false);
        visit.push_back(v);
    }

    find(map, visit);

    cout << result.size() << '\n';
    sort(result.begin(), result.end());
    for (auto &it : result) {
        cout << it << '\n';
    }
}
