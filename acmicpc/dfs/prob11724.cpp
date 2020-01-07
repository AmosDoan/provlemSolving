//
// Created by Amos on 2020/01/07.
//
#include <iostream>
#include <vector>
#include <cstdio>
#include <set>

using namespace std;

int N, M;
vector<vector<int>> edge;
set<int> visit;

void subFind(int start) {
    if (visit.find(start) != visit.end()) {
        return;
    }

    visit.insert(start);

    vector<int> neighbor = edge[start];

    for (auto it : neighbor) {
        subFind(it);
    }
}

int find() {
    int nr_connect = 0;
    for (int i = 1; i< N + 1; i++) {
        if (visit.find(i) == visit.end()) {
            nr_connect++;
            subFind(i);
        }
    }
    return nr_connect;
}


// scanf("%d %d\n") 하면 무한루프..
int main() {

    scanf("%d %d", &N, &M);

    edge.resize(N + 1, vector<int>());

    for (int i = 0; i < M; i++) {
        int start, end;
        scanf("%d %d", &start, &end);
        edge[start].push_back(end);
        // 무방향 그래프일 경우 반드시 인접리스트에 반대의 경우도 넣어주어야!
        edge[end].push_back(start);
    }

    /*
    for (int i = 0; i < N; i++) {
        for (auto it : edge[i]) {
            cout << it;
        }
        cout << '\n';
    }
    */

    cout << find();

    return 0;
}
