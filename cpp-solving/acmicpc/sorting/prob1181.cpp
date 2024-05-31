//
// Created by Amos on 2020/04/05.
//
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// compare는 앞의 것이 앞으로 가는 상황에서 true 리턴
bool compare(string a, string b) {
    if (a.length() == b.length()) {
        return a < b;
    } else {
        return a.length() < b.length();
    };
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<string> buf;
    buf.reserve(N);
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        if (find(buf.begin(), buf.end(), s) == buf.end()) {
            buf.push_back(s);
        }
    }

    sort(buf.begin(), buf.end(), compare);

    for (auto elem : buf) {
        cout << elem << '\n';
    }
}
