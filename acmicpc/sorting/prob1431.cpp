//
// Created by Amos on 2020/04/05.
//
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;

int sum(string &a) {
    int ret = 0;
    for (char curr : a) {
        int num = curr - '0';

        if (num >= 0 && num <= 9) {
            ret += num;
        }
    }

    return ret;
}

bool compare(string &a, string &b) {

    if (a.length() == b.length()) {
        int a_sum = sum(a);
        int b_sum = sum(b);

        if (a_sum == b_sum) {
            return a < b;
        } else {
            return a_sum < b_sum;
        }
    } else {
        return a.length() < b.length();
    }


}

int main() {
    cin >> N;

    vector<string> buf;
    buf.reserve(N);
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        buf.push_back(s);
    }

    sort(buf.begin(), buf.end(), compare);

    for (const auto& elem : buf) {
        cout << elem << '\n';
    }

    return 0;
}
