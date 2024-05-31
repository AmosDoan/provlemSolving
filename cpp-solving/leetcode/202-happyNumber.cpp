//
// Created by Amos on 2020/04/04.
//
#include <iostream>
#include <set>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        set<int> s;

        int number = n;
        while (true) {
            int sum = 0;
            while (number != 0) {
                int left = number % 10;
                number = number / 10;
                sum += left * left;
            }

            if (s.find(sum) != s.end()) {
                return false;
            } else {
                s.insert(sum);
            }

            if (sum == 1) {
                return true;
            }

            number = sum;
        }
    }
};

int main() {
    Solution *s;

    s = new Solution();
    cout << s->isHappy(19) << '\n';
    delete s;

    s = new Solution();
    cout << s->isHappy(20) << '\n';
    delete s;

    return 0;
}
