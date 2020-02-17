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
    int max_length = 0;
    pair<int, int> max_palindrome;

    bool solve(string &s, int i, int j) {
        if (j == i) {
            dp[i][j] = true;
            return true;
        }

        if (j == i + 1) {
            dp[i][j] = s[i] == s[j];
        } else {
            dp[i][j] = s[i] == s[j] && solve(s, i + 1, j -1);
        }

        if (dp[i][j]) {
            if (j - 1 > max_length) {
                max_length = j - i;
                max_palindrome = {i, j};
            }
            return true;
        }
        return false;
    }

public:
    string longestPalindrome(string s) {
        int n = s.size();
        dp.resize(n, vector<bool>(n, false));

        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }

        solve(s, 0, s.size() - 1);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << dp[i][j] << ' ';
            }
            cout << '\n';
        }

        dp.clear();

        int start = max_palindrome.first;
        int end = max_palindrome.second;
        cout << "DEBUG :: " << start << ", " << end << '\n';
        return s.substr(start, end - start + 1);
    }
};

int main() {
    Solution *s;
    /*
    s = new Solution();
    cout << s->longestPalindrome("aa") << '\n';
    delete s;
    */

    s = new Solution();
    cout << s->longestPalindrome("babad") << '\n';
    delete s;

    /*
    s = new Solution();
    cout << s->longestPalindrome("cbbd") << '\n';
    delete s;

    s = new Solution();
    cout << s->longestPalindrome("aaaa") << '\n';
    delete s;
    */

    return 0;
}