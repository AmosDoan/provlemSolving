#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    map<int, vector<int>> adjacent;

    void buildAdjacentList(TreeNode* current, TreeNode* prev) {
        if (current == nullptr) {
            return;
        }

        int current_val = current->val;
        if (prev != nullptr) {
            adjacent[current_val].push_back(prev->val);
            adjacent[prev->val].push_back(current_val);
        }

        buildAdjacentList(current->left, current);
        buildAdjacentList(current->right, current);
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<int> ret;
        if (root == nullptr || target == nullptr) {
            return ret;
        }

        buildAdjacentList(root, nullptr);
        if (adjacent.size() == 0) {
            return ret;
        }

        vector<int> visit(adjacent.size(), 0);
        queue<pair<int, int>> q;

        q.push({target->val, 0});

        for (auto& v : adjacent) {
            int key = v.first;
            for (auto& elem : v.second) {
                cout << key << ":"<< elem << ' ';
            }
            cout << '\n';
        }

        while (!q.empty()) {
            int current = q.front().first;
            int current_level = q.front().second;
            q.pop();

            visit[current] = 1;

            if (current_level == K) {
                ret.push_back(current);
            }

            if (current_level > K) {
                break;
            }

            for (auto &elem : adjacent[current]) {
                if (visit[elem] == 0) {
                    q.push({elem, current_level + 1});
                }
            }
        }

        return ret;
    }
};

int main() {
    Solution *s;
    TreeNode* root = new TreeNode(1);

    s = new Solution();
    s->distanceK(root, root, 3);
    delete s;
}

static const auto _ = []() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();
