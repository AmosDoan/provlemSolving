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
    bool traverse(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr && t2 == nullptr) {
            return true;
        }

        if (t1 == nullptr || t2 == nullptr) {
            return false;
        }

        return t1->val == t2->val && traverse(t1->left, t2->right) && traverse(t1->right, t2->left);
    }

public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }

        if (root->left == nullptr && root->right == nullptr) {
            return true;
        }

        return traverse(root->left, root->right);
    }
};

int main() {
    TreeNode* a = new TreeNode(3);
    TreeNode* b = new TreeNode(3);

    TreeNode* c = new TreeNode(2, nullptr, a);
    TreeNode* d = new TreeNode(2, b, nullptr);

    TreeNode* root = new TreeNode(1, c, d);

    Solution *s;
    s = new Solution();
    cout << s->isSymmetric(root) << '\n';
    delete s;
}

static const auto _ = []() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();
