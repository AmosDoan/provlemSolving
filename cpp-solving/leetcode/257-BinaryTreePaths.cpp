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
    vector<string> ret;

private:
    void traverse(TreeNode* current, string s) {
        if (current == nullptr) {
            return;
        }

        if (current->left == nullptr && current->right == nullptr) {
            s += to_string(current->val);
            ret.push_back(s);
            s.pop_back();
            return;
        } else {
            s += to_string(current->val);
            s += "->";
            traverse(current->left, s);
            traverse(current->right, s);
            s.pop_back();
        }
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        traverse(root, "");
        return ret;
    }
};

int main() {
    Solution *s;

    TreeNode a = TreeNode(5);
    TreeNode b = TreeNode(2, nullptr, &a);
    TreeNode c = TreeNode(3);
    TreeNode root = TreeNode(1, &b, &c);

    s = new Solution();
    vector<string> ret = s->binaryTreePaths(&root);

    for (auto &elem : ret) {
        cout << elem << '\n';
    }

    delete s;
}

static const auto _ = []() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();
