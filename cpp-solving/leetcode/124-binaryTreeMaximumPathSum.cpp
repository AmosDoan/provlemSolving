//
// Created by Amos on 2020/04/29.
//
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
    int sum(TreeNode* current, int &max_val) {

        if (current == nullptr) {
            return 0;
        }

        max_val = max(current->val, max_val);
        int left = sum(current->left, max_val);
        int right = sum(current->right, max_val);

        if (left + right + current->val > 0) {
            max_val = max(left + right + current->val, max_val);
        }

        return max(0, max({0, left, right}) + current->val);
    }

public:
    int maxPathSum(TreeNode* root) {
        if (root->left == nullptr && root->right == nullptr) {
            return root->val;
        }

        int max_val = INT_MIN;
        sum(root, max_val);
        return max_val;
    }
};

int main() {
    Solution *s;

    auto *a = new TreeNode(1);
    auto *b = new TreeNode(2);
    auto *c = new TreeNode(3);

    a->left = b;
    a->right = c;

    s = new Solution();
    cout << s->maxPathSum(a) << '\n';
    delete s;

    auto *d = new TreeNode(-10);
    auto *e = new TreeNode(9);
    auto *f = new TreeNode(20);
    auto *g = new TreeNode(15);
    auto *h = new TreeNode(7);

    d->left = e;
    d->right = f;
    f->left = g;
    f->right = h;

    s = new Solution();
    cout << s->maxPathSum(d) << '\n';
    delete s;

    auto *i = new TreeNode(2);
    auto *j = new TreeNode(-1);
    i->left = j;

    s = new Solution();
    cout << s->maxPathSum(i) << '\n';
    delete s;

    auto *k = new TreeNode(0);
    auto *l = new TreeNode(1);
    auto *m = new TreeNode(1);
    k->left = l;
    k->right = m;

    s = new Solution();
    cout << s->maxPathSum(k) << '\n';
    delete s;

    auto *aa = new TreeNode(1);
    auto *ab = new TreeNode(-2);
    auto *ac = new TreeNode(-3);
    auto *ad = new TreeNode(1);
    auto *ae = new TreeNode(3);
    auto *af = new TreeNode(-2);
    auto *ag = new TreeNode(-1);

    aa->left = ab;
    aa->right = ac;
    ab->left = ad;
    ab->right = ae;
    ad->left = ag;
    ac->right = af;

    s = new Solution();
    cout << s->maxPathSum(aa) << '\n';
    delete s;
}

static const auto _ = []() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

