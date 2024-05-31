//
// Created by Amos on 2020/04/04.
//
#include <iostream>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle == "") {
            return 0;
        }

        int ret = -1;
        for (int i = 0; i < haystack.size(); i++) {
            if (haystack[i] == needle[0]) {
                string tmp = haystack.substr(i, needle.size());
                if(tmp == needle) {
                    return i;
                }
            }
        }

        return ret;
    }
};

int main() {
    Solution *s;

    s = new Solution();
    cout << s->strStr("hello", "ll") << '\n';
    delete s;

    s = new Solution();
    cout << s->strStr("aaaaa", "bba") << '\n';
    delete s;

    s = new Solution();
    cout << s->strStr("mississippi", "issip") << '\n';
    delete s;

    return 0;
}