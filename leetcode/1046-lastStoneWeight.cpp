//
// Created by Amos on 2020/04/12.
//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if (stones.size() == 1) {
            return stones[0];
        }

        if (stones.size() == 2) {
            return abs(stones[0] - stones[1]);
        }

        priority_queue<int> q;
        for (auto stone : stones) {
            q.push(stone);
        }

        while (q.size() > 1) {
            int s1 = q.top();
            q.pop();

            int s2 = q.top();
            q.pop();

            if (s1 != s2) {
                q.push(abs(s1 - s2));
            }
        }

        return q.empty() ? 0 : q.top();
    }
};

int main() {
    Solution *s;
    vector<int> v;

    s = new Solution();
    v = {2, 7, 4, 1, 8, 1};
    cout << s->lastStoneWeight(v) << '\n';
    delete s;

    s = new Solution();
    v = {2, 2};
    cout << s->lastStoneWeight(v) << '\n';
    delete s;

    s = new Solution();
    v = {9, 3, 2, 10};
    cout << s->lastStoneWeight(v) << '\n';
    delete s;

    return 0;
}

