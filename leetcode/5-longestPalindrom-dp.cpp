//
// Created by Amos on 2020/02/17.
//

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class Solution {
private:
    vector<vector<bool>> dp;

public:
    string longestPalindrome(string s) {
        int n = s.size();
        dp.resize(n, vector<bool>(n, false));

        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }

        int max_length = 0;
        pair<int, int> max_palindrome;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n - i; j++) {
                int start = j;
                int end = j + i;

                if (i == 1) {
                    dp[start][end] = s[start] == s[end];
                } else {
                    dp[start][end] = s[start] == s[end] && dp[start + 1][end - 1];
                }

                if (dp[start][end] && end - start > max_length) {
                    max_length = end - start;
                    max_palindrome = {start, end};
                }
            }
        }

        /*
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << dp[i][j] << ' ';
            }
            cout << '\n';
        }
        */

        dp.clear();

        int start = max_palindrome.first;
        int end = max_palindrome.second;
        return s.substr(start, end - start + 1);
    }
};

int main() {
    Solution *s;
    s = new Solution();
    cout << s->longestPalindrome("aa") << '\n';
    delete s;

    s = new Solution();
    cout << s->longestPalindrome("babad") << '\n';
    delete s;

    s = new Solution();
    cout << s->longestPalindrome("cbbd") << '\n';
    delete s;

    s = new Solution();
    cout << s->longestPalindrome("aaaa") << '\n';
    return 0;
}