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
    int traverse(TreeNode* node, int root_value) {
        if (node == nullptr) {
            return INT_MAX;
        }

        int val = abs(node->val - root_value);
        int left = traverse(node->left, root_value);
        int right = traverse(node->right, root_value);

        if (val == 0) {
            return min(left, right);
        } else {
            int ret = min(val, left);
            return min(ret, right);
        }
    }

public:
    int minDiffInBST(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        int ret = INT_MAX;
        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();

            int temp = traverse(current, current->val);
            ret = min(temp, ret);

            if (current->left) {
                q.push(current->left);
            }

            if (current->right) {
                q.push(current->right);
            }
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
