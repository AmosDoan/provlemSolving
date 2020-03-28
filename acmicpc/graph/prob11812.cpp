//
// Created by Amos on 2020/03/28.
//
#include <iostream>

using namespace std;

long long N, K, Q;

long long solve(long long node1, long long node2) {
    long long result = 0;
    while (node1 != node2) {
        if (node1 > node2) {
            node1 = (node1 - 2) / K + 1;
        } else {
            node2 = (node2 - 2) / K + 1;
        }

        result++;
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K >> Q;
    for (int i = 0; i < Q; i++) {
        long long node1 = 0, node2 = 0;
        cin >> node1 >> node2;

        if (1LL == K) {
            cout << abs(node1 - node2) << '\n';
        } else {
            cout << solve(node1, node2) << '\n';
        }
    }

    return 0;
}
