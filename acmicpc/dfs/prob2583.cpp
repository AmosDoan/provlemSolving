//
// Created by Amos on 2020/01/12.
//
#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include <algorithm>

using namespace std;

int M;
int N;
int K;

typedef struct square_s {
    pair<int, int> start_bound;
    pair<int, int> end_bound;
} square;

vector<vector<int>> map;
vector<int> result;
vector<square> squares;
set<pair<int, int>> visit;

int dfsForCount(int x, int y) {
    if (map[x][y] != 0 || visit.find(make_pair(x, y)) != visit.end()) {
        return 0;
    }

    int area = 1;
    visit.insert(make_pair(x, y));

    if (x < N - 1) {
        area += dfsForCount(x + 1, y);
    }

    if (x > 0) {
        area += dfsForCount(x - 1, y);
    }

    if (y < M - 1) {
        area += dfsForCount(x, y + 1);
    }

    if (y > 0) {
        area += dfsForCount(x, y - 1);
    }

    return area;
}

// 사실 칠할때는 DFS안해줘도 된다...
/**
 *  for (int y = y1; y < y2; y++)
 *    for (int x = x1; x < x2; x++)
 *          graph[y][x] = 1;
 */
void dfs(int x, int y, pair<int, int> start_bound, pair<int, int> end_bound, int marker) {
    if (x < start_bound.first || y < start_bound.second ||
        x > end_bound.first - 1 || y > end_bound.second - 1 || map[x][y] == marker) {
        return;
    }

    map[x][y] = marker;

    if (x < N) {
        dfs(x + 1, y, start_bound, end_bound, marker);
    }

    if (x > 0) {
        dfs(x - 1, y, start_bound, end_bound, marker);
    }

    if (y < M) {
        dfs(x, y + 1, start_bound, end_bound, marker);
    }

    if (y > 0) {
        dfs(x, y - 1, start_bound, end_bound, marker);
    }
}

void solve() {
    for (int i = 0; i < squares.size(); i++) {
        square sq = squares[i];
        int start_x = sq.start_bound.first;
        int start_y = sq.start_bound.second;
        dfs(start_x, start_y, sq.start_bound, sq.end_bound, i + 1);
    }

    int number = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 0 && visit.find(make_pair(i, j)) == visit.end()) {
                number++;
                result.push_back(dfsForCount(i, j));
            }
        }
    }

    sort(result.begin(), result.end());

    cout << number << '\n';
    for (auto it : result) {
        cout << it << ' ';
    }
}

// 사각형과 꼭지점 좌표를 혼동하지 말 것 (왼쪽 아래의 꼭지점이 해당 사격형을 의미함)
// 좌표는 end bound의 x좌표 y좌표에서 1씩 뺀 조건을 명시하면 사각형과 동일
int main() {
    cin >> M >> N >> K;

    for (int i = 0; i < N + 1; i++) {
        vector<int> col = vector<int>(M + 1, 0);
        map.push_back(col);
    }

    for (int i = 0; i < K; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        square sq;
        sq.start_bound = make_pair(x1, y1);
        sq.end_bound = make_pair(x2, y2);
        squares.push_back(sq);
    }

    solve();

    /*
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }
    */

    /*
    for (auto it : squares) {
        cout << it.x1 << it.y1 << it.x2 << it.y2 << '\n';
    }
    */

    return 0;
}
