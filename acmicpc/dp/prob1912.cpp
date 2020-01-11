//
// Created by Amos on 2020/01/11.
//
#include <cstdio>
#include <vector>
#include <set>

using namespace std;

int N;
vector<int> memoization;
vector<int> number_list;

int solve() {
    int max_number = number_list[0];
    bool first = true;

    for (int i = 0; i < N; i++) {
        int current = number_list[i];
        if (current == 0) {
            continue;
        }

        for (int j = 0; j < i + 1; j++) {
            if (!first && memoization[j] < 0) {
                continue;
            } else {
                first = false;
            }
            memoization[j] += current;

            if (current > 0 && memoization[j] > max_number) {
                max_number = memoization[j];
            }
        }
    }

    return max_number;
}

int main() {
    scanf("%d", &N);

    memoization.resize(N, 0);

    for (int i = 0; i < N; i++) {
        int number;
        scanf("%d", &number);
        number_list.push_back(number);
    }

    printf("%d\n", solve());

    return 0;
}