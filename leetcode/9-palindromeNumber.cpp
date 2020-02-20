//
// Created by Amos on 2020/02/21.
//
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);

        int i = 0;
        int j = s.size() - 1;
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }

            i++;
            j--;
        }

        return true;
    }
};

int main() {
    Solution *s;

    s = new Solution();
    cout << s->isPalindrome(121) << '\n';
    delete s;

    s = new Solution();
    cout << s->isPalindrome(-121) << '\n';
    delete s;

    s = new Solution();
    cout << s->isPalindrome(1) << '\n';
    delete s;

    s = new Solution();
    cout << s->isPalindrome(10) << '\n';
    delete s;


    return 0;
}
