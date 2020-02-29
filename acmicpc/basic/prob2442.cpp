//
// Created by Amos on 2020/02/29.
//
#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    for (int i = 0 ; i < N; i++) {
        for (int j = 0; j < N + i; j++) {
            if (j >= N - i -1 && j <= N - 1 + i) {
                cout << "*";
            } else {
                cout << ' ';
            }
        }
        cout << '\n';
    }

    return 0;
}

