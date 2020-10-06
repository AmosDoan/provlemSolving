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
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;

        if (root == nullptr) {
            return ret;
        }

        vector<vector<int>> temp;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            TreeNode* current = q.front().first;
            int current_val = current->val;
            int current_level = q.front().second;
            q.pop();

            if (temp.size() == current_level) {
                vector<int> v(1, current_val);
                temp.push_back(v);
            } else {
                temp[current_level].push_back(current_val);
            }

            if (current->left) {
                q.push({current->left, current_level + 1});
            }

            if (current->right) {
                q.push({current->right, current_level + 1});
            }
        }

        for (auto& v : temp) {
            ret.push_back(v[v.size() - 1]);
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
