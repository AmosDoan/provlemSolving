//
// Created by Amos on 2020/03/22.
//
#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;

        if (nums.size() <= 2) {
            return result;
        }

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 2; i++) {
            if (i == 0 || (i > 0 && nums[i] != nums[i - 1])) {
                int current = nums[i];
                int left = i + 1;
                int right = nums.size() - 1;

                while (left < right) {
                    int sum = nums[left] + nums[right] + current;
                    if (sum == 0) {
                        result.push_back({current, nums[left], nums[right]});
                        while (left < right && nums[left] == nums[left + 1]) {
                            left++;
                        }
                        while (left < right && nums[right] == nums[right - 1]) {
                            right--;
                        }
                        left++;
                        right--;
                    } else if (sum > 0) {
                        right--;
                    } else if (sum < 0) {
                        left++;
                    }
                }
            }
        }

        return result;
    }
};

void printInfo(vector<vector<int>> &&ret) {
    for (auto v : ret) {
        for (auto elem : v) {
            cout << elem << ' ';
        }
        cout << '\n';
    }
}

int main() {
    Solution *s;
    vector<int> v;

    /*
    s = new Solution();
    v = {-1, 0, 1, 2, -1, -4};
    printInfo(s->threeSum(v));
    delete s;

    s = new Solution();
    v = {};
    printInfo(s->threeSum(v));
    delete s;
     */

    s = new Solution();
    v = {0, 0, 0};
    printInfo(s->threeSum(v));
    delete s;

    /*
    s = new Solution();
    v = {1, 1, 1};
    printInfo(s->threeSum(v));
    delete s;

    s = new Solution();
    v = {-1, 0, 1, 2, -1, -4};
    printInfo(s->threeSum(v));
    delete s;
     */

    return 0;
}
