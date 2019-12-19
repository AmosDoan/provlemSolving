//
// Created by Amos on 2019/12/19.
//
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int N;

    cin >> N;

    vector<int> list(N);

    for (int i = 0; i < N; i++) {
        list.at(i) = i + 1;
    }

    do {
        for (auto elem : list) {
            cout << elem << " ";
        }
        //cout << endl;
        cout << '\n';
    } while(next_permutation(list.begin(), list.end()));

    return 0;
}
