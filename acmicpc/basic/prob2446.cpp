//
// Created by Amos on 2020/02/29.
//
#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 2 * N - 1; j++) {
            if (j >= 2 * N - i - 1) {
                break;
            }

            if (j < i) {
                cout << " ";
            } else {
                cout << "*";
            }
        }
        cout << '\n';
    }

    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < 2 * N - 1; j++) {
            if (j > N + i) {
                break;
            }

            if (j < N - i - 2) {
                cout << " ";
            } else {
                cout << "*";
            }
        }
        cout << '\n';
    }

    return 0;
}

