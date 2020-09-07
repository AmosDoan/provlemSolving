#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string temp;

        string result;
        while (getline(ss, temp, ' ')) {
            for (int i = temp.size() - 1; i >= 0; i--) {
                result += temp[i];
            }

            result += ' ';
        }

        return result.substr(0, result.size() - 1);
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
