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
    void traverse(TreeNode *t1, TreeNode* t2, TreeNode* ret) {
        if (t1 == nullptr && t2 == nullptr) {
            return;
        }

        if (t1 == nullptr) {
            ret->left = t2->left;
            ret->right = t2->right;
            return;
        }

        if (t2 == nullptr) {
            ret->left = t1->left;
            ret->right = t1->right;
            return;
        }


        if (t1->left == nullptr && t2->left != nullptr) {
            ret->left = new TreeNode(t2->left->val);
        } else if (t1->left != nullptr && t2->left == nullptr) {
            ret->left = new TreeNode(t1->left->val);
        } else if (t1->left != nullptr && t2->left != nullptr) {
            ret->left = new TreeNode(t1->left->val + t2->left->val);
        }

        if (t1->right == nullptr && t2->right != nullptr) {
            ret->right = new TreeNode(t2->right->val);
        } else if (t1->right != nullptr && t2->right == nullptr) {
            ret->right = new TreeNode(t1->right->val);
        } else if (t1->right != nullptr && t2->right != nullptr) {
            ret->right = new TreeNode(t1->right->val + t2->right->val);
        }

        traverse(t1->right, t2->right, ret->right);
        traverse(t1->left, t2->left, ret->left);
    }

public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr) {
            return t2;
        }


        if (t2 == nullptr) {
            return t1;
        }

        TreeNode *ret = new TreeNode(t1->val + t2->val);
        traverse(t1, t2, ret);
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
