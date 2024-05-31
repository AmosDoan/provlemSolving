#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {

        if (height.empty()) {
            return 0;
        }

        int water = 0;
        vector<int> left_cache;
        vector<int> right_cache;

        left_cache.resize(height.size(), 0);
        right_cache.resize(height.size(), 0);

        left_cache[0] = 0;
        right_cache[right_cache.size() - 1] = 0;

        for (int i = 1; i < height.size(); i++) {
            left_cache[i] = left_cache[i - 1] < height[i - 1] ? height[i - 1] : left_cache[i - 1];
        }

        for (int i = height.size() - 2; i >= 0; i--) {
            right_cache[i] = right_cache[i + 1] < height[i + 1] ? height[i + 1] : right_cache[i + 1];
        }


        for (int i = 1; i < height.size(); i++) {
            int wall = min(left_cache[i], right_cache[i]);
            if (wall > height[i]) {
                water += wall - height[i];
            }
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
