//
// Created by Amos on 2020/01/01.
//
#include <iostream>
#include <vector>
#include <stack>
#include <set>

using namespace std;

stack<int> s;
set<int> visit;

// 공백을 포함하여 들어오므로 단순 cin으로 받기 힘들다. 이럴 때는 std::getline으로
// https://stackoverflow.com/questions/5838711/stdcin-input-with-spaces
void dfs(vector<vector<int>> &map, int start, vector<vector<int>> &result) {
    // Stack에는 Current Node가 들어있음
    int currentNode = s.top();
    vector<int> subMap = map[currentNode];
    s.pop();

    visit.insert(currentNode);

    for (int i = 0; i < subMap.size(); i++) {
        // start node로 다시 돌아오는 케이스 체크해야 함
        if (subMap[i] == 1 && (visit.find(i) == visit.end() || i == start)) {
            s.push(i);
            result[start][i] = 1;
            dfs(map, start, result);
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;
    cin.ignore();

    vector<vector<int>> map;
    for (int i = 0; i < N; i++) {
        vector<int> v;
        for (int j = 0; j < N; j++) {
            int node;
            cin >> node;
            v.push_back(node);
        }
        map.push_back(v);
    }

    vector<vector<int>> result;
    for (int i = 0; i < N; i++) {
        vector<int> v = vector<int>(N, 0);
        result.push_back(v);
    }

    for (int i = 0; i < N; i++) {
        s.push(i);
        dfs(map, i, result);
        visit.clear();
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << result[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
