//
// Created by Amos on 2020/04/24.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    Solution() {}

private:
};

int main() {
    Solution *s;

    s = new Solution();


    delete s;
}

static const auto _ = []() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();
