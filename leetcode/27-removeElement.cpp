//
// Created by Amos on 2020/03/16.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int>::iterator it;
        for (it = nums.begin(); it != nums.end(); ) {
            if (*it == val) {
                it = nums.erase(it);
            } else {
                ++it;
            }
        }

        return nums.size();
    }
};

void printList(int length, vector<int>& nums) {
    cout << length << '\n';
    for (auto num : nums) {
        cout << num << ' ';
    }
    cout << '\n';
}

int main() {
    Solution *s;

    s = new Solution();
    vector<int> nums = {3, 2, 2, 3};
    printList(s->removeElement(nums, 3), nums);
    delete s;

    s = new Solution();
    nums = {0,1,2,2,3,0,4,2};
    printList(s->removeElement(nums, 2), nums);
    delete s;

    return 0;
}
