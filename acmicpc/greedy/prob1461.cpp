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

int solve() {
    vector<int> trace;

    // positive
    sort(positive_locations.begin(), positive_locations.end());

    // negative
    sort(negative_locations.begin(), negative_locations.end(), std::greater<int>());

    int i;
    for (i = M - 1; i < positive_locations.size(); ) {
        trace.push_back(positive_locations[i]);
        i += M;
    }

    while (i < positive_locations.size()) {
        trace.push_back(positive_locations[i]);
    }

    for (int i = M - 1; i < negative_locations.size(); ) {
        trace.push_back(-negative_locations[i]);
        i += M;
    }

    i++;
    while (i < negative_locations.size()) {
        trace.push_back(-negative_locations[i++]);
    }

    sort(trace.begin(), trace.end());

    int ret = 0;
    for (int i = 0; i < trace.size() - 1; i++) {
        ret += 2 * trace[i];
    }
    ret += trace[trace.size() - 1];

    return ret;
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        int book;
        cin >> book;
        if (book < 0) {
            negative_locations.push_back(book);
        } else {
            positive_locations.push_back(book);
        }
    }

    cout << solve() << '\n';

    return 0;
}
