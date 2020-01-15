//
// Created by Amos on 2020/01/15.
//

#include <iostream>
#include <queue>

#define MAX_NUM 100000

using namespace std;

int start;
int target;
queue<pair<int, int>> q;

int solve() {
    q.push({start, 0});

    while (!q.empty()) {
        int current = q.front().first;
        int time = q.front().second;
        q.pop();

        if (current == target) {
            return time;
        }

        if (target <= 1.5 * current && target < MAX_NUM) {
            q.push({current - 1, time + 1});
            continue;
        }

        if (current > 0) {
            q.push({current - 1, time + 1});
        }

        int teleport = current * 2;
        if (teleport < MAX_NUM && 1.5 * current < target) {
            q.push({current * 2, time + 1});
        }
    }

    return 0;
}

int main() {
    cin >> start >> target;

    cout << solve();

    return 0;
}
