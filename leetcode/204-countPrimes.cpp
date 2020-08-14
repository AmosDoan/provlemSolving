#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if (n == 0 || n == 1) {
            return 0;
        }

        vector<bool> nums(n, true);
        for (int i = 2; i < sqrt(n); i++) {
            int j = 2;

            while (true) {
                int temp = i * j;
                if (temp >= n) {
                    break;
                }
                nums[temp] = false;
                j++;
            }
        }

        int ret = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i]) {
                ret++;
            }
        }

        return ret - 1;
    }
};

int main() {
    Solution *s;

    s = new Solution();
    cout << s->countPrimes(10) << '\n';
    delete s;
}

static const auto _ = []() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();
