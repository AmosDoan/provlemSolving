//
// Created by Amos on 2020/04/16.
//
#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        stack<pair<char, int>> st1;
        stack<pair<char, int>> st2;

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            if (c == '(') {
                st1.push({c, i});
            }

            if (c == '*') {
                st2.push({c, i});
            }

            if (c == ')') {
                if (!st1.empty()) {
                    st1.pop();
                } else if (!st2.empty()) {
                    st2.pop();
                } else {
                    return false;
                }
            }
        }

        while (!st1.empty()) {
            auto st1_elem = st1.top();

            if (st2.empty()) {
                return false;
            }

            auto st2_elem = st2.top();

            st1.pop();
            st2.pop();

            if (st2_elem.second < st1_elem.second) {
                return false;
            }
        }
        return true;
    }
};

void printBoolean(bool result) {
    result ? cout << "true" << '\n' : cout << "false" << '\n';
}

int main() {
    Solution *s;

    s = new Solution();
    printBoolean(s->checkValidString("()"));
    delete s;

    s = new Solution();
    printBoolean(s->checkValidString("(*))"));
    delete s;

    s = new Solution();
    printBoolean(s->checkValidString("(*()"));
    delete s;

    s = new Solution();
    printBoolean(s->checkValidString("(*"));
    delete s;

    s = new Solution();
    printBoolean(s->checkValidString("*)"));
    delete s;

    // false
    s = new Solution();
    printBoolean(s->checkValidString("(())((())()()(*)(*()(())())())()()((()())((()))(*"));
    delete s;

    // false
    s = new Solution();
    printBoolean(s->checkValidString("**("));
    delete s;

    // false
    s = new Solution();
    printBoolean(s->checkValidString("**((*"));
    delete s;

    s = new Solution();
    printBoolean(s->checkValidString("(*)"));
    delete s;

    return 0;
}
