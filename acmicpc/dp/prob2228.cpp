//
// Created by Amos on 2020/03/07.
//
#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> numbers;
vector<vector<int>> group;

int solve(int idx, int current_group) {
    // Base Case
    if (idx >= N && current_group != M) {
        return 0;
    }

    if (current_group == M) {
        int sum = 0;
        for (int i = 0; i < M; i++) {
            cout << "DEBUG : GROUP "  << i << " ";
            for (auto elem : group[i]) {
                cout << elem << " ";
                sum += elem;
            }
            cout << '\n';
        }
        return sum;
    }

    // 현재 숫자는 선택 패스하는 케이스
    int current_pass = solve(idx + 1, current_group);

    int current_choice_only = 0;
    if (idx + 1 < N) {
        group[current_group].push_back(numbers[idx]);
        cout << "DEUBG PUSH // GROUP :: " << current_group << " NUMBERS :: " << numbers[idx] << '\n';
        current_choice_only = solve(idx + 1, current_group + 1);
        group[current_group].pop_back();
    }

    int current_choice = 0;
    if (idx + 2 < N) {
        group[current_group].push_back(numbers[idx]);
        cout << "DEUBG PUSH // GROUP :: " << current_group << " NUMBERS :: " << numbers[idx] << '\n';
        current_choice = solve(idx + 2, current_group + 1);
        group[current_group].pop_back();
    }

    int ret = max(current_pass, current_choice_only);
    ret = max(ret, current_choice);
    return ret;
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        numbers.push_back(a);
    }

    group.resize(M, vector<int>());

    cout << solve(0, 0) << '\n';
    return 0;
}
