//
// Created by Amos on 2020/03/07.
//
#include <iostream>
#include <vector>

#define MIN -3276801

using namespace std;

int N, M;
vector<int> numbers;
vector<vector<int>> dp;

// current_idx 까지의 숫자를 고려하여 current_idx 수를 nr_group개의 구간으로 나눌 때
// 얻을 수 있는 최대 합
int solve(int nr_number, int nr_group) {
    if (nr_group == 0) {
        return 0;
    }

    if (nr_number <= 0) {
        return MIN;
    }

    int &ret = dp[nr_number][nr_group];
    if (ret != -1) {
        return ret;
    }

    // i 포함 X
    ret = solve(nr_number - 1, nr_group);

    // i 포함
    int temp_max = 0;
    for (int i = nr_number; i >= 1; i--) {
        temp_max += numbers[i];
        int temp = solve(i - 2, nr_group - 1) + temp_max;

        if (temp > ret) {
            ret = temp;
        }
    }

    return ret;
}

int main() {
    cin >> N >> M;

    numbers.push_back(0);
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        numbers.push_back(a);
    }

    dp.resize(N + 1, vector<int>(M + 1, -1));

    cout << solve(N, M) << '\n';

    /*
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }
    */

    return 0;
}
