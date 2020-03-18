//
// Created by Amos on 2020/03/18.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    void solve(vector<string> &s, string candidate, int left, int valid) {
        if (candidate.size() == end) {
            if (valid == 0) {
                cout << candidate << '\n';
                s.push_back(candidate);
            }
            return;
        }

        if (valid == 0) {
            candidate.push_back('(');
            solve(s, candidate, left - 1, valid + 1);
            candidate.pop_back();
        } else if (valid > 0){

            if (left != 0) {
                candidate.push_back('(');
                solve(s, candidate, left - 1, valid + 1);
                candidate.pop_back();
            }

            candidate.push_back(')');
            solve(s, candidate, left, valid - 1);
            candidate.pop_back();
        } else {
            cout << "invalid" << '\n';
        }
    }

    int end;
public:
    vector<string> generateParenthesis(int n) {
        end = 2 * n;
        vector<string> ret;

        solve(ret, "", n, 0);

        return ret;
    }
};

int main() {
    Solution *s;

    s = new Solution();
    s->generateParenthesis(3);
    delete s;

    cout << '\n';

    s = new Solution();
    s->generateParenthesis(2);
    delete s;

    cout << '\n';

    s = new Solution();
    s->generateParenthesis(4);
    delete s;

    return 0;
}