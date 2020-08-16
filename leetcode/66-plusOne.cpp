#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; i--) {
            digits[i]++;

            if (digits[i] < 10) {
                return digits;
            }

            digits[i] = digits[i] % 10;
        }

        if (digits[0] == 0) {
            vector<int> ret(digits.size() + 1, 0);
            ret[0] = 1;

            for (int i = 1; i < ret.size(); i++) {
                ret[i] = digits[i - 1];
            }

            return ret;
        } else {
            return digits;
        }
    }
};

int main() {
    Solution *s;

    vector<int> v =  {9};
    s = new Solution();
    vector<int> ret = s->plusOne(v);
    for (auto& elem : ret) {
        cout << elem << ' ';
    }
    cout << '\n';
    delete s;
}

static const auto _ = []() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();
