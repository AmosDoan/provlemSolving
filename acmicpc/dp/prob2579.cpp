//
// Created by Amos on 2020/05/24.
//
#include <iostream>
#include <climits>
#include <vector>

using namespace std;

int N;
vector<int> stairs;
vector<vector<int>> dp;

int traverse(int current, int sum, unsigned int visit) {
    if (current < 0) {
        return sum;
    }

    if (visit & 1 << current && visit & 1 << (current + 1) && visit & 1 << (current + 2)) {
        return INT_MIN;
    }

    int &ret = dp[current][visit];
    if (ret != -1) {
        return ret;
    }

    if (current == 0) {
        return ret = sum + stairs[0];
    }

    sum += stairs[current];

    // miss point : visit |= 를 하면 수정됨
    return ret = max(traverse(current - 1, sum, visit | 1 << (current - 1)),
                     traverse(current - 2, sum, visit | 1 << (current - 2)));
}

int solve() {
    int visit_size = (1 << N) - 1;
    dp.resize(N, vector<int>(visit_size, -1));
    return traverse(N - 1, 0, 1 << (N - 1));
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        int stair;
        cin >> stair;
        stairs.push_back(stair);
    }

    cout << solve() << '\n';

    return 0;
}
