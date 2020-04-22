//
// Created by Amos on 2020/04/22.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if (nums.size() == 0) {
            return 0;
        }

        if (nums.size() == 1) {
            return nums[0] == k;
        }

        vector<int> partialSum(nums.size(), 0);

        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            partialSum[i] = nums[i];
            if (i > 0) {
                partialSum[i] += partialSum[i - 1];
            }

            if (partialSum[i] == k) {
                count++;
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                int sum = partialSum[j] - partialSum[i];
                if (sum == k) {
                    count++;
                }
            }
        }
        return count;
    }
};

int main() {
    Solution *s;
    vector<int> v;

    s = new Solution();
    v = {1, 1, 1};
    cout << s->subarraySum(v, 2) << "\n";
    delete s;

    s = new Solution();
    v = {1, 1, 1};
    cout << s->subarraySum(v, 3) << "\n";
    delete s;

    s = new Solution();
    v = {1, 2, 3};
    cout << s->subarraySum(v, 3) << "\n";
    delete s;

    s = new Solution();
    v = {1,2,3,4,5,6,7,1,23,21,3,1,2,1,1,1,1,1,12,2,3,2,3,2,2};
    cout << s->subarraySum(v, 1) << "\n";
    delete s;

    return 0;
}
