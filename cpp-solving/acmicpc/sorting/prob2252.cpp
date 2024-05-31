//
// Created by Amos on 2020/09/06.
//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<int> indegree;
vector<vector<int>> graph;

int main() {
    vector<int> result;
    queue<int> q;
    cin >> N >> M;

    indegree.resize(N + 1, 0);
    graph.resize(N + 1, vector<int>());

    for (int i = 0; i < M; i++) {
        int start, end;
        cin >> start >> end;
        graph[start].push_back(end);
        indegree[end]++;
    }

    for (int i = 1; i <= N; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        result.push_back(current);

        for (int i = 0; i < graph[current].size(); i++) {
            int end = graph[current][i];
            indegree[end]--;

            if (indegree[end] == 0) {
                q.push(end);
            }
        }
    }

    for (auto& elem : result) {
        cout << elem << ' ';
    }
    cout << '\n';

    return 0;
}
