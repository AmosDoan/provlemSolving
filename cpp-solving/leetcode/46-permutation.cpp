#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        this->nums = nums;

        for (int i = 0; i < nums.size(); i++) {
            vector<int> temp;
            traverse(0, i, temp);
        }

        return result;
    }
private:

    void traverse(int current_idx, int idx, vector<int> temp) {
        if (current_idx == nums.size() - 1) {
            temp.push_back(nums[idx]);
            result.push_back(temp);
        }

        visit.insert(idx);
        temp.push_back(nums[idx]);

        for (int i = 0; i < nums.size(); i++) {
            if (visit.find(i) == visit.end()) {
                traverse(current_idx + 1, i, temp);
            }
        }

        temp.pop_back();
        visit.erase(idx);
    }

    set<int> visit;
    vector<int> nums;
    vector<vector<int>> result;
};

int main() {
    Solution *s;

    vector<int> params = {1, 2, 3};
    s = new Solution();
    vector<vector<int>> result = s->permute(params);
    delete s;

    for (auto& v : result) {
        for (auto& e : v) {
            cout << e << " ";
        }
        cout << '\n';
    }

}

static const auto _ = []() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();
