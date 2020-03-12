//
// Created by Amos on 2020/03/12.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int>::iterator it;
        for (it = nums.begin(); it != nums.end();) {
            if (it + 1 != nums.end() && *it == *(it + 1)) {
                // vector 삭제 시 성공한 다음 iterator를 리턴
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
    vector<int> nums = {1, 1, 2};
    int length = s->removeDuplicates(nums);
    printList(length, nums);
    delete s;

    s = new Solution();
    nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    length = s->removeDuplicates(nums);
    printList(length, nums);
    delete s;

    return 0;
}
