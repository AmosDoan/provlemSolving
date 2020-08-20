#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    set<string> dictionary;
    vector<int> cache;

    bool traverse(int start, string s) {
        if (start == s.size()) {
            return true;
        }

        int &ret = cache[start];
        if (ret != -1) {
            return ret == 1;
        }

        for (int i = start + 1; i <= s.size(); i++) {
            string subStr = s.substr(start, i - start);
            if (dictionary.find(subStr) != dictionary.end() && traverse(i, s)) {
                ret = 1;
                return true;
            }
        }

        ret = 0;
        return false;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        for (auto& word : wordDict) {
            dictionary.insert(word);
        }

        cache.resize(s.size(), -1);
        return traverse(0, s);
    }
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
