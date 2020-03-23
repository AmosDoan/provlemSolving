//
// Created by Amos on 2020/03/24.
//
#include <iostream>
#include <queue>

using namespace std;

int F, S, G, U, D;
queue<pair<int, int>> q;
vector<int> visit;

int solve() {
    q.push({S, 0});
    visit[S] = 1;

    int level = -1;
    while(!q.empty()) {
        int current = q.front().first;
        int current_level = q.front().second;
        q.pop();

        if (current == G) {
            level = current_level;
            break;
        }

        int up = current + U;
        if (up <= F && visit[up] == 0) {
            visit[up] = 1;
            q.push({up, current_level + 1});
        }

        int down = current - D;
        if (down > 0 && visit[down] == 0) {
            visit[down] = 1;
            q.push({down, current_level + 1});
        }
    }

    return level;
}

int main() {
    cin >> F >> S >> G >> U >> D;

    visit.resize(F + 1, 0);

    int ret = solve();
    if (ret == -1) {
        cout << "use the stairs" << '\n';
    } else {
        cout << ret << '\n';
    }

    return 0;
}
