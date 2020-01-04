//
// Created by Amos on 2020/01/01.
//

/**
 *
4 6
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
set<pair<int, int>> visit;
set<pair<int, int>> virus;

int findArea(vector<vector<int>> &tempMap, int start_x, int start_y, int area) {
    if (visit.find(make_pair(start_x, start_y)) != visit.end()) {
        return area;
    }

    visit.insert(make_pair(start_x, start_y));

    if (tempMap[start_x][start_y] != 0) {
        return area;
    }

    if (start_x > 0 && visit.find(make_pair(start_x - 1, start_y)) == visit.end()) {
        area = findArea(tempMap, start_x - 1, start_y, area);
    }

    if (start_x + 1 < H && visit.find(make_pair(start_x + 1, start_y)) == visit.end()) {
        area = findArea(tempMap, start_x + 1, start_y, area);
    }

    if (start_y > 0 && visit.find(make_pair(start_x, start_y - 1)) == visit.end()) {
        area = findArea(tempMap, start_x, start_y - 1, area);
    }

    if (start_y + 1 < W && visit.find(make_pair(start_x, start_y + 1)) == visit.end()) {
        area = findArea(tempMap, start_x, start_y + 1, area);
    }

    return area + 1;
}

void growVirus(vector<vector<int>> &tempMap, int start_virus_x, int start_virus_y) {
    if (tempMap[start_virus_x][start_virus_y] == 1) {
        return;
    }

    map[start_virus_x][start_virus_y] = 2;

    if (start_virus_x > 0 && map[start_virus_x - 1][start_virus_y] != 2) {
        growVirus(tempMap, start_virus_x - 1, start_virus_y);
    }

    if (start_virus_x + 1 < H && map[start_virus_x + 1][start_virus_y] != 2) {
        growVirus(tempMap, start_virus_x + 1, start_virus_y);
    }

    if (start_virus_y > 0 && map[start_virus_x ][start_virus_y - 1] != 2) {
        growVirus(tempMap, start_virus_x, start_virus_y - 1);
    }

    if (start_virus_y + 1 < W && map[start_virus_x ][start_virus_y + 1] != 2) {
        growVirus(tempMap, start_virus_x, start_virus_y + 1);
    }
}

int setupWall(int x, int y, int wall) {

    if (map[x][y] != 0) {
        return 0;
    }

    map[x][y] = 1;

    if (wall == 0) {
        vector<vector<int>> tempMap = map;
        for (auto v : virus) {
            growVirus(tempMap, v.first, v.second);
        }
        //넓이 구하기
        return findArea(tempMap, )
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            setupWall(i, j, wall - 1);
        }
    }

    map[x][y] = 0;

}

/*
int find() {
    int maxSafety = 0;
    // 바이러스 확산하면서 벽설치??
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            // Virus 확산
            growVirus(0, 0);
            // 안전 영역 너비 구하기
            int area = findArea(0, 0, 0);
            if (area > maxSafety) {
                maxSafety = area;
            }
        }
    }

    return maxSafety;
}
*/

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> H >> W;

    for (int i = 0; i < H; i++) {
        vector<int> v;
        for (int j = 0; j < W; j++) {
            int node;
            cin >> node;
            v.push_back(node);

            if (node == 2) {
                virus.insert(make_pair(i, j));
            }
        }
        map.push_back(v);
    }


    for (auto v : virus) {
        growVirus(map, v.first, v.second);
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }

    //cout << find();

    return 0;
}
