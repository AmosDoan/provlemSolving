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
    int solve(TreeNode* root, TreeNode* node, int number) {
        if (node == nullptr) {
            return 0;
        }

        if (node == root) {
            return solve(root, node->left, number) + solve(root, node->right, number);
        } else {
            if (node->val != number) {
                return 0;
            }

            if (node->left == nullptr && node->right == nullptr) {
                return 1;
            } else {
                return 1 + max(solve(root, node->left, number), solve(root, node->right, number));
            }
        }
    }

public:
    int longestUnivaluePath(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        int max_length = 0;
        if (root == nullptr) {
            return max_length;
        }

        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();

            int temp = solve(current, current, current->val);

            if (temp > max_length) {
                max_length = temp;
            }

            if (current->left) {
                q.push(current->left);
            }

            if (current->right) {
                q.push(current->right);
            }
        }

        return max_length;
    }
};

int main() {
    Solution *s;


    TreeNode *a = new TreeNode(1);
    TreeNode *b = new TreeNode(1);
    TreeNode *c = new TreeNode(1);
    TreeNode *d = new TreeNode(1, a, b);
    TreeNode *e = new TreeNode(1, c, nullptr);
    TreeNode *f = new TreeNode(1, d, e);
    TreeNode *root = new TreeNode(1, nullptr, f);
    /*
    TreeNode *a = new TreeNode(1);
    TreeNode *b = new TreeNode(1);
    TreeNode *c = new TreeNode(5);
    TreeNode *d = new TreeNode(4, a, b);
    TreeNode *e = new TreeNode(5, nullptr, c);
    TreeNode *root = new TreeNode(1, d, e);
    */

    s = new Solution();
    cout << s->longestUnivaluePath(root) << '\n';
    delete s;
}

static const auto _ = []() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();
