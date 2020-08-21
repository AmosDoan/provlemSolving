#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    queue<int> q;
    vector<vector<int>> courseMap;
    vector<int> indegree;
    vector<int> visit;

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        indegree.resize(numCourses, 0);
        visit.resize(numCourses, 0);
        courseMap.resize(numCourses, vector<int>(numCourses, 0));
        for (auto &v : prerequisites) {
            int end = v[0];
            int start = v[1];

            courseMap[start][end] = 1;
            indegree[end]++;
        }

        vector<int> result;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0)  {
                q.push(i);
                visit[i] = 1;
                break;
            }
        }

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            result.push_back(current);

            for (int i = 0; i < numCourses; i++) {
                if (courseMap[current][i] == 1) {
                    indegree[i]--;
                }
            }

            for (int i = 0; i < numCourses; i++) {
                if (indegree[i] == 0 && visit[i] == 0) {
                    q.push(i);
                    visit[i] = 1;
                }
            }
        }

        if (result.size() == numCourses) {
            return result;
        } else {
            return {};
        }

    }
};

int main() {
    Solution *s;

    s = new Solution();


    delete s;
}

static const auto _ = []() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();
