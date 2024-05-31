//
// Created by Amos on 2020/03/02.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) {
            return "";
        }

        bool is_common = true;
        string commonPrefix;

        for (int i = 0; i <= strs[0].size(); i++) {
            char current = strs[0][i];

            for (string str : strs) {
                if (str[i] != current) {
                    is_common = false;
                    break;
                }
            }

            if (!is_common) {
                break;
            } else {
                commonPrefix += current;
            }
        }

        return commonPrefix;
    }
};

int main() {
    Solution *s;

    vector<string> sample = {"flower", "flow", "flight"};

    s = new Solution();
    cout << "sol : " << s->longestCommonPrefix(sample) << '\n';

    sample = {"dog","racecar","car"};
    cout << "sol : " << s->longestCommonPrefix(sample) << '\n';


    sample = {};
    cout << "sol : " << s->longestCommonPrefix(sample) << '\n';

    return 0;
}