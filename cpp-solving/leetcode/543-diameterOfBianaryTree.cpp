//
// Created by Amos on 2020/04/11.
//
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
class Solution {
private:
    // height, diameter
    pair<int, int> getDiameter(TreeNode* root) {
        if (root->left == nullptr && root->right == nullptr) {
            return {0, 0};
        }

        int left_height = 0;
        int left_max_diameter = 0;
        if (root->left) {
            auto left = getDiameter(root->left);
            left_height = left.first + 1;
            left_max_diameter = left.second;
        }

        int right_height = 0;
        int right_max_diameter = 0;
        if (root->right) {
            auto right = getDiameter(root->right);
            right_height = right.first + 1;
            right_max_diameter = right.second;
        }

        int current_height = max(left_height, right_height);
        // 현재 노드를 지나는 가장 최대의 diameter
        int current_diameter = left_height + right_height;
        // right / left child의 second에는 현재 노드를 지나지 않는 가정 하의 최대 diameter
        int max_diameter = max(current_diameter, left_max_diameter);
        max_diameter = max(max_diameter, right_max_diameter);

        return {current_height, max_diameter};
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
       if (root == nullptr || (root->left == nullptr && root->right == nullptr)) {
           return 0;
       }
       auto ret = getDiameter(root);
       return max(ret.first, ret.second);
    }
};
*/

// L + R + 1의 max를 구해놓고 리턴할 때 1을 빼서 리턴한다.
class Solution {
private:
    int max_diameter;

    int dfs(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }

        int max_left = dfs(node->left);
        int max_right = dfs(node->right);

        max_diameter = max(max_diameter, max_left + max_right + 1);

        return max(max_left, max_right) + 1;
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        max_diameter = 0;
        dfs(root);
        return max_diameter - 1;
    }
};

int main() {
    Solution *s;

    auto *a = new TreeNode(1);
    auto *b = new TreeNode(2);
    auto *c = new TreeNode(3);
    auto *d = new TreeNode(4);
    auto *e = new TreeNode(5);

    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;

    s = new Solution();
    cout << s->diameterOfBinaryTree(a) << '\n';
    delete s;

    auto *f = new TreeNode(1);
    s = new Solution();
    cout << s->diameterOfBinaryTree(f) << '\n';
    delete s;

    auto *g = new TreeNode(1);
    auto *h = new TreeNode(2);
    g->left = h;

    s = new Solution();
    cout << s->diameterOfBinaryTree(g) << '\n';
    delete s;

    return 0;
}