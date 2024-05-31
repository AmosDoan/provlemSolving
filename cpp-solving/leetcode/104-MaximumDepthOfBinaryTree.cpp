#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    int max_level = 0;
    void traverse(TreeNode *current, int current_level) {
        if (current->left == nullptr && current->right == nullptr) {
            if (current_level > max_level) {
                max_level = current_level;
            }
            return;
        }

        if (current->left) {
            traverse(current->left, current_level + 1);
        }

        if (current->right) {
            traverse(current->right, current_level + 1);
        }
    }

public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        traverse(root, 1);

        return max_level;
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
