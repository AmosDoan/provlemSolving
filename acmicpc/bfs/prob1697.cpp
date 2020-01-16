//
// Created by Amos on 2020/01/15.
//

#include <iostream>
#include <queue>
#include <set>

// 숫자의 범위를 잘보자..
#define MAX_NUM 100001

using namespace std;

int start;
int target;
queue<pair<int, int>> q;
set<int> visit;

int solve() {
    q.push({start, 0});

    while (!q.empty()) {
        int current = q.front().first;
        int time = q.front().second;
        q.pop();

        if (current == target) {
            return time;
        }

        if (current + 1 < MAX_NUM && visit.find(current + 1) == visit.end()) {
            visit.insert(current + 1);
            q.push({current + 1, time + 1});
        }

        if (current - 1 >= 0 && visit.find(current - 1) == visit.end()) {
            visit.insert(current - 1);
            q.push({current - 1, time + 1});
        }

        if (2 * current < MAX_NUM && visit.find(2 * current) == visit.end()) {
            visit.insert(2 * current);
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
