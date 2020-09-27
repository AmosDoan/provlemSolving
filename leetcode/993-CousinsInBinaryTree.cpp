#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        map<int, pair<int, int>> m;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while(!q.empty()) {
            TreeNode* current = q.front().first;
            int current_level = q.front().second;
            q.pop();


            TreeNode*left = current->left;
            TreeNode*right = current->right;

            if (left != nullptr) {
                m[left->val] = {current_level + 1, current->val};
                q.push({left, current_level + 1});
            }

            if (right != nullptr) {
                m[right->val] = {current_level + 1, current->val};
                q.push({right, current_level + 1});
            }
        }

        return m[x].first == m[y].first && m[x].second != m[y].second;
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
