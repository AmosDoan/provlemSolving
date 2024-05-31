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
    bool traverse(TreeNode* current, int current_sum, const int sum) {
        if (current == nullptr) {
            return false;
        }

        if (current->left == nullptr && current->right == nullptr) {
            current_sum += current->val;
            return current_sum == sum;
        }

        current_sum += current->val;

        return traverse(current->left, current_sum, sum) || traverse(current->right, current_sum, sum);
    }

public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == nullptr) {
            return 0;
        }

        return traverse(root, 0, sum);
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
