//
// Created by Amos on 2020/01/01.
//

#include <vector>
#include <iostream>

using namespace std;

// X, Y 좌표의 경우 Array의 행렬과 반대로 찍어야
void printMap(vector<vector<int>> &map, int M, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << map[j][i] << ' ';
        }
        cout << '\n';
    }
}

// X,Y map과 관련된 문제는 네 방향을 잘 살펴보자
void detect(vector<vector<int>> &map, int start_x, int start_y, int X, int Y) {
    if (map[start_x][start_y] == 0) {
        return;
    }

    map[start_x][start_y] = -1;

    if (start_x + 1 != X && map[start_x + 1][start_y] != -1) {
        detect(map, start_x + 1, start_y, X, Y);
    }

    if (start_y + 1 != Y && map[start_x][start_y + 1] != -1) {
        detect(map, start_x, start_y + 1, X, Y);
    }

    if (start_x != 0 && map[start_x - 1][start_y] != -1) {
        detect(map, start_x - 1, start_y, X, Y);
    }

    if (start_y != 0 && map[start_x][start_y - 1] != -1) {
        detect(map, start_x, start_y - 1, X, Y);
    }
}

int traverse(vector<vector<int>> &map, int X, int Y) {
    int number_of_group = 0;

    for (int i = 0; i < Y; i++) {
        for (int j = 0; j < X; j++) {
            if (map[j][i] == 1) {
                detect(map, j, i, X, Y);
                //printMap(map, X, Y);
                number_of_group++;
            }
        }
    }

    return number_of_group;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int M, N, K;
        vector<vector<int>> map;
        cin >> M >> N >> K;

        for (int i = 0; i < M; i++) {
            vector<int> row(N, 0);
            map.push_back(row);
        }

        for (int i = 0; i < K; i++) {
            int x, y;
            cin >> x >> y;
            map[x][y] = 1;
        }

        cout << traverse(map, M, N) << '\n';
    }

    return 0;
}