//
// Created by Amos on 2020/03/28.
//
#include <iostream>
#include <set>

using namespace std;

long long N, K, Q;

long long solve(long long node1, long long node2) {
    set<long long> s;
    long long ancestor = node1;

    while (true) {
        s.insert(ancestor);
        ancestor = (ancestor - 2) / K + 1;

        if (ancestor == 1) {
            s.insert(1);
            break;
        }
    }

    long long common_ancestor = 1;
    ancestor = node2;
    while (ancestor != 1) {
        s.insert(ancestor);
        ancestor = (ancestor - 2) / K + 1;
        if (s.find(ancestor) != s.end() || ancestor == 1) {
            common_ancestor = ancestor;
            break;
        }
    }

    set<long long> result;
    for (auto i = s.begin(); i != s.end(); ++i) {
        if (*i >= common_ancestor) {
            result.insert(*i);
        }
    }

    return result.size() - 1;
}

int main() {
    cin >> N >> K >> Q;
    for (int i = 0; i < Q; i++) {
        long long node1 = 0, node2 = 0;
        cin >> node1 >> node2;
        cout << solve(node1, node2) << '\n';
    }

    return 0;
}
