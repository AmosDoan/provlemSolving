//
// Created by Amos on 2020/04/09.
//
#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> st;

        for (auto c : S) {
            if (c == '#') {
                if (!st.empty()) {
                    st.pop();
                }
            } else {
                st.push(c);
            }
        }

        string candi1;
        while (!st.empty()) {
           char c = st.top();
           st.pop();
           candi1 += c;
        }

        for (auto c : T) {
            if (c == '#') {
                if (!st.empty()) {
                    st.pop();
                }
            } else {
                st.push(c);
            }
        }

        string candi2;
        while (!st.empty()) {
            char c = st.top();
            st.pop();
            candi2 += c;
        }

        return candi1 == candi2;
    }
};

int main() {
    Solution *s;

    s = new Solution();
    cout << s->backspaceCompare("ab#c", "ad#c") << '\n';
    delete s;

    s = new Solution();
    cout << s->backspaceCompare("ab##", "c#d#") << '\n';
    delete s;

    s = new Solution();
    cout << s->backspaceCompare("a##c", "#a#c") << '\n';
    delete s;

    s = new Solution();
    cout << s->backspaceCompare("a#c", "b") << '\n';
    delete s;

    s = new Solution();
    cout << s->backspaceCompare("y#fo##f", "y#f#o##f") << '\n';
    delete s;

    return 0;
}
