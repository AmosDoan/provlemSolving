//
// Created by Amos on 2020/04/30.
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
    bool find(TreeNode* current, int current_index) {
        if (current == nullptr) {
            return false;
        }

        if (current->val != arr[current_index]) {
            return false;
        }

        if (current_index == arr.size() - 1) {
            return !(current->left || current->right);
        }

        return find(current->left, current_index + 1) || find(current->right, current_index + 1);
    }

public:
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        this->arr = arr;
        return find(root, 0);
    }

private:
    vector<int> arr;
};

void printBoolean(bool && result) {
    if (result) {
        cout << "true" << '\n';
    } else {
        cout << "false" << '\n';
    }
}

int main() {
    Solution *s;
    vector<int> v;

    auto a = new TreeNode(0);
    auto b = new TreeNode(1);
    auto c = new TreeNode(0);
    auto d = new TreeNode(0);
    auto e = new TreeNode(1);
    auto f = new TreeNode(0);
    auto g = new TreeNode(1);
    auto h = new TreeNode(0);
    auto i = new TreeNode(0);

    a->left = b;
    a->right = c;

    b->left = d;
    b->right = e;

    c->left = f;

    d->right = g;

    e->left = h;
    e->right = i;

    s = new Solution();
    v = {0, 1, 0, 1};
    printBoolean(s->isValidSequence(a, v));
    delete s;

    s = new Solution();
    v = {0, 0, 1};
    printBoolean(s->isValidSequence(a, v));
    delete s;

    s = new Solution();
    v = {0, 1, 1};
    printBoolean(s->isValidSequence(a, v));
    delete s;
}

static const auto _ = []() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

