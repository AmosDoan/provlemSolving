//
// Created by Amos on 2019/12/26.
//

// Example of DFS using adjacent matrix
#include <iostream>
#include <memory>
#include <vector>
//#include <deque> // Deque : Double Ended Queue
#include <queue>

using namespace std;

vector<int> visit;

void bfs(vector<vector <int>>& graph, queue<int>& queue_, int edge) {
    while(!queue_.empty()) {
        int current_node {queue_.front()};
        queue_.pop();
        cout << current_node + 1 << " ";

        for(int i {0}; i < edge; i++) {
            if(graph[current_node][i] == 1 && !visit[i]) {
                visit[i] = 1;
                queue_.push(i);
            }
        }
    }
}

void dfs(vector<vector <int>>& graph, int start_node, int edge) {
    cout << start_node + 1 << " ";
    visit[start_node] = 1;

    for(int i {0}; i < edge; i ++) {
        if(graph[start_node][i] == 1 && visit[i] == 0)
            dfs(graph, i, edge);
    }
}

int main(int argc, char **argv) {
    int vertex, edge, start;
    vector<vector <int>> data;
//  deque<int> queue;
    queue<int> queue_;

    cin >> vertex >> edge >> start;

    data.resize(vertex, vector<int>(vertex, 0));
    visit.resize(vertex, 0);

    for(int i {0}; i < edge; i++) {
        int src_node, dest_node;
        cin >> src_node >> dest_node;
        data[src_node - 1][dest_node - 1] = 1;
        data[dest_node -1][src_node - 1] = 1;
    }

//    for(auto& row : data)
//    {
//        cout << endl;
//        for(auto &col : row)
//            cout << col;
//    }
//    cout << endl;

    dfs(data, start - 1, vertex);
    cout << endl;

    visit.assign(vertex, 0);
    queue_.push(start - 1);
    visit[start - 1] = 1;
    bfs(data, queue_, vertex);

    cout << endl;

    return 0;
}

