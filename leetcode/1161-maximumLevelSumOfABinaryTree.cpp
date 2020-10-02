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
public:
    int maxLevelSum(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;

        q.push({root, 0});
        vector<int> temp;
        while (!q.empty()) {
            TreeNode* current = q.front().first;
            int current_level = q.front().second;
            q.pop();

            if (temp.size() > current_level) {
                temp[current_level] += current->val;
            } else {
                temp.push_back(current->val);
            }

            if (current->left) {
                q.push({current->left, current_level + 1});
            }

            if (current->right) {
                q.push({current->right, current_level + 1});
            }
        }

        int ret = 0;
        int temp_max = INT_MIN;
        for (int i = 0; i < temp.size(); i++) {
            cout << i << ":" << temp[i] << '\n';
            if (temp[i] > temp_max) {
                temp_max = temp[i];
                ret = i;
            }
            cout << "ret:" << ret << '\n';
        }

        return ret + 1;
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
