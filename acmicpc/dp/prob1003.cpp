//
// Created by Amos on 2020/03/30.
//
#include <iostream>

using namespace std;

int T;
pair<int, int> cache[40];

pair<int, int> solve(int current) {
    if (current == 0) {
        return {1, 0};
    }

    if (current == 1) {
        return {0, 1};
    }

    pair<int, int>& ret = cache[current];
    if (ret.first != 0 && ret.second != 0) {
        return ret;
    }

    pair<int, int> left = solve(current - 1);
    pair<int, int> right = solve(current - 2);

    return ret = {left.first + right.first, left.second + right.second};
}

int main() {
    cin >> T;

    for (int i = 0; i < T; i++) {
        int N;
        cin >> N;
        pair<int, int> ret = solve(N);
        cout << ret.first << ' ' << ret.second << '\n';
    }

    return 0;
}
