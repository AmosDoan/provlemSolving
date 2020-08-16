#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    queue<pair<TreeNode*, int>> q;

public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;

        if (root == nullptr) {
            result;
        }

        int max_level = 0;
        vector<pair<int, int>> temp;
        q.push({root, 1});
        while (!q.empty()) {
            TreeNode *current_node = q.front().first;
            if (current_node == nullptr) {
                break;
            }

            int current_level = q.front().second;
            q.pop();

            if (current_level > max_level) {
                max_level = current_level;
            }

            temp.push_back({current_node->val, current_level});

            if (current_node->left != nullptr) {
                q.push({current_node->left, current_level + 1});
            }

            if (current_node->right != nullptr) {
                q.push({current_node->right, current_level + 1});
            }
        }

        result.resize(max_level, vector<int>(0));

        for (auto& elem : temp) {
            int current_val = elem.first;
            int current_level = elem.second;

            result[current_level - 1].push_back(current_val);
        }

        return result;
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
