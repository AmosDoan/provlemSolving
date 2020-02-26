//
// Created by Amos on 2020/02/27.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> sample;

bool solve(int start, int count, vector<int> &collect) {
    if (count == 7) {
        int sum = 0;
        for (auto &e : collect) {
            sum += e;
        }
        return sum == 100;
    }

    for (int i = start; i++; i < 7) {
        if(solve(i + 1, count + 1, collect)) {
            return true;
        }
    }
}

int main() {

    for (int i = 0; i < 7; i++) {
        int n = 0;
        cin >> n;
        sample.push_back(n);
    }

    //cout << solve() << '\n';

    return 0;
}
