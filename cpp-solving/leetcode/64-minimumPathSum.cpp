//
// Created by Amos on 2020/04/18.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int dp(int current_row, int current_col, vector<vector<int>>& grid) {
        if (current_row < 0 || current_row >= size_of_row ||
            current_col < 0 || current_col >= size_of_col) {
            return INT_MAX;
        }

        int& ret = cache[current_row][current_col];
        if (ret != -1) {
            return ret;
        }

        if (current_row == 0 && current_col == 0) {
            return ret = grid[0][0];
        }

        return ret = grid[current_row][current_col] +
                min(dp(current_row - 1, current_col, grid),
                    dp(current_row, current_col - 1, grid));
    }

public:
    int minPathSum(vector<vector<int>>& grid) {
        size_of_row = grid.size();
        if (size_of_row == 0) {
            return 0;
        }

        size_of_col = grid[0].size();
        if (size_of_col == 0) {
            return 0;
        }

        cache.resize(size_of_row, vector<int>(size_of_col, -1));
        return dp(size_of_row - 1, size_of_col - 1, grid);
    }

private:
    vector<vector<int>> cache;
    int size_of_row;
    int size_of_col;
};

int main() {
    Solution *s;
    vector<vector<int>> map;

    s = new Solution();
    map = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    cout << s->minPathSum(map) << '\n';
    delete s;

    return 0;
}

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();