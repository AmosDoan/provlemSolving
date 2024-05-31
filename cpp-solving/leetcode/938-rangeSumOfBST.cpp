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
    int sum = 0;

    void traverse(TreeNode* node, int L, int R) {
        if (node == nullptr) {
            return;
        }

        if (node->val >= L && node->val <= R) {
            sum += node->val;
        }

        if (node->val <= L) {
            traverse(node->right, L, R);
            return;
        }

        if (node->val >= R) {
            traverse(node->left, L, R);
            return;
        }

        traverse(node->left, L, R);
        traverse(node->right, L, R);
    }


public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        traverse(root, L, R);
        return sum;
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
