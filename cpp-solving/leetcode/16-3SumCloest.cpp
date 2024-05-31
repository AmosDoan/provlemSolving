#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
       sort(nums.begin(), nums.end());

       int diff = INT_MAX;
       for (int i = 0; i < nums.size() && diff != 0; i++) {
           int left = i + 1;
           int right = nums.size() - 1;

           while (left < right) {
               int sum = nums[i] + nums[left] + nums[right];

               if (abs(target - sum) < abs(diff)) {
                   diff = target - sum;
               }

               if (sum >= target) {
                   right--;
               } else {
                   left++;
               }
           }
       }

       return target - diff;
    }
};

int main() {
    Solution *s;
    vector<int> params = {-1, 2, 1, -4};
    s = new Solution();
    cout << s->threeSumClosest(params, 1) << '\n';
    delete s;

    /*
    params = {1, 1, 1, 0};
    s = new Solution();
    cout << s->threeSumClosest(params, -100) << '\n';
    delete s;

    params = {0, 2, 1, -3};
    s = new Solution();
    cout << s->threeSumClosest(params, 1) << '\n';
    delete s;
    */
}

static const auto _ = []() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();
