//
// Created by Amos on 2020/02/29.
//
#include <iostream>

using namespace std;

int main() {
    int N;

    cin >> N;

    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;

        cout << "Case #" << i + 1 << ": " << a << " + " << b << " = " << a + b << '\n';
    }
    return 0;
}
