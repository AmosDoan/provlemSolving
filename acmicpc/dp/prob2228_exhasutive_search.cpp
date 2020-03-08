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
    if (idx > N && current_group != M) {
        return 0;
    }

    if (current_group == M) {
        int sum = 0;
        for (int i = 0; i < M; i++) {
            for (auto elem : group[i]) {
                sum += elem;
            }
        }
        return sum;
    }

    // 현재 숫자는 현재 그룹에서 패스
    bool is_current_empty = group[current_group].empty();
    int current_pass = solve(idx + 1, is_current_empty ? current_group : current_group + 1);

    // 현재 숫자 현재 그룹에 선택
    int current_choice = 0;
    if (idx < N) {
        group[current_group].push_back(numbers[idx]);
        // 다음 수는 현재 그룹에 넣을 수 밖에 없음
        current_choice = solve(idx + 1, current_group);
        group[current_group].pop_back();
    }

    int ret = max(current_pass, current_choice);
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
