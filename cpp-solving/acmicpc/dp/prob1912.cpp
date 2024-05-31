//
// Created by Amos on 2020/01/11.
//
#include <cstdio>
#include <vector>

using namespace std;

int N;
vector<int> memoization;
vector<int> number_list;

int solve() {
    int prior_sum = 0;
    int memo = 0;

    for (int i = 0; i < N; i++) {
        int current = number_list[i];
        memo = current + prior_sum;
        memoization.push_back(memo);
        if (memo < 0) {
            prior_sum = 0;
        } else if (memo > current) {
            prior_sum = memo;
        } else {
            prior_sum = current;
        }
    }

    int max_number = memoization[0];
    for (auto it : memoization) {
        if (it > max_number) {
            max_number = it;
        }
    }

    return max_number;
}

int main() {
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        int number;
        scanf("%d", &number);
        number_list.push_back(number);
    }

    printf("%d\n", solve());

    return 0;
}