//
// Created by Amos on 2020/04/15.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ret(nums.size(), 1);

        int prefix = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            ret[i] = prefix;
            prefix = prefix * nums[i];
        }

        int postfix = nums[nums.size() - 1];
        for (int i = nums.size() - 2; i >= 0; i--) {
            ret[i] *= postfix;
            postfix = postfix * nums[i];
        }

        return ret;
    }
};

void printVector(vector<int>& nums) {
    for (auto elem : nums) {
        cout << elem << ' ';
    }
    cout << '\n';
}

int main() {
    Solution *s;
    vector<int> v;

    s = new Solution();
    v = {1, 2, 3, 4};
    vector<int> result = s->productExceptSelf(v);
    printVector(result);
    delete s;

    s = new Solution();
    v = {1, 2};
    result = s->productExceptSelf(v);
    printVector(result);
    delete s;

    return 0;
}
