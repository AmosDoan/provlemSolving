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

void drawMap(vector<vector<int>> tempMap) {
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cout << tempMap[i][j] << ' ';
        }
        cout << '\n';
    }
}

int findArea(vector<vector<int>> &tempMap) {
    int area = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++){
            if (tempMap[i][j] == 0) {
                area++;
            }
        }
    }
    return area;
}

void growVirus(vector<vector<int>> &tempMap, int start_virus_x, int start_virus_y) {
    if (tempMap[start_virus_x][start_virus_y] == 1) {
        return;
    }

    tempMap[start_virus_x][start_virus_y] = 2;

    if (start_virus_x > 0 && tempMap[start_virus_x - 1][start_virus_y] != 2) {
        growVirus(tempMap, start_virus_x - 1, start_virus_y);
    }

    if (start_virus_x + 1 < H && tempMap[start_virus_x + 1][start_virus_y] != 2) {
        growVirus(tempMap, start_virus_x + 1, start_virus_y);
    }

    if (start_virus_y > 0 && tempMap[start_virus_x ][start_virus_y - 1] != 2) {
        growVirus(tempMap, start_virus_x, start_virus_y - 1);
    }

    if (start_virus_y + 1 < W && tempMap[start_virus_x ][start_virus_y + 1] != 2) {
        growVirus(tempMap, start_virus_x, start_virus_y + 1);
    }
}

int setupWall(int x, int y, int wall) {
    map[x][y] = 1;

    if (wall == 1) {
        vector<vector<int>> tempMap = map;
        for (auto v : virus) {
            growVirus(tempMap, v.first, v.second);
        }
        int result = findArea(tempMap);
        map[x][y] = 0;
        return result;
    }

    int maxArea = 0;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (map[i][j] != 0) {
                continue;
            }
            int area = setupWall(i, j, wall - 1);
            if (area > maxArea) {
                maxArea = area;
            }
        }
    }

    map[x][y] = 0;
    return maxArea;
}

int findMaxArea() {
    int maxArea = 0;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (map[i][j] != 0) {
                continue;
            }
            int area = setupWall(i, j, 3);
            if (area > maxArea) {
                maxArea = area;
            }
        }
    }

    return maxArea;
}

/**
 * Time Complexity : O(H * W * H * W * H * W)
 * H와 W는 최대 8이므로 64^3 => 2 ^ 18 = 1024 X 128 이므로 돌려볼만함
 * @return
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

    cout << findMaxArea();

    return 0;
}
