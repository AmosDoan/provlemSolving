//
// Created by Amos on 2020/04/01.
//
#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

typedef pair<int, int> Coord;

int T;
set<Coord> visit;
vector<Coord> stores;

bool safeManhattan(Coord a, Coord b) {
    return (abs(a.first - b.first) + abs(a.second - b.second)) <= 1000;
}

bool solve(Coord &start, Coord &target) {
    queue<Coord> q;

    q.push({start.first, start.second});

    while (!q.empty()) {
        Coord current = q.front();
        q.pop();

        if (safeManhattan(target, current)) {
            return true;
        }

        for (auto store : stores) {
            if (visit.find(store) == visit.end()) {
                if (safeManhattan(current, store)) {
                    visit.insert(store);
                    q.push({store.first, store.second});
                }
            }
        }
    }

    return false;
}

int main() {
    cin >> T;

    for (int i = 0; i < T; i++) {
        int n_store;
        int x, y;
        cin >> n_store;
        cin >> x >> y;

        Coord start = {x, y};

        for (int j = 0; j < n_store; j++) {
            cin >> x >> y;
            stores.emplace_back(x, y);
        }

        cin >> x >> y;

        Coord target = {x, y};
        if (solve(start, target)) {
            cout << "happy" << '\n';
        } else {
            cout << "sad" << '\n';
        }

        visit.clear();
        stores.clear();
    }

    return 0;
}
