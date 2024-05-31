#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    bool isVowel(char &s) {
        return s == 'a' || s == 'e' || s == 'i' || s == 'o' || s =='u';
    }

public:
    string removeVowels(string S) {
        string ret;
        for (auto &s : S) {
            if (isVowel(s)) {
                continue;
            }

            ret += s;
        }

        return ret;
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
