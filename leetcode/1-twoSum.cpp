//
// Created by Amos on 2020/01/01.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    return vector<int> {i, j};
                }
            }
        }
        return vector<int>{};
    }
};


int main() {
    vector<int> numbers = vector<int> {2, 7, 11, 5};

    for (auto it : numbers) {
        cout << it << " ";
    }
    cout << "\n";

    Solution sol;
    vector<int> solution = sol.twoSum(numbers, 9);

    for (auto it : solution) {
        cout << it << " ";
    }
}
