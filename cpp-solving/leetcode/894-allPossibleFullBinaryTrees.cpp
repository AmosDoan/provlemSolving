#include <iostream>
#include <vector>
#include <map>

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
    map<int, vector<TreeNode*>> cache;

public:
    vector<TreeNode*> allPossibleFBT(int N) {

        if (cache.find(N) == cache.end()) {
            vector<TreeNode*> ans;
            if (N == 1) {
                ans.push_back(new TreeNode(0));
            } else if (N % 2 == 1) {
                for (int x = 0; x < N; x++) {
                    int y = N - 1 - x;

                    for (TreeNode* left : allPossibleFBT(x)) {
                        for (TreeNode* right : allPossibleFBT(y)) {
                            TreeNode *bns = new TreeNode(0);
                            bns->left = left;
                            bns->right = right;
                            ans.push_back(bns);
                        }
                    }
                }
            }

            cache[N] = ans;
        }

        return cache[N];
    }
};

int main() {
    Solution *s;

    s = new Solution();
    s->allPossibleFBT(3);

    delete s;
}

static const auto _ = []() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();
