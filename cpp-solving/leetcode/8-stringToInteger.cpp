//
// Created by Amos on 2020/02/27.
//
#include <iostream>
#include <vector>

/**
 * https://leetcode.com/problems/string-to-integer-atoi/discuss/521431/simple-C%2B%2B
 * https://leetcode.com/problems/string-to-integer-atoi/discuss/514945/C%2B%2B-code-with-comments
 */

using namespace std;

class Solution {
private:
    vector<int> numbers;
public:
    int myAtoi(string str) {
        bool is_positive = true;
        bool found = false;

        for (int i = 0; i < str.size(); i++) {
            char current = str[i];

            if (!found) {
                if (current == ' ') {
                    continue;
                }

                if (current == '+') {
                    found = true;
                    continue;
                }

                if (current == '-') {
                    found = true;
                    is_positive = false;
                    continue;
                }

                if (current > '9' || current < '0') {
                    break;
                } else {
                    found = true;
                }
            }

            if (found) {
                if (current > '9' || current < '0') {
                    break;
                }
            }

            numbers.push_back(current - '0');
        }

        if (numbers.empty()) {
            return 0;
        }

        int result = 0;

        for (int i = 0; i < numbers.size(); i++) {
            int number = numbers[i];

            if (!is_positive) {
                number *= -1;
            }

            if (is_positive && result > 0.1 * (INT_MAX - number)) {
                return INT_MAX;
            }

            if (!is_positive && result < 0.1 * (INT_MIN - number)) {
                return INT_MIN;
            }

            result = result * 10 + number;
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
    cout << s->myAtoi("2147483648") << '\n';
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

    s = new Solution();
    cout << s->myAtoi("words and 987") << '\n';
    delete s;

    s = new Solution();
    cout << s->myAtoi("4193 with words") << '\n';
    delete s;

    s = new Solution();
    cout << s->myAtoi("-91283472332") << '\n';
    delete s;

    s = new Solution();
    cout << s->myAtoi("3.14159") << '\n';
    delete s;

    s = new Solution();
    cout << s->myAtoi("+-2") << '\n';
    delete s;

    s = new Solution();
    cout << s->myAtoi("-+1") << '\n';
    delete s;

    /*
    // 2147483647
    //cout << INT_MAX << '\n';


    // -2147483648
    //cout << INT_MIN << '\n';
    */
    return 0;
}
