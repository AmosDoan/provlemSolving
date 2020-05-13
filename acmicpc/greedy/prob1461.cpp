//
// Created by Amos on 2020/05/13.
//
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> negative_locations;
vector<int> positive_locations;

int N, M;

int calc(vector<int>& v1, vector<int>& v2) {
    int ret = 0;
    for (int i = v1.size() - 1 - M; i >= 0; i -= M) {
        ret += 2 * v1[i];
    }

    for (int i = v2.size() - 1; i >= 0; i -= M) {
        ret += 2 * v2[i];
    }
    return ret;
}

int solve() {
    // positive
    sort(positive_locations.begin(), positive_locations.end());

    // negative
    sort(negative_locations.begin(), negative_locations.end());

    int ret = 0;
    bool isMaxPositive = true;
    if (negative_locations.empty()) {
        ret += positive_locations[positive_locations.size() - 1];
    } else if (positive_locations.empty()) {
        isMaxPositive = false;
        ret += negative_locations[negative_locations.size() - 1];
    } else if (negative_locations[negative_locations.size() - 1] >
        positive_locations[positive_locations.size() - 1]) {
        ret += negative_locations[negative_locations.size() - 1];
        isMaxPositive = false;
    } else {
        ret += positive_locations[positive_locations.size() - 1];
    }

    if (isMaxPositive) {
        ret += calc(positive_locations, negative_locations);
    } else {
        ret += calc(negative_locations, positive_locations);
    }

    return ret;
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        int book;
        cin >> book;
        if (book < 0) {
            negative_locations.push_back(-book);
        } else {
            positive_locations.push_back(book);
        }
    }

    cout << solve() << '\n';

    return 0;
}
