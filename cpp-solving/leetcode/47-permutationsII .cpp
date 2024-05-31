#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
private:
    vector<int> nums;
    set<vector<int>> result_set;
    vector<vector<int>> result;
    set<int> visit;

    void traverse(int current_idx, int current_length, vector<int> temp) {
        if (current_length == nums.size() - 1) {
            temp.push_back(nums[current_idx]);
            result_set.insert(temp);
            temp.pop_back();
            return;
        }

        temp.push_back(nums[current_idx]);
        visit.insert(current_idx);

        for (int i = 0; i < nums.size(); i++) {
            if (visit.find(i) == visit.end()) {
                traverse(i, current_length + 1, temp);
            }
        }

        temp.pop_back();
        visit.erase(current_idx);
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        this->nums = nums;

        for (int i = 0; i < nums.size(); i++) {
            vector<int> temp;
            traverse(i, 0, temp);
        }

        for (auto& res : result_set) {
            result.push_back(res);
        }

        return result;
    }
};

int main() {
    Solution *s;

    s = new Solution();
    vector<int> v = {1, 1, 2};
    vector<vector<int>> ret = s->permuteUnique(v);

    for (auto& v : ret) {
        for (auto& e : v) {
            cout << e << ' ';
        }
        cout << '\n';
    }

    delete s;
}

static const auto _ = []() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();
