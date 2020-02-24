//
// Created by Amos on 2020/02/24.
//
#include <iostream>
#include <map>

using namespace std;

class Solution {
private:
    map<char, int> table =
            {{'I', 1}, {'V', 5},
             {'X', 10}, {'L', 50},
             {'C', 100}, {'D', 500},
             {'M', 1000}};
public:
    int romanToInt(string s) {
        int size = s.size();
        int result = 0;
        for (int i = 0; i < size; i++) {
            char current = s[i];
            int current_int = table[current];

            if (i < size - 1) {
                char next = s[i + 1];

                if (current == 'I' && (next == 'V' || next == 'X')) {
                    current_int *= -1;
                } else if (current == 'X' && (next == 'L' || next == 'C')) {
                    current_int *= -1;
                } else if (current == 'C' && (next == 'D' || next == 'M')) {
                    current_int *= -1;
                }
            }
            result += current_int;
        }

        return result;
    }
};

int main() {
    Solution *s;

    s = new Solution();
    cout << s->romanToInt("III") << '\n';
    delete s;

    s = new Solution();
    cout << s->romanToInt("IV") << '\n';
    delete s;

    s = new Solution();
    cout << s->romanToInt("IX") << '\n';
    delete s;

    s = new Solution();
    cout << s->romanToInt("LVIII") << '\n';
    delete s;

    s = new Solution();
    cout << s->romanToInt("MCMXCIV") << '\n';
    delete s;

    s = new Solution();
    cout << s->romanToInt("XXVII") << '\n';
    delete s;

    s = new Solution();
    cout << s->romanToInt("I") << '\n';
    delete s;

    s = new Solution();
    cout << s->romanToInt("II") << '\n';
    delete s;

    return 0;
}