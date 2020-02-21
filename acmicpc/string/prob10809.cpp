//
// Created by Amos on 2020/02/22.
//
#include <iostream>
#include <vector>

using namespace std;

string s;

int main() {
    cin >> s;

    vector<int> solution = vector<int>(26, -1);

    for (int i = 0; i < s.size(); i++) {
        char current = s[i];
        int idx = current - 'a';

        if (solution[idx] == -1) {
            solution[idx] = i;
        }
    }

    for (int &s : solution) {
        cout << s << ' ';
    }
    cout << '\n';


    return 0;
}
