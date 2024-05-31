//
// Created by Amos on 2020/02/27.
//
#include <iostream>

using namespace std;

int main() {
    string s;

    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        if (i != 0 && i % 10 == 0) {
            cout << '\n';
        }
        cout << s[i];
    }
    cout << '\n';

    return 0;
}
