//
// Created by Amos on 2020/04/12.
//
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    int getHeight(TreeNode *current) {
        if (current == nullptr) {
            return 0;
        }
        return 1 + max(getHeight(current->left), getHeight(current->right));
    }

public:
    bool isBalanced(TreeNode *root) {
        if (root == nullptr) {
            return true;
        }

        int leftSubTree = getHeight(root->left);
        int rightSubTree = getHeight(root->right);

        if (abs(leftSubTree - rightSubTree) <= 1) {
            return true;
        } else {
            return isBalanced(root->left) && isBalanced(root->right);
        }
    }
};

int main() {
    return 0;
}
