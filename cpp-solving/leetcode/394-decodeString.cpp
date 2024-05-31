#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
private:
    stack<int> numbers;
    stack<string> symbols;

public:
    string decodeString(string s) {
        int i = 0;
        string result;
        while (i < s.size()) {
            char current = s[i];

            if (isdigit(current)) {
                int nums = 0;

                while (isdigit(s[i])) {
                    nums = 10 * nums + (s[i] - '0');
                    i++;
                }
                numbers.push(nums);
            } else if (current == '[') {
                symbols.push(result);
                result.clear();
                i++;
            } else if (current == ']') {
                int cnt = numbers.top();
                numbers.pop();

                string temp_str = symbols.top();
                symbols.pop();

                for (int i = 0; i < cnt; i++) {
                    temp_str = temp_str + result;
                }

                result = temp_str;
                i++;
            } else {
                result += current;
                i++;
            }
        }

        return result;
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
