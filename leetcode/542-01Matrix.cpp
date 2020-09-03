#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

class Solution {
private:
    int d_row[4] = {1, -1, 0, 0};
    int d_col[4] = {0, 0, 1, -1};
    int row_size;
    int col_size;

    int traverse(int start_row, int start_col, vector<vector<int>>& matrix) {
        queue<pair<pair<int, int>, int>> q;
        set<pair<int, int>> visit;

        q.push({{start_row, start_col}, 0});
        visit.insert({start_row, start_col});

        int ret = 0;
        while (!q.empty()) {
            int current_row = q.front().first.first;
            int current_col = q.front().first.second;
            int current_level = q.front().second;
            q.pop();

            if (matrix[current_row][current_col] == 0) {
                ret = current_level;
                break;
            }

            for (int i = 0; i < 4; i++) {
                int next_row = current_row + d_row[i];
                int next_col = current_col + d_col[i];

                if (next_row >= row_size || next_row < 0 || next_col >= col_size || next_col < 0) {
                    continue;
                }

                if (visit.find({next_row, next_col}) != visit.end()) {
                    continue;
                }

                visit.insert({next_row, next_col});
                q.push({{next_row, next_col}, current_level + 1});
            }
        }

        return ret;
    }

public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        row_size = matrix.size();
        col_size = matrix[0].size();

        vector<vector<int>> result;
        result.resize(row_size, vector<int>(col_size, 0));

        for (int i = 0; i < row_size; i++) {
            for (int j = 0; j < col_size; j++) {
                if (matrix[i][j] == 0) {
                    result[i][j] = 0;
                }


                int distance = traverse(i, j, matrix);
                result[i][j] = distance;
            }
        }

        return result;
    }
};

int main() {
    Solution *s;

    s = new Solution();


    delete s;
}

static const auto _ = []() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();
