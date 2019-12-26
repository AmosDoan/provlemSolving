//
// Created by Amos on 2019/12/26.
//
#include <iostream>
#include <vector>

#include "vectorUtil.h"

using namespace std;

/**
 * Example input
 *
 First line - Number of nodes / Number of edges
4 5
1 2
1 3
1 4
2 4
3 4
 *
 * @return
 */
int main() {
    int N, M;
    vector<vector<int>> list;

    cin >> N >> M;

    for (int i = 0; i < N + 1; i++) {
        vector<int> v;
        list.push_back(v);
    }

    for (int i = 0; i < M; i++) {
        int start, end;
        cin >> start >> end;
        list[start].push_back(end);
        list[end].push_back(start);
    }

    traversal2DVector(list);

    return 0;
}

