//
// Created by Amos on 2020/03/19.
//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<vector<int>> relation;
queue<pair<int, int>> q;

int bfs(int start) {
    vector<int> visit(N + 1, 0);

    q.push({start, 0});

    int cavin = 0;
    while (!q.empty()) {
        int current = q.front().first;
        int level = q.front().second;
        q.pop();

        visit[current] = 1;
        cavin += level;

        for (int i = 1; i < N + 1; i++) {
            if (relation[current][i] == 1 && visit[i] == 0) {
                visit[i] = 1;
                q.push({i, level + 1});
            }
        }
    }

    return cavin;
}

int solve() {
    int min_idx = 0;
    int min = 987654321;
    for (int i = 1; i < N + 1; i++) {
        int ret = bfs(i);
        if (ret < min) {
            min = ret;
            min_idx = i;
        }
    }

    return min_idx;
}

int main() {
    cin >> N >> M;

    relation.resize(N + 1, vector<int>(N + 1, 0));

    for (int i = 0; i < M; i++) {
        int start, end;
        cin >> start >> end;

        relation[start][end] = 1;
        relation[end][start] = 1;
    }

    cout << solve() << '\n';

    return 0;
}
