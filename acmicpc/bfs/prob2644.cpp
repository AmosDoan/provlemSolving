//
// Created by Amos on 2020/03/03.
//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, start, target, M;
vector<vector<int>> map;
vector<int> visit;
queue<pair<int, int>> q;

int solve() {

    q.push({start, 0});
    visit[start] = 1;

    while (!q.empty()) {
        pair<int, int> elem = q.front();
        q.pop();

        int current = elem.first;
        int level = elem.second;

        if (current == target) {
            return level;
        }

        for (int next : map[current]) {
            if (visit[next] == 0) {
                visit[next] = 1;
                q.push({next, level + 1});
            }
        }
    }

    return -1;
}

int main() {
    cin >> N >> start >> target >> M;

    map.resize(N + 1, vector<int>(0, 0));
    visit.resize(N + 1, 0);

    for (int i = 0; i < M; i++) {
        int s, t;
        cin >> s >> t;

        map[s].push_back(t);
        map[t].push_back(s);
    }

    /*
    for (int i = 0; i< N; i++) {
        vector<int> sub = map[i];

        cout << i << ". ";
        for (int elem : sub) {
            cout << elem << " ";
        }
        cout << '\n';
    }
    */

    cout << solve() << '\n';

    return 0;
}
