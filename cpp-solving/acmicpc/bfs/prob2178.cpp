//
// Created by Amos on 2020/01/06.
//

#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <utility>

using namespace std;

int N, M;
// String인 것을 명심하자. 일반 숫자가 아니다.
vector<string> map;
queue<pair<pair<int, int>, int>> q;
set<pair<int, int>> visit;

int bfs() {
    int level = 0;
    while (!q.empty()) {
        pair<int, int> current = q.front().first;
        int current_level = q.front().second;
        q.pop();
        visit.insert(current);

        int current_row = current.first;
        int current_col = current.second;
        current_level++;

        if (current_row == N - 1 && current_col == M - 1) {
            level = current_level;
            break;
        }

        if (current_row + 1 < N && visit.find(make_pair(current_row + 1, current_col)) == visit.end()
            && map[current_row + 1][current_col] == '1') {
            visit.insert(make_pair(current_row + 1, current_col));
            q.push(make_pair(make_pair(current_row + 1, current_col), current_level));
        }

        if (current_col + 1 < M && visit.find(make_pair(current_row, current_col + 1)) == visit.end()
            && map[current_row][current_col + 1] == '1') {
            visit.insert(make_pair(current_row, current_col + 1));
            q.push(make_pair(make_pair(current_row, current_col + 1), current_level));
        }

        if (current_row > 0 && visit.find(make_pair(current_row - 1, current_col)) == visit.end()
            && map[current_row - 1][current_col] == '1') {
            visit.insert(make_pair(current_row - 1, current_col));
            q.push(make_pair(make_pair(current_row - 1, current_col), current_level));
        }

        // C++도 Java와 같이 Short circuit operator임
        if (current_col > 0 && visit.find(make_pair(current_row, current_col - 1)) == visit.end()
            && map[current_row][current_col - 1] == '1') {
            // 미리 visit 표시
            visit.insert(make_pair(current_row, current_col - 1));
            q.push(make_pair(make_pair(current_row, current_col - 1), current_level));
        }
    }

    return level;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string row;
        cin >> row;
        map.push_back(row);
    }

    q.push(make_pair(make_pair(0, 0), 0));
    cout << bfs();

    return 0;
}
