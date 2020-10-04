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
    TreeNode* buildTree(TreeNode* prev, int left, int right, vector<int>& nums) {
        if (left > right) {
            return nullptr;
        }

        int mid = (left + right + 1) / 2;
        int current_val = nums[mid];
        if (prev == nullptr) {
            prev = new TreeNode(current_val);
        } else if (prev->val > current_val) {
            prev->left = new TreeNode(current_val);
            prev = prev->left;
        } else {
            prev->right = new TreeNode(current_val);
            prev = prev->right;
        }

        buildTree(prev, mid + 1, right, nums);
        buildTree(prev, left, mid - 1, nums);
        return prev;
    }

public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty()) {
            return nullptr;
        }

        return buildTree(nullptr, 0, nums.size() - 1, nums);
    }
};

int main() {
    Solution *s;
    vector<int> v = {-10,-3,0,5,9};

    s = new Solution();
    s->sortedArrayToBST(v);
    delete s;
}

static const auto _ = []() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();
