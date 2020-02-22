//
// Created by Amos on 2020/02/22.
//
#include <iostream>
#include <string>
#include <set>

using namespace std;

int M;
set<int> space;

// Clion에서 마지막에 엔터를 왜 쳐주어야하지?
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> M;

    for (int i = 0; i < M; i++) {
        string command;
        cin >> command;

        int target;
        if (command == "add") {
            cin >> target;
            if (space.find(target) == space.end()) {
                space.insert(target);
            }
        } else if (command == "check") {
            cin >> target;
            if (space.find(target) == space.end()) {
                cout << 0 << '\n';
            } else {
                cout << 1 << '\n';
            }
        } else if (command == "remove") {
            cin >> target;
            if (space.find(target) != space.end()) {
                space.erase(target);
            }
        } else if (command == "toggle") {
            cin >> target;
            if (space.find(target) != space.end()) {
                space.erase(target);
            } else {
                space.insert(target);
            }
        } else if (command == "all") {
            // 바깥 i랑 중복하면 안된다..
            for (int j = 1; j <= 20; j++) {
                space.insert(j);
            }
        } else if (command == "empty") {
            space.clear();
        }
    }

    return 0;
}
