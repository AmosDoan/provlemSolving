//
// Created by Amos on 2020/02/22.
//

#include <iostream>

using namespace std;

/**
3
test1
test2
test3
 */

int N;
int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        string test;
        cin >> test;

        // cout이 한번 들어가는 순간 clion에서 마지막에 엔터를 입력해야함
        if (test == "test1") {
            cout << test << '\n';
        }
    }
}
