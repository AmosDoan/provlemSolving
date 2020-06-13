//
// Created by Amos on 2020/06/13.
//
#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        map<char, int> m;

        for (auto c : s) {
            m[c]++;
        }

        for (int i = 0; i < s.size(); i++) {
            if (m[s[i]] == 1) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    Solution *s;

    s = new Solution();
    cout << s->firstUniqChar("leetcode") << '\n';
    delete s;

    s = new Solution();
    cout << s->firstUniqChar("loveleetcode") << '\n';
    delete s;
}

static const auto _ = []() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

