//
// Created by Amos on 2020/04/01.
//
#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef pair<int, int> Coord;
typedef set<Coord> Map;

int T;
vector<pair<int, int>> visit;

bool traverse(int x, int y, int beer, Coord &target) {

    if (beer == 0) {
        return false;
    }

    if (x == target.first && y == target.second) {
        return true;
    }

}

bool solve(Coord &start, Coord &target, Map &m) {

}

int main() {
    cin >> T;

    for (int i = 0; i < T; i++) {
        int n_store;
        int x, y;
        cin >> n_store;
        cin >> x >> y;

        Coord start = {x, y};

        Map m;
        for (int j = 0; j < n_store; j++) {
            cin >> x >> y;
            m.insert({x, y});
        }

        cin >> x >> y;

        Coord target = {x, y};
        if (solve(start, target, m)) {
            cout << "happy" << '\n';
        } else {
            cout << "sad" << '\n';
        }
    }

    return 0;
}
