//
// Created by Amos on 2020/02/29.
//

#include <iostream>

using namespace std;

int main() {
    while (true) {
        int a, b;
        cin >> a;
        cin >> b;

        if (a == 0 && b == 0) {
            break;
        }

        cout << a + b << '\n';
    }
    return 0;
}