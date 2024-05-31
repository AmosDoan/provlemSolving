//
// Created by Amos on 2020/01/01.
//
#include <iostream>
#include <vector>
#include <map>

using namespace std;

// O(n^2)
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

class Solution2 {
private:
    map<int, int> hash;
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            int need = target - nums[i];

            auto it = hash.find(need);
            if (it != hash.end()) {
                return vector<int>{it->second, i};
            }

            hash[nums[i]] = i;
        }

        return vector<int>{};
    }
};

int main() {
    vector<int> numbers = vector<int>{2, 7, 11, 5};

    for (auto it : numbers) {
        cout << it << " ";
    }
    cout << "\n";

    Solution sol;
    vector<int> solution = sol.twoSum(numbers, 9);

    for (auto it : solution) {
        cout << it << " ";
    }

    Solution2 sol2;
    vector<int> solution2 = sol2.twoSum(numbers, 9);

    for (auto it : solution2) {
        cout << it << " ";
    }
}
