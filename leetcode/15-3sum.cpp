//
// Created by Amos on 2020/03/19.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    void solve(int current, int level, vector<int> &candidate,
               vector<vector<int>> &ret, vector<int> &nums) {
        if (level == 3) {
            candidate.push_back(nums[current]);

            int sum = 0;
            for (auto n : candidate) {
                sum += n;
            }

            if (sum == 0) {
                ret.push_back(candidate);
            }

            candidate.pop_back();
            return;
        }

        candidate.push_back(nums[current]);

        for (int i = current + 1; i < nums.size(); i++) {
            solve(i, level + 1, candidate, ret, nums);
        }

        candidate.pop_back();
    }

public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;

        for (int i = 0; i < nums.size(); i++) {
            vector<int> candidate;
            solve(i, 1, candidate, ret, nums);
        }

        return ret;
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

    s = new Solution();
    v = {-1, 0, 1, 2, -1, -4};
    printInfo(s->threeSum(v));
    delete s;

    return 0;
}
