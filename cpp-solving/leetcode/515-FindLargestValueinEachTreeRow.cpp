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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ret;
        if (root == nullptr) {
            return ret;
        }

        vector<priority_queue<int>> pq;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            TreeNode *current = q.front().first;
            int current_level = q.front().second;
            q.pop();

            if (current_level == pq.size()) {
                priority_queue<int> temp;
                pq.push_back(temp);
            }

            pq[current_level].push(current->val);

            if (current->left) {
                q.push({current->left, current_level + 1});
            }

            if (current->right) {
                q.push({current->right, current_level + 1});
            }
        }

        for (int i = 0; i < pq.size(); i++) {
            ret.push_back(pq[i].top());
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
