//
// Created by Amos on 2020/03/24.
//
#include <iostream>
#include <vector>
#include <map>

using namespace std;

/*
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int, int> m;
        for (int num : nums) {
            if (m.find(num) == m.end()) {
                m[num] = 1;
            } else {
                m[num]++;
            }
        }

        for (auto & it : m) {
            if (it.second == 1) {
                return it.first;
            }
        }
        return 0;
    }
};
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        for (auto num : nums) {
            ret ^= num;
        }
        return ret;
    }
};

int main() {
    Solution *s;
    vector<int> v;

    s = new Solution();
    v = {2, 2, 1};
    cout << s->singleNumber(v) << '\n';
    delete s;

    s = new Solution();
    v = {4, 1, 2, 1, 2};
    cout << s->singleNumber(v) << '\n';
    delete s;

    return 0;
}