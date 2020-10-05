#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int d_row[4] = {0, 0, 1, -1};
    int d_col[4] = {1, -1, 0, 0};
    vector<vector<int>> visit;
    int row_size;
    int col_size;

    int dfs(int current_row, int current_col, vector<vector<int>>& grid) {
        visit[current_row][current_col] = 1;

        int area = 0;
        for (int i = 0; i < 4; i++) {
            int next_row = current_row + d_row[i];
            int next_col = current_col + d_col[i];

            if (next_row < 0 || next_row >= row_size) {
                continue;
            }

            if (next_col < 0 || next_col >= col_size) {
                continue;
            }

            if (visit[next_row][next_col] == 0 && grid[next_row][next_col] == 1) {
                area += dfs(next_row, next_col, grid);
            }
        }

        return 1 + area;
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        row_size = grid.size();
        col_size = grid[0].size();

        visit.resize(row_size, vector<int>(col_size, 0));

        int ret = 0;

        for (int i = 0; i < row_size; i++) {
            for (int j = 0; j < col_size; j++) {
                if (grid[i][j] == 1 && visit[i][j] == 0) {
                    int temp = dfs(i, j, grid);
                    cout << i << "," << j << " : " << temp << '\n';
                    if (temp > ret) {
                        ret = temp;
                    }
                }
            }
        }

        return ret;
    }
};

int main() {
    Solution *s;
    vector<vector<int>> v = {{1,1,0,1,1},{1,0,0,0,0},{0,0,0,0,1},{1,1,0,1,1}};

    s = new Solution();
    cout << s->maxAreaOfIsland(v) << '\n';
    delete s;
}

static const auto _ = []() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();
