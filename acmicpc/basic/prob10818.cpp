//
// Created by Amos on 2020/02/29.
//
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    vector<int> s;

    cin >> N;

    int max, min;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;

        if (i == 0) {
            max = a;
            min = a;
        } else {
            if (a > max) {
                max = a;
            }

            if (a < min) {
                min = a;
            }
        }
    }

    cout << min << ' ' << max << '\n';

    return 0;
}
