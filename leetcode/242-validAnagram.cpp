#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int a[26] = {0}, b[26] = {0};

        for (char c : s) {
            a[c - 'a']++;
        }

        for (char c : t) {
            b[c - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if (a[i] != b[i]) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    Solution *s;

    s = new Solution();


    delete s;
}

static const auto _ = []() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();
