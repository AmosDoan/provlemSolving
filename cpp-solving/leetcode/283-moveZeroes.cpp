//
// Created by Amos on 2020/04/05.
//
#include <iostream>
#include <vector>

using namespace std;

/*
 * Below class O(n^2) time complexity
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
*/

// Time complexity O(n)
/*
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int nonZeroElement = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[nonZeroElement++] = nums[i];
            }
        }

        // Suboptimal, since unnecessary 0 move operations can occurred if [0, 0, 0, ... , 1]
        for (int i = nonZeroElement; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};
*/

// Time complexity O(n) and prevent suboptimal
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (int i = 0, lastNonZero = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                int temp = nums[i];
                nums[i] = 0;
                nums[lastNonZero++] = temp;
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