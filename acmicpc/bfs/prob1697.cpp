//
// Created by Amos on 2020/01/15.
//

#include <iostream>
#include <queue>
#include <set>

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

        visit.insert(current);

        if (current == target) {
            return time;
        }

        int candidate[4];
        candidate[0] = current + 1;
        candidate[1] = current - 1;
        candidate[2] = 2 * current;
        candidate[3] = 2 * (current - 1);

        int min = 200000;
        int min_idx = 0;
        for (int i = 0; i < 4; i++) {
            int difference = target - candidate[i];
            if (difference < min) {
                min = difference;
                min_idx = i;
            }
        }

        int next_time = time + 1;
        if (min_idx == 3) {
            next_time++;
        }

        if (visit.find(candidate[min_idx]) == visit.end()) {
            q.push({candidate[min_idx], next_time});
        }
    }

    return 0;
}

int main() {
    cin >> start >> target;

    cout << solve();

    return 0;
}
