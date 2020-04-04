//
// Created by Amos on 2020/04/04.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }

        vector<int> cache;

        cache.resize(nums.size(), 0);
        cache[0] = nums[0];
        int ret = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            cache[i] = max(cache[i - 1] + nums[i], nums[i]);

            if (cache[i] > ret) {
                ret = cache[i];
            }
        }

        return ret;
    }
};

int main() {
    Solution *s;
    vector<int> v;

    s = new Solution();
    v = {-2 ,1, -3, 4, -1, 2, 1, -5, 4};
    cout << s->maxSubArray(v) << '\n';
    delete s;

    s = new Solution();
    v = {-2, -1};
    cout << s->maxSubArray(v) << '\n';
    delete s;

    s = new Solution();
    v = {-1, -2};
    cout << s->maxSubArray(v) << '\n';
    delete s;

    return 0;
}