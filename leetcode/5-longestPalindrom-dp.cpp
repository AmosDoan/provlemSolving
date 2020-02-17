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
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (j == i + 1) {
                    dp[i][j] = s[i] == s[j];
                } else {
                    dp[i][j] = s[i] == s[j] && dp[i + 1][j - 1];
                }

                if (dp[i][j] && j - i > max_length) {
                    max_length = j - i;
                    max_palindrome = {i, j};
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << dp[i][j] << ' ';
            }
            cout << '\n';
        }

        dp.clear();

        int start = max_palindrome.first;
        int end = max_palindrome.second;
        return s.substr(start, end - start + 1);
    }
};

int main() {
    Solution s;
    /*
    cout << s.longestPalindrome("aa") << '\n';
    cout << s.longestPalindrome("babad") << '\n';
    cout << s.longestPalindrome("cbbd") << '\n';
    */
    cout << s.longestPalindrome("aaaa") << '\n';
    return 0;
}