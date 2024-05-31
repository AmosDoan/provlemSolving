#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
private:
    bool bfs(int current, int current_color, vector<vector<int>>& graph, vector<int>& colors) {
        colors[current] = current_color;

        queue<int> q;
        q.push(current);

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            for (auto& next : graph[current]) {
                if (colors[next] == 0) {
                    colors[next] = -1 * colors[current];
                    q.push(next);
                } else if (colors[current] == colors[next])  {
                    return false;
                }
            }
        }

        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        if (graph.size() == 0) {
            return false;
        }

        vector<int> colors(graph.size(), 0);

        for (int i = 0; i < graph.size(); i++) {
            if (colors[i] == 0) {
                bool ret = bfs(i, 1, graph, colors);

                if (!ret) {
                    return false;
                }
            }
        }

        return true;
    }
};

int main() {
    Solution *s;
    vector<vector<int>> v = {{1, 3}, {0, 2}, {1, 3}, {0, 2}};
    //vector<vector<int>> v = {{1, 2, 3}, {0, 2}, {0, 1, 3}, {0, 2}};
    //vector<vector<int>> v = {{1}, {0, 3}, {3}, {1, 2}};

    s = new Solution();
    cout << s->isBipartite(v) << '\n';
    delete s;
}

static const auto _ = []() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();
