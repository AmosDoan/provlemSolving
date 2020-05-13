//
// Created by Amos on 2020/05/13.
//
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> person;

int solve() {
    sort(person.begin(), person.end());

    int ret = 0;
    int wait = 0;
    for (int i : person) {
        ret += wait + i;
        wait += i;
    }

    return ret;
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        int cost;
        cin >> cost;
        person.push_back(cost);
    }

    cout << solve() << '\n';

    return 0;
}
