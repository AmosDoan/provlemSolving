#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
private:
    map<char, string> m =
            {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mon"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};

    int sz;
    string digits;
    vector<string> result;

    void traverse(int current_idx, string temp) {
        if (current_idx == sz) {
            result.push_back(temp);
            return;
        }

        char current = digits[current_idx];
        string str = m[current];

        for (int i = 0; i < str.size(); i++) {
            temp.push_back(str[i]);
            traverse(current_idx + 1, temp);
            temp.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        if (digits == "") {
            return result;
        }

        this->digits = digits;
        sz = digits.size();

        traverse(0, "");
        return result;
    }
};

int main() {
    Solution *s;

    s = new Solution();
    vector<string> result = s->letterCombinations("23");

    for (auto & elem : result) {
        cout << elem << '\n';
    }

    delete s;
}

static const auto _ = []() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();
