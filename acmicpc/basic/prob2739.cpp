//
// Created by Amos on 2020/02/29.
//
#include <iostream>

using namespace std;

int main() {
    int N;

    cin >> N;

    for (int i = 1; i <= 9; i++) {
        cout << N << " * " << i << " = " << N * i << '\n';
    }

    return 0;
}
