#include <iostream>
#include <vector>

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
    int traverse(TreeNode* current, int current_depth) {
        if (current == nullptr) {
            return INT_MAX;
        }

        if (current->left == nullptr && current->right == nullptr) {
            return current_depth;
        }

        int ret = traverse(current->left, current_depth + 1);
        ret = min(traverse(current->right, current_depth + 1), ret);
        return ret;
    }


public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        return traverse(root, 1);
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
