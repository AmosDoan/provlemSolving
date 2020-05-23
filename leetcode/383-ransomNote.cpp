//
// Created by Amos on 2020/05/24.
//
#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> m;

        for (auto ch : magazine) {
            m[ch]++;
        }

        for (auto ch : ransomNote) {
            if (m.find(ch) == m.end()) {
                return false;
            }

            if (m[ch] == 0) {
                return false;
            }

            m[ch]--;
        }

        return true;
    }
};

int main() {
    Solution *s;

    s = new Solution();
    cout << s->canConstruct("a", "b") << '\n';
    delete s;

    s = new Solution();
    cout << s->canConstruct("aa", "ab") << '\n';
    delete s;

    s = new Solution();
    cout << s->canConstruct("aa", "aab") << '\n';
    delete s;
}

static const auto _ = []() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

