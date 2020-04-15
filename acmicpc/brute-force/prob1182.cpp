//
// Created by Amos on 2020/04/15.
//
#include <iostream>
#include <vector>

using namespace std;

int N, S;
vector<int> numbers;
int ret;

void dfs(int current, int &sum) {
    if (current >= numbers.size()) {
        return;
    }

    sum += numbers[current];
    if (sum == S) {
        ret++;
    }

    for (int i = current + 1; i < numbers.size(); i++) {
        dfs(i, sum);
    }

    sum -= numbers[current];
}

int solve() {
    for (int i = 0; i < numbers.size(); i++) {
        int sum = 0;
        dfs(i, sum);
    }
}

int main() {
    cin >> N >> S;

    for (int i = 0; i < N; i++) {
        int c = 0;
        cin >> c;
        numbers.push_back(c);
    }

    solve();
    cout << ret << '\n';

    return 0;
}
