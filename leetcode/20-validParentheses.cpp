//
// Created by Amos on 2020/03/03.
//
#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char current : s) {
            if (current == '(' || current == '[' || current == '{') {
                st.push(current);
                continue;
            }

            if (st.empty()) {
                return false;
            }

            if ((current == ')' && st.top() != '(') ||
                (current == ']' && st.top() != '[') ||
                (current == '}' && st.top() != '{')) {
                return false;
            }

            st.pop();
        }

        return st.empty();
    }
};

int main() {
    std::cout.setf(std::ios::boolalpha);

    Solution *s;

    s = new Solution();
    cout << s->isValid("()") << '\n';
    delete s;

    s = new Solution();
    cout << s->isValid("()[]{}") << '\n';
    delete s;

    s = new Solution();
    cout << s->isValid("(]") << '\n';
    delete s;

    s = new Solution();
    cout << s->isValid("([)]") << '\n';
    delete s;

    s = new Solution();
    cout << s->isValid("{[]}") << '\n';
    delete s;

    s = new Solution();
    cout << s->isValid("[") << '\n';
    delete s;

    s = new Solution();
    cout << s->isValid("") << '\n';
    delete s;

    s = new Solution();
    cout << s->isValid("]") << '\n';
    delete s;

    return 0;
}