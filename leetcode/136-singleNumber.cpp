//
// Created by Amos on 2020/03/24.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
        }
    }
};

int main() {
    Solution *s;
    vector<int> v;

    s = new Solution();
    v = {2, 2, 1};
    cout << s->singleNumber(v) << '\n';
    delete s;

    s = new Solution();
    v = {4, 1, 2, 1, 2};
    cout << s->singleNumber(v) << '\n';
    delete s;

    return 0;
}