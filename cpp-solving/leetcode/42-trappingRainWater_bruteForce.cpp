#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int water = 0;
        for (int i = 0; i < height.size(); i++) {

            int current_height = height[i];
            int left_max = current_height;
            for (int left = 0; left < i; left++) {
                if (height[left] > left_max) {
                    left_max = height[left];
                }
            }

            int right_max = current_height;
            for (int right = i + 1; right < height.size(); right++) {
                if (height[right] > right_max) {
                    right_max = height[right];
                }
            }

            water += min(left_max, right_max) - current_height;
        }

        return water;
    }
};

int main() {
    Solution *s;
    vector<int> v = {0,1,0,2,1,0,1,3,2,1,2,1};

    s = new Solution();
    cout << s->trap(v) << '\n';
    delete s;
}

static const auto _ = []() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();
