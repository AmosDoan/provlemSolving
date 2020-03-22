//
// Created by Amos on 2020/03/22.
//
#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
private:
    int size_of_input;
    vector<int> numbers;
    vector<vector<int>> result;
    set<int> s;

    void solve(int current_idx) {
        int temp, expected_sum = numbers[current_idx];

        for (int i = current_idx + 1; i < size_of_input; i++) {
            for (int j = i + 1; j < size_of_input; j++) {
                temp = numbers[i] + numbers[j];
                if (temp == -expected_sum) {
                    result.push_back({numbers[i] ,numbers[j], expected_sum});
                    break;
                }
            }
        }
    }

public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        numbers = nums;
        size_of_input = nums.size();

        for (int i = 0; i < nums.size(); i++) {
            int expected_sum = nums[i];

            if (s.find(expected_sum) == s.end()) {
                solve(i);
                s.insert(expected_sum);
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

    s = new Solution();
    v = {-1, 0, 1, 2, -1, -4};
    printInfo(s->threeSum(v));
    delete s;

    return 0;
}
