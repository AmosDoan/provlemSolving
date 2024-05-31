//
// Created by Amos on 2020/02/22.
//

#include <iostream>

using namespace std;

/**
 * // 마지막에 엔터가 있어야 된다.
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

        // input의 마지막에 개행이 없는 경우 cout이 한번 들어가는 순간 clion에서 마지막에 엔터를 입력해야함
        // 즉 엔터는 input에 대한 개행
        cout << test << '\n';
        /*
        if (test == "test1") {
            cout << test << '\n';
        }
         */
    }
}
