//
// Created by Amos on 2020/05/17.
//
#include <iostream>
#include <queue>

using namespace std;

priority_queue<int> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;

        if (num != 0) {
            q.push(num);
            continue;
        }

        if (q.empty()) {
            cout << 0 << '\n';
        } else {
            cout << q.top() << '\n';
            q.pop();
        }
    }

    return 0;
}
