//
// Created by Amos on 2020/04/24.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                return i;
            }

            if (nums[i] > target) {
                return i;
            }
        }

        return nums.size();
    }
};

int main() {
    Solution *s;
    vector<int> v;

    s = new Solution();
    v = {1, 3, 5, 6};
    cout << s->searchInsert(v, 5) << '\n';
    delete s;

    s = new Solution();
    v = {1, 3, 5, 6};
    cout << s->searchInsert(v, 2) << '\n';
    delete s;

    s = new Solution();
    v = {1, 3, 5, 6};
    cout << s->searchInsert(v, 7) << '\n';
    delete s;

    s = new Solution();
    v = {1, 3, 5, 6};
    cout << s->searchInsert(v, 0) << '\n';
    delete s;
}

static const auto _ = []() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();
