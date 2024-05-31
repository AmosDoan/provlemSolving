//
// Created by Amos on 2020/04/15.
//
#include <iostream>
#include <cmath>

using namespace std;

/*
class Solution {
public:
    int divide(int dividend, int divisor) {
        int ret = 0;
        bool is_positive = false;

        if (dividend == INT_MIN && divisor == 1) {
            return INT_MIN;
        }

        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        if (dividend == INT_MAX && divisor == 1) {
            return INT_MAX;
        }

        if (dividend == INT_MAX && divisor == -1) {
            return -INT_MAX;
        }

        if ((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0)) {
            is_positive = true;
        }

        if (dividend > 0) {
            dividend = -dividend;
        }

        int real_divisor = divisor;
        if (divisor > 0) {
            real_divisor = -divisor;
        }

        while (dividend <= real_divisor) {
            dividend -= real_divisor;

            if (ret == INT_MAX - 1) {
                return INT_MAX;
            }

            ret++;
        }

        if (is_positive) {
            return ret;
        }

        return -ret;
    }
};
 */

/**
 * a /b = e ^ (log(a) - log(b))
 */
class Solution {
public:
    int divide(int a, int b) {
        if (a == INT_MAX && b == INT_MIN) return 0;
        int x = a;
        int y = b;
        bool neg1 = 0, neg2 = 0;
        if (a < 0) neg1 = 1;
        if (b < 0) neg2 = 1;
        a = (a == INT_MIN) ? INT_MAX : abs(a);
        b = (b == INT_MIN) ? INT_MAX : abs(b);
        int ans = exp(log(a) - log(b));
        if (neg1 && neg2) return ans;
        else if (neg1 || neg2) return ans == INT_MAX ? INT_MIN :
                                      ((x == INT_MIN && y == 2) ? -ans-1 :-ans);
        return ans;

    }
};

int main() {
    Solution *s;

    s = new Solution();
    cout << s->divide(10, 3) << '\n';
    delete s;

    s = new Solution();
    cout << s->divide(7, -3) << '\n';
    delete s;

    s = new Solution();
    cout << s->divide(3, 3) << '\n';
    delete s;

    s = new Solution();
    cout << s->divide(-1, -1) << '\n';
    delete s;

    s = new Solution();
    cout << s->divide(-2147483648, -1) << '\n';
    delete s;

    return 0;
}
