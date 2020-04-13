//
// Created by Amos on 2020/04/13.
//
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
private:
public:
    int findMaxLength(vector<int>& nums) {
        map<int, int> m;
        int maxLength = 0;
        int count = 0;

        m[0] = -1;
        for (int i = 0; i < nums.size(); i++) {
            count = count + (nums[i] == 0 ? -1 : 1);
            if (m.find(count) == m.end()) {
                m[count] = i;
            } else {
                maxLength = max(maxLength, i - m[count]);
            }
        }

        return maxLength;
    }
};

int main() {
    Solution *s;
    vector<int> v;

    s = new Solution();
    v = {1, 0};
    cout << s->findMaxLength(v) << '\n';
    delete s;

    s = new Solution();
    v = {0, 1, 0, 1, 1};
    cout << s->findMaxLength(v) << '\n';
    delete s;

    s = new Solution();
    v = {0, 1, 1, 0, 1, 0, 1, 1, 0, 0, 1, 0, 1, 0, 1};
    cout << s->findMaxLength(v) << '\n';
    delete s;

    return 0;
}
