#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;

        for (string op : ops) {
            if (op == "D") {
                int score = st.top();
                st.push(score * 2);
            } else if (op == "+") {
                int score1 = st.top();
                st.pop();
                int score2 = st.top();
                st.pop();

                st.push(score2);
                st.push(score1);
                st.push(score1 + score2);
            } else if (op == "C") {
                st.pop();
            } else {
                int number = stoi(op);
                st.push(number);
            }
        }

        int score = 0;
        while (!st.empty()) {
            score += st.top();
            st.pop();
        }

        return score;
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
