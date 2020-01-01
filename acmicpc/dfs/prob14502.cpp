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

using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int W, H;

    cin >> W >> H;

    vector<vector<int>> map;
    for (int i = 0; i < H; i++) {
        vector<int> v;
        for (int j = 0; j < W; j++) {
            int node;
            cin >> node;
            v.push_back(node);
        }
        map.push_back(v);
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
