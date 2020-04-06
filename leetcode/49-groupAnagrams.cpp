//
// Created by Amos on 2020/04/06.
//
#include <iostream>
#include <vector>
#include <unordered_map>
// map은 red black tree로 매번 정렬 O(nlogn) unordered map은 hash table로 O(1)

using namespace std;

class Solution {
private:
    string countSort(string &str) {
        string ret;

        int charCount[26] = { 0 };

        for (int i = 0; i < str.length(); i++) {
            charCount[str[i] - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < charCount[i]; j++) {
                ret += (char)('a' + i);
            }
        }
        return ret;
    }

public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> m;

        for (auto str : strs) {
            string sorted = countSort(str);

            if (m.find(sorted) == m.end()) {
                vector<string> v;
                v.push_back(str);
                m[sorted] = v;
            } else {
                m[sorted].push_back(str);
            }
        }

        vector<vector<string>> ret;
        for (auto & iter : m) {
            ret.push_back(iter.second);
        }

        return ret;
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

static const auto _ = []() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

int main() {
    Solution *s;
    vector<string> v;

    s = new Solution();
    v = {"eat", "tea", "tan", "ate", "nat", "bat"};
    printResult(s->groupAnagrams(v));
    delete s;

    return 0;
}
