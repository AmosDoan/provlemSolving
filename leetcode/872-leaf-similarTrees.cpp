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
    void traverse(TreeNode* current, vector<int> &result) {

        if (current == nullptr) {
            return;
        }

        if (current->left == nullptr && current->right == nullptr) {
            result.push_back(current->val);
            return;
        }

        traverse(current->left, result);
        traverse(current->right, result);
    }


public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> ret1, ret2;

        traverse(root1, ret1);
        traverse(root2, ret2);

        if (ret1.size() != ret2.size()) {
            return false;
        }

        for (int i = 0; i < ret1.size(); i++) {
            if (ret1[i] != ret2[i]) {
                return false;
            }
        }

        return true;
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
