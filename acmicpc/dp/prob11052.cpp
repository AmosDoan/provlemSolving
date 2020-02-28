//
// Created by Amos on 2020/02/29.
//

#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<int>> dp;
vector<int> p;

int solve() {

}

int main() {
    cin >> N;

    for(int i = 0; i < N; i++) {
        int cost;
        cin >> cost;
        p.push_back(cost);
    }

    dp.resize(N, vector<int>(N, 0));

    cout << solve() << '\n';

    return 0;
}
