#include <iostream>
#include <vector>
#include <queue>
#include <stack>

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
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ret;
        queue<pair<TreeNode*, int>> q;
        stack<pair<int, int>> st;

        if (root == nullptr) {
            return ret;
        }

        q.push({root, 0});

        int max_level = -1;
        while (!q.empty()) {
            TreeNode* current = q.front().first;
            int current_level = q.front().second;
            q.pop();

            st.push({current->val, current_level});
            if (current_level > max_level) {
                max_level = current_level;
            }

            if (current->right != nullptr) {
                q.push({current->right, current_level + 1});
            }

            if (current->left != nullptr) {
                q.push({current->left, current_level + 1});
            }
        }

        ret.resize(max_level + 1);

        while (!st.empty()) {
            int val = st.top().first;
            int current_level = st.top().second;
            st.pop();

            ret[max_level - current_level].push_back(val);
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
