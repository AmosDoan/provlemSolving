//
// Created by Amos on 2020/01/11.
//
#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_length = 0;
        int start = 0;
        map<string, int> table;

        for (int i = 0; i < s.size(); i++) {
            string current = string(1, s[i]);
            string subString;
            if (table.find(current) != table.end()) {
                start = table[current] + 1 > start ? table[current] + 1 : start;
            }
            subString = s.substr(start, i - start + 1);
            table[current] = i;
            table[subString] = i;

            if (subString.size() > max_length) {
                max_length = subString.size();
            }
        }

        table.clear();
        return max_length;
    }
};

int main() {
    Solution sol;
    cout << sol.lengthOfLongestSubstring("abc") << '\n';
    cout << sol.lengthOfLongestSubstring("bbbbb") << '\n';
    cout << sol.lengthOfLongestSubstring("pwwkew") << '\n';
    cout << sol.lengthOfLongestSubstring("dvdf") << '\n';
    cout << sol.lengthOfLongestSubstring("abcabcbb") << '\n';
    cout << sol.lengthOfLongestSubstring("tmmzuxt") << '\n';
    return 0;
}

