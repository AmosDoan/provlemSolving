//
// Created by Amos on 2020/03/02.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

    }
};

int main() {
    Solution *s;

    vector<string> sample = {"flower", "flow", "flight"};

    s = new Solution();
    cout << s->longestCommonPrefix(sample);
    delete s;

    return 0;
}