//
// Created by Amos on 2020/03/03.
//
#include <iostream>
#include <vector>

using namespace std;

int N, start, target, M;
vector<vector<int>> map;

int main() {
    cin >> N >> start >> target >> M;

    map.resize(N + 1, vector<int>(0, 0));

    for (int i = 0; i < M; i++) {
        int s, t;
        cin >> s >> t;

        map[s].push_back(t);
        map[t].push_back(s);
    }

    for (int i = 0; i< N; i++) {
        vector<int> sub = map[i];

        cout << i << ". ";
        for (int elem : sub) {
            cout << elem << " ";
        }
        cout << '\n';
    }

    return 0;
}
