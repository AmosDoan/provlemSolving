#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        if (s.empty()) {
            return 0;
        }

        if (s.size() == 1) {
            return 1;
        }

        map<char, int> m;
        for (char c : s) {
            m[c]++;
        }

        int ret = 0;
        int maximum_odd = 0;
        for (auto it = m.begin(); it != m.end(); it++) {
            int numbers = it->second;
            if (numbers % 2 == 0) {
                ret += numbers;
                m[numbers] = 0;
            } else {
                ret += (numbers - 1);
                m[numbers] = 1;
            }
        }

        for (auto it = m.begin(); it != m.end(); it++) {
            if (it->second == 1) {
                ret++;
                break;
            }
        }

        return ret;
    }
};

int main() {
    Solution *s;

    s = new Solution();
    cout << s->longestPalindrome("abcccdd") << '\n';
    delete s;
}

static const auto _ = []() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();
