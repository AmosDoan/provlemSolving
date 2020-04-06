//
// Created by Amos on 2020/04/05.
//
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<int> counter;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    counter.resize(10001, 0);
    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;
        counter[n]++;
    }

    for (int i = 0; i < 10001; i++) {
        for (int j = 0; j < counter[i]; j++) {
            cout << i << '\n';
        }
    }

    return 0;
}
