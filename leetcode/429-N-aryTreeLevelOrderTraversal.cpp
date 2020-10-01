#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<pair<Node*, int>> q;
        vector<vector<int>> ret;

        if (root == nullptr) {
            return ret;
        }

        vector<pair<int, int>> temp;
        q.push({root, 0});
        int max_level = 0;
        while (!q.empty()) {
            Node* current = q.front().first;
            int current_level = q.front().second;
            q.pop();

            temp.push_back({current->val, current_level});

            if (current_level > max_level) {
                max_level = current_level;
            }

            for (auto& elem : current->children) {
                q.push({elem, current_level + 1});
            }
        }

        ret.resize(max_level + 1);
        for (auto& elem : temp) {
            ret[elem.second].push_back(elem.first);
        }

        return ret;
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
