//
// Created by Amos on 2020/05/17.
//
#include <iostream>
#include <set>

using namespace std;

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        set<int> s;

        for (auto j : J) {
            s.insert(j);
        }

        int count = 0;
        for (auto st : S) {
            if (s.find(st) != s.end()) {
                count++;
            }
        }
        return count;
    }
};

int main() {
    Solution *s;

    s = new Solution();
    cout << s->numJewelsInStones("aA", "aAAbbbb") << '\n';
    delete s;

    s = new Solution();
    cout << s->numJewelsInStones("z", "ZZ") << '\n';
    delete s;
}

static const auto _ = []() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

