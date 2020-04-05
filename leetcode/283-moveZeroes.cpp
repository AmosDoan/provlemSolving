//
// Created by Amos on 2020/04/05.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int temp = 0;
        for (int i = nums.size() - 1; i > 0; i--) {
            for (int j = 0; j < i; j ++) {
                if (nums[j] == 0) {
                    temp = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = temp;
                }
            }
        }
    }
};

void printVectors(vector<int> &v) {
    for (auto elem : v) {
        cout << elem << ' ';
    }
    cout << '\n';
}

int main() {
    Solution *s;
    vector<int> v;

    s = new Solution();
    v = {0, 1, 0, 3, 12};
    s->moveZeroes(v);
    printVectors(v);
    delete s;

    s = new Solution();
    v = {0, 0, 3, 12};
    s->moveZeroes(v);
    printVectors(v);
    delete s;

    s = new Solution();
    v = {0};
    s->moveZeroes(v);
    printVectors(v);
    delete s;

    return 0;
}