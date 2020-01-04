//
// Created by Amos on 2020/01/01.
//

/**
 *
0 0 0 0 0 0
1 0 0 0 0 2
1 1 1 0 0 2
0 0 0 0 0 2

다음과 같이 9개가 정답

0 0 0 0 1 0
1 0 0 1 0 2
1 1 1 0 0 2
0 0 0 1 0 2
*/
#include <iostream>
#include <vector>
#include <set>
#include <utility>

using namespace std;

int W, H;
vector<vector<int>> map;
vector<vector<int>> virus;
set<pair<int, int>> visit;

int findArea(int start_x, int start_y, int area) {
    if (visit.find(make_pair(start_x, start_y)) != visit.end()) {
        return area;
    }

    visit.insert(make_pair(start_x, start_y));

    if (map[start_x][start_y] != 0) {
        return area;
    }

    visit.insert(make_pair(start_x, start_y));

    if (start_x > 0 && visit.find(make_pair(start_x - 1, start_y)) == visit.end()) {
        area = findArea(start_x - 1, start_y, area);
    }

    if (start_x + 1 < W && visit.find(make_pair(start_x + 1, start_y)) == visit.end()) {
        area = findArea(start_x + 1, start_y, area);
    }

    if (start_y > 0 && visit.find(make_pair(start_x, start_y - 1)) == visit.end()) {
        area = findArea(start_x, start_y - 1, area);
    }

    if (start_y + 1 < H && visit.find(make_pair(start_x, start_y + 1)) == visit.end()) {
        area = findArea(start_x, start_y + 1, area);
    }

    return area + 1;
}

void find() {
    // 바이러스 확산하면서 벽설치??
    /*
    for (int i = 0; i < W; i++) {
        for (int j = 0; j < H; j++) {
            if (map[i][j] == 2 && visit.find(make_pair(i, j)) == visit.end()) {
                // 첫 방문 하는 바이러스

            }

        }
    }
    */

    // 안전 영역 너비 구하기
    findArea(0, 0, 0);
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> W >> H;

    for (int i = 0; i < H; i++) {
        vector<int> v;
        vector<int> virus_info(W, 0);
        for (int j = 0; j < W; j++) {
            int node;
            cin >> node;
            v.push_back(node);
        }
        map.push_back(v);
        virus.push_back(virus_info);
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }

    cout << findArea(0, 0, 0);

    return 0;
}
