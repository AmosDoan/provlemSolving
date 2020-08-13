#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
private:
    set<int> visit;
    vector<int> nums;
    vector<int> result;
    int min;
    int target;

    void traverse(int current_idx, int len, int sum) {
        if (len == 2) {
            sum += nums[current_idx];
            if (abs(target - sum) < min) {
                min = sum;
            }
            return;
        }

        visit.insert(current_idx);
        sum += nums[current_idx];

        for (int i = 0; i < nums.size(); i++) {
            if (visit.find(i) == visit.end()) {
                traverse(i, len + 1, sum);
            }
        }

        visit.erase(current_idx);

    }

public:
    int threeSumClosest(vector<int>& nums, int target) {
        this->nums = nums;
        this->target = target;

        min = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            traverse(i, 0, 0);
        }

        return min;
    }
};

int main() {
    Solution *s;
    vector<int> params = {-1, 2, 1, -4};

    /*
    s = new Solution();
    cout << s->threeSumClosest(params, 1) << '\n';
    delete s;
    */

    params = {1, 1, 1, 0};
    s = new Solution();
    cout << s->threeSumClosest(params, -100) << '\n';
    delete s;
}

static const auto _ = []() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();
