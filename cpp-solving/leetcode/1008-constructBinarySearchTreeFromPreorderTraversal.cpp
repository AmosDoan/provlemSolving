//
// Created by Amos on 2020/04/20.
//

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
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if (preorder.size() == 0) {
            return NULL;
        }

        if (preorder.size() == 1) {
            return new TreeNode(preorder[0]);
        }

        TreeNode *ret = NULL;
        for (auto val : preorder) {
            insertNode(ret, val);
        }

        return ret;
    }

private:
    TreeNode* insertNode(TreeNode *&node, int val) {
        if (node == NULL) {
             node = new TreeNode(val);
        } else {
            int current_val = node->val;
            if (val < current_val) {
                node->left = insertNode(node->left, val);
            } else if (val > current_val) {
                node->right = insertNode(node->right, val);
            }
        }
        return node;
    }
};

void printTree(TreeNode *head) {
    if (head == NULL) {
        return;
    }

    cout << head->val << '\n';

    printTree(head->left);
    printTree(head->right);
}

int main() {
    Solution *s;
    vector<int> v;

    s = new Solution();
    v = {8,5,1,7,10,12};
    TreeNode* ret = s->bstFromPreorder(v);
    printTree(ret);
    delete s;

    return  0;
}

static int x = [] () {ios::sync_with_stdio(false); cin.tie(NULL); return 0;} ();