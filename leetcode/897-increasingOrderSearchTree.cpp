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
    void traverse(TreeNode* node, vector<int>& q) {
        if (node == nullptr) {
            return;
        }

        traverse(node->right, q);
        q.push_back(node->val);
        traverse(node->left, q);
    }

public:
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> q;
        traverse(root, q);

        TreeNode* ret = nullptr;
        for (auto& elem : q) {
            TreeNode* tmp = new TreeNode(elem);
            tmp->right = ret;
            ret = tmp;
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
