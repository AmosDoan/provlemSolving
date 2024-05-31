//
// Created by Amos on 2020/04/13.
//
#include <iostream>
#include <vector>

using namespace std;

int N, K;
vector<int> v;

int solve() {
    int nr_coins = 0;
    int remain = K;
    for (int i = v.size() - 1; i >= 0; i--) {
        int current = v[i];

        if (current > remain) {
            continue;
        }

        nr_coins += remain / current;
        remain = remain % current;

        if (remain == 0) {
            break;
        }
    }

    return nr_coins;
}

int main() {
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        int coin;
        cin >> coin;
        v.push_back(coin);
    }

    cout << solve() << '\n';

    return 0;
}
