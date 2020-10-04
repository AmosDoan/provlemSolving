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
    int findBottomLeftValue(TreeNode* root) {
        vector<vector<int>> temp;
        queue<pair<TreeNode*, int>> q;

        if (root == nullptr) {
            return 0;
        }

        q.push({root, 0});
        while(!q.empty()) {
            TreeNode* current = q.front().first;
            int current_level = q.front().second;
            q.pop();

            if(temp.size() == current_level) {
                vector<int> node(1, current->val);
                temp.push_back(node);
            } else {
                temp[current_level].push_back(current->val);
            }

            if (current->left) {
                q.push({current->left, current_level + 1});
            }

            if (current->right) {
                q.push({current->right, current_level + 1});
            }
        }

        return temp[temp.size() - 1][0];
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
