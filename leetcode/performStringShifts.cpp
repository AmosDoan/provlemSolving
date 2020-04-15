//
// Created by Amos on 2020/04/14.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int total_count = 0;
        for (auto elem : shift) {
            int direction = elem[0];
            int count = elem[1];

            if (direction == 0) {
                total_count -= count;
            } else {
                total_count += count;
            }
        }

        if (total_count == 0) {
            return s;
        }


        if (total_count > 0) {
            total_count = total_count % s.size();
            string rest = s.substr(0, s.length() - total_count);
            string m = s.substr(s.length() - total_count, total_count);
            return m + rest;
        } else {
            total_count =- total_count;
            total_count = total_count % s.size();
            string rest = s.substr(total_count, s.length() - total_count);
            string m = s.substr(0, total_count);
            return rest + m;
        }
    }
};

int main() {
    Solution *s;
    vector<vector<int>> v;

    v = {{0, 1}, {1, 2}};
    s = new Solution();
    cout << s->stringShift("abc", v) << '\n';
    delete s;

    v = {{1, 1}, {1, 1}, {0 , 2}, {1, 3}};
    s = new Solution();
    cout << s->stringShift("abcdefg", v) << '\n';
    delete s;

    v = {{0, 7}, {1, 7}, {1, 0}, {1, 3}, {0, 3}, {0, 6}, {1, 2}};
    s = new Solution();
    cout << s->stringShift("wpdhhcj", v) << '\n';
    delete s;

    return 0;
}
