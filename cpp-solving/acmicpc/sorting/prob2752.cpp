//
// Created by Amos on 2020/04/01.
//
#include <iostream>

using namespace std;

int main() {
    int a[3];

    for (int i = 0; i < 3; i++) {
        int n;
        cin >> n;
        a[i] = n;
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3 - 1; j++) {
            if (a[j] >= a[j + 1]) {
                int temp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = temp;
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        cout << a[i] << ' ';
    }
    cout << '\n';

    return 0;
}
