//
// Created by Amos on 2020/03/16.
//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<vector<int>> map;
vector<int> visit;
queue<int> q;

int solve() {

    int ret = 0;

    q.push(1);
    visit[1] = 1;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int i = 1; i < N + 1; i++) {
            if (map[current][i] == 1 && visit[i] != 1) {
                q.push(i);
                visit[i] = 1;
                ret++;
            }
        }
    }

    return ret;
}

int main() {
    cin >> N >> M;

    map.resize(N + 1, vector<int>(N + 1, 0));
    visit.resize(N + 1, 0);

    for (int i = 0; i < M; i++) {
        int start, end;
        cin >> start >> end;
        map[start][end] = 1;
        map[end][start] = 1;
    }

    cout << solve() << '\n';

    return 0;
}
