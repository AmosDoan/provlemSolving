//
// Created by Amos on 2020/02/24.
//
#include <iostream>

using namespace std;

class Solution {
private:
public:
    string intToRoman(int num) {
        string result;
        while (true) {
            int cipher = num / 10;
            int current = num % 10;
            num = num / 10;

            string cipher_str;
            if (10 < cipher && cipher < 100) {
                cipher = current == 4 ? 'L' : 'C';
            } else if (100 < cipher && cipher < 1000) {
                cipher = current == 4 ? 'D' : 'M';
            }

            string current_str = "t";
            if (current < 4) {
                current_str.append("I", cipher);
            } else if (current == 4) {
                if (cipher_str == "L") {
                    current_str.append("X");
                } else if (cipher_str == "D") {
                    current_str.append("C");
                } else {
                    current_str.append("I");
                }
            } else if (current < 9) {
                current_str.append("V");
                current_str.append("I", 9 - cipher);
            } else if (current == 9) {
                if (cipher_str == "C") {
                    current_str.append("X");
                } else if (cipher_str == "M") {
                    current_str.append("C");
                } else {
                    current_str.append("I");
                }
            }
            cout << current_str << '\n';

            /*
            if (cipher_str != "") {
                current_str.append(cipher_str);
            }
            result = current_str + result;
             */

            if (num == 0) {
                break;
            }
        }
        return result;
    }
};

int main() {
    Solution *s;

    s = new Solution();
    cout << s->intToRoman(3) << '\n';
    delete s;

    /*
    s = new Solution();
    cout << s->intToRoman(4) << '\n';
    delete s;

    s = new Solution();
    cout << s->intToRoman(9) << '\n';
    delete s;
    */

    return 0;
}