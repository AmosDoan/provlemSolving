//
// Created by Amos on 2020/04/25.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    Solution() {}

    bool canJump(vector<int>& nums) {
        int lastPos = nums.size() - 1;
        for (int i = nums.size() - 2; i >= 0; i--) {
            bool possible = i + nums[i] >= lastPos;
            if (possible) {
                lastPos = i;
            }
        }

        return lastPos == 0;
    }
};

void printBoolean(bool result) {
    if (result) {
        cout << "true" << '\n';
    } else {
        cout << "false" << "\n";
    }
}

int main() {
    Solution *s;
    vector<int> v;

    s = new Solution();
    v = {2, 3, 1, 1, 4};
    printBoolean(s->canJump(v));
    delete s;

    s = new Solution();
    v = {3, 2, 1, 0, 4};
    printBoolean(s->canJump(v));
    delete s;

    s = new Solution();
    v = {2, 0};
    printBoolean(s->canJump(v));
    delete s;

    s = new Solution();
    v = {3, 2, 1, 1, 0, 0};
    printBoolean(s->canJump(v));
    delete s;

    s = new Solution();
    v = {2, 5, 0, 0};
    printBoolean(s->canJump(v));
    delete s;
}

static const auto _ = []() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();
