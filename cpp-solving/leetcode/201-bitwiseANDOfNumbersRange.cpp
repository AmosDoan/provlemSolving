//
// Created by Amos on 2020/04/23.
//
#include <iostream>

using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if (m == 0) {
            return 0;
        }

        if (m == INT_MAX && n == INT_MAX) {
            return INT_MAX;
        }

        bool zero = false;
        for (int i = 0; i < 31; i++) {
            unsigned int temp = (1 << i);

            if (temp > m && temp < n) {
                zero = true;
            }
        }

        if (zero) {
            return 0;
        }

        unsigned int ret = m;
        for (int i = m + 1; i <= n; i++) {
            ret &= i;
            if (i == INT_MAX) {
                break;
            }
        }

        return ret;
    }
};

int main() {
    Solution *s;

    /*
    s = new Solution();
    cout << s->rangeBitwiseAnd(5, 7) << '\n';
    delete s;

    s = new Solution();
    cout << s->rangeBitwiseAnd(20000, INT_MAX) << '\n';
    delete s;

    s = new Solution();
    cout << s->rangeBitwiseAnd(1, 1) << '\n';
    delete s;
    */

    s = new Solution();
    cout << s->rangeBitwiseAnd(2147483646, 2147483647) << '\n';
    delete s;

    return 0;
}
