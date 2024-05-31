//
// Created by Amos on 2020/02/26.
//
#include <iostream>

using namespace std;

class Solution {
public:
    int numberOfSteps (int num) {
        int step = 0;
        while (num != 0) {
            if (num % 2 == 0)  {
                num /= 2;
            } else {
                num -= 1;
            }

            step++;
        }

        return step;
    }
};

int main() {
    Solution *s;

    s =  new Solution();
    cout << s->numberOfSteps(14) << '\n';
    delete s;

    s =  new Solution();
    cout << s->numberOfSteps(8) << '\n';
    delete s;

    s =  new Solution();
    cout << s->numberOfSteps(123) << '\n';
    delete s;

    return 0;
}
