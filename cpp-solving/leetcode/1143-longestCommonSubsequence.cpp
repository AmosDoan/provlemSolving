//
// Created by Amos on 2020/04/26.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        if (text1.empty() || text2.empty()) {
            return 0;
        }

        cache.resize(text1.size() + 1, vector<int>(text2.size() + 1, 0));
        for (int i = 1; i <= text1.size(); i++) {
            for (int j = 1; j <= text2.size(); j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    cache[i][j] = cache[i - 1][j - 1] + 1;
                } else {
                    cache[i][j] = max(cache[i - 1][j], cache[i][j - 1]);
                }
            }
        }

        return cache[text1.size()][text2.size()];
    }

private:
    vector<vector<int>> cache;
};

int main() {
    Solution *s;

    s = new Solution();
    cout << s->longestCommonSubsequence("abcde", "ace") << '\n';
    delete s;

    s = new Solution();
    cout << s->longestCommonSubsequence("abc", "abc") << '\n';
    delete s;

    s = new Solution();
    cout << s->longestCommonSubsequence("abc", "def") << '\n';
    delete s;

    s = new Solution();
    cout << s->longestCommonSubsequence("aba", "aaa") << '\n';
    delete s;

    s = new Solution();
    cout << s->longestCommonSubsequence("ezupkr", "ubmrapg") << '\n';
    delete s;
}

static const auto _ = []() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();


