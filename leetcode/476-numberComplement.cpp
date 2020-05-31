//
// Created by Amos on 2020/05/31.
//
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int findComplement(int num)
    {
        int bit_count = 0;
        int temp = num;

        while(temp != 0)
        {
            bit_count++;
            temp >>= 1;
        }

        return num ^ int(pow(2, bit_count) - 1);
    }
};

/*
class Solution {
public:
    int findComplement(int num) {
        long int cipher = 1;
        int ret = 0;
        while (num != 0) {
            int rest = num % 2;
            rest = rest == 0 ? 1 : 0;
            ret += rest * cipher;

            cipher *= 2;
            num = num / 2;
        }

        return ret;
    }
};
*/

int main() {
    Solution *s;

    s = new Solution();
    cout << s->findComplement(5) << '\n';
    delete s;

    s = new Solution();
    cout << s->findComplement(1) << '\n';
    delete s;

    s = new Solution();
    cout << s->findComplement(4) << '\n';
    delete s;

    s = new Solution();
    cout << s->findComplement(2147483647) << '\n';
    delete s;
}

static const auto _ = []() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

