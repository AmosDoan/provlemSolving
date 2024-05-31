//
// Created by Amos on 2020/02/24.
//
#include <iostream>
#include <sstream>

using namespace std;

// Retrospect : https://leetcode.com/problems/integer-to-roman/discuss/?currentPage=1&orderBy=hot&query=
class Solution {
private:
    string repeat(const string &str, int times) {
        stringstream stream;

        for (size_t i = 0; i < times; i++) {
            stream << str;
        }
        return stream.str();
    }

    string fillNumbers(int current, const string &sig1, const string &sig2,
                       const string &sig3) {
        string str;
        if (current < 4) {
            str = repeat(sig1, current);
        } else if (current == 4) {
            str = sig1 + sig2;
        } else if (current < 9) {
            str = sig2;
            str = str + repeat(sig1, current - 5);
        } else {
            str = sig1 + sig3;
        }

        return str;
    }

public:
    string intToRoman(int num) {
        string result;
        int cipher = 0;
        while (true) {
            int current = num % 10;
            num = num / 10;
            string current_str;

            if (cipher == 0) {
                current_str = fillNumbers(current, "I", "V", "X");
            } else if (cipher == 1) {
                current_str = fillNumbers(current, "X", "L", "C");
            } else if (cipher == 2) {
                current_str = fillNumbers(current, "C", "D", "M");
            } else if (cipher == 3) {
                current_str = fillNumbers(current, "M", "I", "I");
            }

            result = current_str + result;
            if (num == 0) {
                break;
            }

            cipher++;
        }
        return result;
    }
};

int main() {
    Solution *s;

    /*
    s = new Solution();
    cout << s->intToRoman(3) << '\n';
    delete s;

    s = new Solution();
    cout << s->intToRoman(4) << '\n';
    delete s;

    s = new Solution();
    cout << s->intToRoman(8) << '\n';
    delete s;
    */

    s = new Solution();
    cout << s->intToRoman(58) << '\n';
    delete s;

    s = new Solution();
    cout << s->intToRoman(1994) << '\n';
    delete s;

    s = new Solution();
    cout << s->intToRoman(20) << '\n';
    delete s;

    return 0;
}