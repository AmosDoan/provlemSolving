//
// Created by Amos on 2020/04/27.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) {
            return 0;
        }

        int row_size = matrix.size();
        int col_size = matrix[0].size();

        cache.resize(row_size, vector<int>(col_size, 0));

        int max_length = 0;
        for (int row = 0; row < row_size; row++) {
            cache[row][0] = matrix[row][0] == '1' ? 1 : 0;
            if (cache[row][0] > max_length) {
                max_length = cache[row][0];
            }
        }

        for (int col = 0; col < col_size; col++) {
            cache[0][col] = matrix[0][col] == '1' ? 1 : 0;
            if (cache[0][col] > max_length) {
                max_length = cache[0][col];
            }
        }

        for (int row = 1; row < row_size; row++) {
            for (int col = 1; col < col_size; col++) {
                int &temp = cache[row][col];
                if (matrix[row][col] == '1') {
                    int c1 = cache[row - 1][col - 1];
                    int c2 = cache[row - 1][col];
                    int c3 = cache[row][col - 1];

                    if (c1 == c2 && c1 == c3) {
                        temp = c1 + 1;
                    } else {
                        int min_length = min(c1, c2);
                        min_length = min(min_length, c3);
                        temp = min_length + 1;
                    }
                } else {
                    temp = 0;
                }

                if (temp > max_length) {
                    max_length = temp;
                }
            }
        }
        return max_length * max_length;
    }

private:
    vector<vector<int>> cache;
};

int main() {
    Solution *s;
    vector<vector<char>> v;

    s = new Solution();
    v = {{'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}};
    cout << s->maximalSquare(v) << '\n';
    delete s;

    s = new Solution();
    v = {{'1'}};
    cout << s->maximalSquare(v) << '\n';
    delete s;
}

static const auto _ = []() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

