//
// Created by Amos on 2019/12/19.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {

    vector<int> list({1, 2, 3, 4});

    do {
        for (auto v : list) {
            cout << v;
        }
        cout << endl;
    } while (next_permutation(list.begin(), list.end()));

    return 0;
}

