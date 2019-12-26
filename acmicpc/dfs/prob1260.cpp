//
// Created by Amos on 2019/12/26.
//

/*
Example:
 input 1
4 5 1
1 2
1 3
1 4
2 4
3 4
 output 1
1 2 4 3
1 2 3 4

 input 2
5 5 3
5 4
5 2
1 2
3 4
3 1
 output 2
3 1 2 5 4
3 1 4 2 5
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>
#include <queue>

using namespace std;

stack<int> s;
set<int> visit;
queue<int> q;

/**
 * BFS needs queue and visit set
 *
 * @param v
 * @param start
 */
void bfs(vector<vector<int>>& v, int start) {
    if (q.empty()) {
        return;
    }

    // dequeue
    q.pop();
    cout << start << ' ';

    // enqueue
    vector<int> subList = v[start];
    for (auto& elem : subList) {
        if (visit.find(elem) == visit.end()) {
            q.push(elem);
            visit.insert(elem);
        }
    }

    bfs(v, q.front());
}


/**
 *
 * DFS needs adjacent list or adjacent matrix and visit set
 *
 * @param v
 * @param start
 */
void dfs(vector<vector<int>>& v, int start) {
    vector<int> subList = v[start];
    s.pop();
    cout << start << ' ';
    visit.insert(start);

    for (auto& elem : subList) {
        if (visit.find(elem) == visit.end()) {
            s.push(elem);
            dfs(v, elem);
        }
    }
}

int main() {
    int N, M, S;
    vector<vector<int>> list;

    cin >> N >> M >> S;

    // O(N)
    for (int i = 0; i < N + 1; i++) {
        vector<int> v;
        list.push_back(v);
    }

    // O(M)
    for (int i = 0; i < M; i++) {
        int start, end;
        cin >> start >> end;
        list[start].push_back(end);
        list[end].push_back(start);
    }

    // O(N * logM)
    for (int i = 0; i < N; i++) {
        sort(list[i].begin(), list[i].end());
    }

    s.push(S);
    dfs(list, S);
    visit.clear();

    cout << '\n';

    q.push(S);
    visit.insert(S);
    bfs(list, S);
}

