//
// Created by Amos on 2020/02/14.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }

        zigzag.resize(numRows, vector<char>());

        for (int i = 0; i < numRows; i++) {
            int first_step = 2 * (numRows - 1) - 2 * i;
            int second_step = 2 * i;

            bool is_first_step = true;
            int current_idx = i;
            int length = s.size();

            while (current_idx < length) {
                zigzag[i].push_back(s[current_idx]);
                if (is_first_step && first_step) {
                    if (second_step != 0) {
                        is_first_step = false;
                    }
                    current_idx += first_step;
                } else if (second_step) {
                    if (first_step != 0) {
                        is_first_step = true;
                    }
                    current_idx += second_step;
                }
            }
        }

        string result;
        for (auto iter : zigzag) {
            for (auto s : iter) {
                result += s;
            }
        }

        zigzag.clear();
        return result;
    }
private:
    vector<vector<char>> zigzag;
};

int main() {
    Solution s;
    string result = s.convert("PAYPALISHIRING", 3);
    // TC 1.
    cout << result << '\n';
    assert(result == "PAHNAPLSIIGYIR");

    // TC 2.
    result = s.convert("PAYPALISHIRING", 4);
    cout << result << '\n';
    assert(result == "PINALSIGYAHRPI");

    // TC 3.
    result = s.convert("A", 1);
    cout << result << '\n';
    assert(result == "A");

    return 0;
}