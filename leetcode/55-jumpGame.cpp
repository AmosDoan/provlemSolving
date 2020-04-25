//
// Created by Amos on 2020/04/25.
//
#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    Solution() {}

    bool jump(int current_index, vector<int>& nums) {
        if (current_index == nums.size() - 1) {
            return true;
        }

        if (current_index >= nums.size()) {
            return false;
        }

        int maximum_jump = nums[current_index];

        if (maximum_jump == 0) {
            return false;
        }

        for (int i = maximum_jump; i > 0; i--) {
            int next_index = current_index + i;
            bool ret = jump(next_index, nums);
            if (ret) {
                return true;
            }
        }
        return false;
    }

    bool canJump(vector<int>& nums) {
        return jump(0, nums);
    }

private:
    set<int> visit;
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

    /*
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
    */

    s = new Solution();
    v = {3, 2, 1, 1, 0, 0};
    printBoolean(s->canJump(v));
    delete s;
}

static const auto _ = []() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();
