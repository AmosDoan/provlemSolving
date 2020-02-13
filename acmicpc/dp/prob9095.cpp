//
// Created by Amos on 2020/02/14.
//

#include <iostream>

using namespace std;

int solve(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else if (n < 0) {
        return 0;
    }

    return solve(n - 2) + solve(n - 1) + solve(n - 3);
}

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int N;
        cin >> N;
        cout << solve(N) << '\n';
    }

    return 0;
}
