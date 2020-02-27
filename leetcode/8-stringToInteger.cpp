//
// Created by Amos on 2020/02/27.
//
#include <iostream>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {

    }
};

int main() {
    Solution *s;

    s = new Solution();
    cout << s->myAtoi("42") << '\n';
    delete s;

    return 0;
}
