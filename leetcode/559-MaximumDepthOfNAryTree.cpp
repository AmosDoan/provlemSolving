#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int solve(Node* node) {
        if (node == nullptr) {
            return 0;
        }

        int max_children = 0;
        for (auto& elem : node->children) {
            max_children = max(max_children, solve(elem));
        }

        return 1 + max_children;
    }

public:
    int maxDepth(Node* root) {
        if (root == nullptr) {
            return 0;
        }

        return solve(root);
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
