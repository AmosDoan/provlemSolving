//
// Created by Amos on 2020/02/14.
//


class Solution {
private:
    bool isPalindrome(string s, int start, int end) {
        int left = start;
        int right = end;

        while (left <= right) {
            if(s[left] == s[right]) {
                left++;
                right--;
                continue;
            }
            return false;
        }
        return true;
    }

public:
    string longestPalindrome(string s) {
        vector<string> palindromes;
        map<char, vector<int>> table;
        if (isPalindrome(s, 0, s.size() - 1)) {
            return s;
        }

        for (int i = 0; i < s.length(); i++) {
            char current = s[i];
            if(table.find(current) == table.end()) {
                vector<int> s;
                table[current] = s;
            } else {
                for (auto it : table[current]) {
                    if(isPalindrome(s, it, i)) {
                        palindromes.push_back(s.substr(it, i - it + 1));
                    }
                }
            }
            table[current].push_back(i);
        }

        int max_index = 0;
        if (!palindromes.empty()) {
            for (int i = 0; i < palindromes.size(); i++) {
                if (palindromes[i].size() > palindromes[max_index].size()) {
                    max_index = i;
                }
            }
            return palindromes[max_index];
        } else {
            return s.substr(0, 1);
        }
    }
};