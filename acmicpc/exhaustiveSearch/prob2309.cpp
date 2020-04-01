//
// Created by Amos on 2020/02/27.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> sample;

int sum_vector(int c1, int c2) {
    int sum = 0;
    for (int i = 0; i < 9; i++) {
        if (i == c1 || i == c2) {
            continue;
        }
        sum += sample[i];
    }
    return sum;
}

void solve() {
    for (int i = 0; i < 9; i++) {
        for (int j = i + 1; j < 9; j++) {
            int result = sum_vector(i, j);

            if (result == 100) {
                sample[i] = sample[j] = 0;
                return;
            }
        }
    }
}

int main() {

    for (int i = 0; i < 9; i++) {
        int n = 0;
        cin >> n;
        sample.push_back(n);
    }

    solve();

    sort(sample.begin(), sample.end());
    for (auto &e : sample) {
        if (e == 0) {
            continue;
        }
        cout << e << '\n';
    }

    return 0;
}
