//
// Created by Amos on 2020/02/22.
//
// 이 문제의 교훈 : visit을 set으로 할 때에는 주의하자
#include <iostream>
#include <vector>
#include <set>

#define USING_MEMO

using namespace std;

int R,C;
vector<string> map;
// visit을 set으로 할 때와 bool로 할 때 시간 초과 발생
#ifdef USING_MEMO
set<char> memo;
#else
bool visit[92];
#endif

int d_row[4] = {1, -1, 0, 0};
int d_col[4] = {0 ,0, 1, -1};
int max_distance = 1;

void solve(int row, int col, int distance) {

    //cout << "visit - row : " << row << ", col : " << col << ", distance : " << distance << ", current : " << map[row][col] << '\n';

    for (int i = 0; i < 4; i++) {
        int next_row = row + d_row[i];
        int next_col = col + d_col[i];

        if (next_row < R && next_row >= 0 && next_col < C && next_col >= 0) {
#ifdef USING_MEMO
            if (memo.find(map[next_row][next_col]) != memo.end()) {
#else
            if (visit[(int)map[next_row][next_col]]) {
#endif
                if (max_distance < distance) {
                    max_distance = distance;
                }
                // 메모리 초과가 발생하였는데, continue의 위치가 엉뚱한 곳에 있다보니 Stack overflow로 예상
                continue;
            }

#ifdef USING_MEMO
            memo.insert(map[next_row][next_col]);
#else
            visit[(int)map[next_row][next_col] ] = true;
#endif
            solve(next_row, next_col, distance + 1);
#ifdef USING_MEMO
            memo.erase(map[next_row][next_col]);
#else
            visit[(int)map[next_row][next_col] ] = false;
#endif
        }
    }
}

int main() {
    cin >> R >> C;

    for (int i = 0; i < R; i++) {
        string s;
        cin >> s;
        map.push_back(s);
    }

#ifdef USING_MEMO
    memo.insert(map[0][0]);
#else
    visit[(int)map[0][0]] = true;
#endif
    solve(0, 0, 1);

    cout << max_distance << '\n';

    return 0;
}
