//
// Created by Amos on 2020/04/06.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

    }
};

void printResult(vector<vector<string>> &&ret) {
    for (auto v : ret) {
        for (auto s : v) {
            cout << s << " ";
        }
        cout << '\n';
    }
}

int main() {
    Solution *s;
    vector<string> v;

    s = new Solution();
    v = {"eat", "tea", "tan", "ate", "nat", "bat"};
    printResult(s->groupAnagrams(v));
    delete s;

    return 0;
}
