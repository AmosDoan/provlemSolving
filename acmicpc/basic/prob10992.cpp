//
// Created by Amos on 2020/03/01.
//
#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - 1 - i; j++) {
            cout << ' ';
        }

        if (i == 0) {
            cout << "*" << '\n';
            continue;
        }

        if (i == N - 1) {
            for (int j = 0; j < 2 * N - 1; j++) {
                cout << "*";
            }
        } else {

            for (int j = 0; j < 2 * i + 1; j++) {
                if (j == 0 || j == 2 * i) {
                    cout << "*";
                } else {
                    cout << ' ';
                }
            }
        }
        cout << '\n';
    }

    return 0;
}
