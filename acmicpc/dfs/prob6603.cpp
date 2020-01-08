//
// Created by Amos on 2020/01/08.
//
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int k;
vector<int> S;

void dfs(int number, int order, vector<int> result, int index) {
    result[order] = number;
    if (order == 5) {
        for (auto it : result) {
            cout << it << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = index + 1; i < k; i++) {
        int next = S[i];
        dfs(next, order + 1, result, i);
    }
}

void solve() {
    for (int i = 0; i < k; i++) {
        vector<int> result(6, 0);
        dfs(S[i], 0, result, i);
    }
}

int main() {
    bool first_case = true;
    while (true) {
        scanf("%d", &k);

        if (k == 0) {
            break;
        } else if (first_case) {
            first_case = false;
        } else {
            cout << "\n";
        }

        for (int i = 0; i < k; i++) {
            int number;
            scanf("%d", &number);
            S.push_back(number);
        }
        S.clear();

        solve();
    }

    return 0;
}