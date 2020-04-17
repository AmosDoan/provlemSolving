//
// Created by Amos on 2020/04/17.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void dfs(int current_row, int current_col, vector<vector<char>>& grid) {

        visit[current_row][current_col] = 1;

        for (int i = 0; i < 4; i++) {
            int next_row = current_row + d_row[i];
            int next_col = current_col + d_col[i];

            if (next_row >= size_of_row || next_row < 0) {
                continue;
            }

            if (next_col >= size_of_col || next_col < 0) {
                continue;
            }

            if (grid[next_row][next_col] == '1' && visit[next_row][next_col] == 0) {
                dfs(next_row, next_col, grid);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        size_of_row = grid.size();
        if (size_of_row == 0) {
            return 0;
        }

        size_of_col = grid[0].size();
        if (size_of_col == 0) {
            return 0;
        }

        visit.resize(size_of_row, vector<int>(size_of_col, 0));

        int number_of_islands = 0;
        for (int i = 0; i < size_of_row; i++) {
            for (int j = 0; j < size_of_col; j++) {
                if (visit[i][j] == 0 && grid[i][j] == '1') {
                    number_of_islands++;
                    dfs(i, j, grid);
                }
            }
        }

        return number_of_islands;
    }

private:
    vector<vector<int>> visit;
    int d_row[4] = {-1, 1, 0, 0};
    int d_col[4] = {0, 0, -1, 1};
    int size_of_row;
    int size_of_col;
};

int main() {
    Solution *s;
    vector<vector<char>> map;

    s = new Solution();
    map = {{'1', '1', '1', '1', '0'}, {'1', '1', '0', '1', '0'}, {'1', '1', '0', '0', '0'}, {'0', '0', '0', '0', '0'}};
    cout << s->numIslands(map) << '\n';
    delete s;

    s = new Solution();
    map = {{'1', '1', '0', '0', '0'}, {'1', '1', '0', '0', '0'}, {'0', '0', '1', '0', '0'}, {'0', '0', '0', '1', '1'}};
    cout << s->numIslands(map) << '\n';
    delete s;

    return 0;
}

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();