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
    int maxHeight(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }

        int left = maxHeight(node->left);
        int right = maxHeight(node->right);

        return max(left, right) + 1;
    }

    bool traverse(TreeNode* node) {
        if (node == nullptr) {
            return true;
        }

        int left = maxHeight(node->left);
        int right = maxHeight(node->right);

        if (abs(left - right) <= 1 && traverse(node->left) && traverse(node->right)) {
            return true;
        }
        return false;
    }

public:
    bool isBalanced(TreeNode* root) {
        return traverse(root);
    }
};

class Solution {
public:
    Solution() {}

private:
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
