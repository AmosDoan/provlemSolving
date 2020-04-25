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

    int jump(int current_index, vector<int>& nums) {
        if (current_index == nums.size() - 1) {
            return 1;
        }

        if (current_index >= nums.size()) {
            return 0;
        }

        int &ret = cache[current_index];
        if (ret != -1) {
            return ret;
        }

        int maximum_jump = nums[current_index];

        if (maximum_jump == 0) {
            return ret = 0;
        }

        int further_jump = min((unsigned long)current_index + maximum_jump, nums.size() - 1);
        for (int i = further_jump; i > current_index; i--) {
            if (jump(i, nums)) {
                return ret = 1;
            }
        }
        return ret = 0;
    }

    bool canJump(vector<int>& nums) {
        cache.resize(nums.size(), -1);
        return jump(0, nums) == 1;
    }

private:
    set<int> visit;
    vector<int> cache;
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
