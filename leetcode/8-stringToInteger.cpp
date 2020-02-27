//
// Created by Amos on 2020/02/27.
//
#include <iostream>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int result = 0;
        int cipher = 1;
        bool is_positive = true;

        if (str[0] == '-') {
            cipher *= -1;
            str = str.substr(1, str.size() - 1);
            is_positive = false;
        }

        int size = str.size();
        for (int i = size - 1; i >= 0; i--) {
            char current = str[i];
            if (current > '9'|| current <'0') {
                continue;
            }

            int number = current - '0';


            if (is_positive && number > (INT_MAX - result) / cipher) {
                return INT_MAX;
            }

            if (!is_positive && result < INT_MIN - cipher * number) {
                return INT_MIN;
            }

            result += number * cipher;
            cipher *= 10;
        }

        return result;
    }
};

int main() {
    Solution *s;

    s = new Solution();
    cout << s->myAtoi("42") << '\n';
    delete s;

    s = new Solution();
    cout << s->myAtoi("   42") << '\n';
    delete s;

    s = new Solution();
    cout << s->myAtoi("   -42") << '\n';
    delete s;

    s = new Solution();
    cout << s->myAtoi("2147483647") << '\n';
    delete s;

    s = new Solution();
    cout << s->myAtoi("9") << '\n';
    delete s;

    s = new Solution();
    cout << s->myAtoi("a") << '\n';
    delete s;

    s = new Solution();
    cout << s->myAtoi("-1") << '\n';
    delete s;

    s = new Solution();
    cout << s->myAtoi("-10") << '\n';
    delete s;

    s = new Solution();
    cout << s->myAtoi("-2147483649") << '\n';
    delete s;

    // 2147483647
    //cout << INT_MAX << '\n';


    // -2147483648
    //cout << INT_MIN << '\n';

    return 0;
}
