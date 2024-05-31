//
// Created by Amos on 2020/02/23.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct info {
    int row;
    int col;
    int chance;
    int level;
};

int N, M;
vector<string> map;
// visit[row][col][break wall]
// 어느 좌표에 부수고 도착한 경우와 부수지 않고 도착하는 경우가 있음
// 만약 부수고 도착한 경우 먼저 visit 처리를 하면 부수지 않고 도착하는 경우는 q에 enqueue되지 못함
// 만약 부수지 않고 나중에 부수는 경우가 최단 거리라면 고려를 할 수 없게됨
// 따라서 부수지 않고 도착한 경우와 부수고 도착한 경우를 따로 세어주어야 함
vector<vector<vector<int>>> visit;
queue<info> q;

int d_row[4] = {0, 0, 1, -1};
int d_col[4] = {1, -1, 0, 0};

int solve() {
    int level = -1;

    info start;
    start.row = 0;
    start.col = 0;
    start.chance = 1;
    start.level = 1;
    q.push(start);

    visit[0][0][0] = 1;
    visit[0][0][1] = 1;
    while (!q.empty()){
        info current = q.front();
        q.pop();

        int current_row = current.row;
        int current_col = current.col;
        int current_chance = current.chance;
        int current_level = current.level;

        if (current_row == N - 1 && current_col == M - 1) {
            level = current_level;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int next_row = current_row + d_row[i];
            int next_col = current_col + d_col[i];

            if (next_row < N && next_row >= 0 && next_col < M && next_col >= 0) {
                char current = map[next_row][next_col];
                if (current_chance == 0 && visit[next_row][next_col][1] == 0) {
                    if (current == '0') {
                        info next;
                        next.row = next_row;
                        next.col = next_col;
                        next.level = current_level + 1;
                        next.chance = current_chance;
                        visit[next_row][next_col][1] = 1;
                        q.push(next);
                    }
                } else if (current_chance == 1 && visit[next_row][next_col][0] == 0) {
                    info next;
                    next.row = next_row;
                    next.col = next_col;
                    next.level = current_level + 1;
                    if (current == '0') {
                        visit[next_row][next_col][0] = 1;
                        next.chance = current_chance;
                    } else {
                        visit[next_row][next_col][1] = 1;
                        next.chance = current_chance - 1;
                    }
                    q.push(next);
                }
            }
        }
    }

    return level;
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        map.push_back(s);
    }

    // visit vector
    visit.resize(N, vector<vector<int>>(M, vector<int>(2, 0)));

    cout << solve() << '\n';
    return 0;
}
