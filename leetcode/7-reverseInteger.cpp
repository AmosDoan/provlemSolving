//
// Created by Amos on 2020/02/19.
//
#include <iostream>
#include <limits>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        bool isPositive = true;
        if (x < 0) {
            isPositive = false;
        }

        int result = 0;
        while (x != 0) {
            int remainder = x % 10;
            x = x / 10;

            if (isPositive && 0.1 * (INT_MAX - remainder) < result) {
                return 0;
            }

            if (!isPositive && 0.1 * (INT_MIN - remainder) > result) {
                return 0;
            }

            result = result * 10 + remainder;
        }

        return result;
    }
};

int main() {
    Solution *s;
    s = new Solution();
    cout << s->reverse(-123) << '\n';
    delete s;

    s = new Solution();
    cout << s->reverse(123) << '\n';
    delete s;


    s = new Solution();
    cout << s->reverse(1) << '\n';
    delete s;

    s = new Solution();
    cout << s->reverse(1534236469) << '\n';
    delete s;

    cout << INT_MAX << '\n';
    cout << INT_MIN << '\n';

    return 0;
}