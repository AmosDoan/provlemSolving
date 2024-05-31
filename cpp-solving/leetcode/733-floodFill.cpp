#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
private:
    int drow[4] = {1, -1, 0, 0};
    int dcol[4] = {0, 0, 1, -1};

    int rowSize;
    int colSize;

    set<pair<int, int>> visit;

    void dfs(vector<vector<int>>& image, int row, int col, int oldColor, int newColor) {
        if (row >= rowSize || col >= colSize || row < 0 || col < 0) {
            return;
        }

        if (image[row][col] != oldColor) {
            return;
        }

        visit.insert({row, col});
        image[row][col] = newColor;

        for (int i = 0; i < 4; i++) {
            int nextRow = row + drow[i];
            int nextCol = col + dcol[i];

            if (nextRow >= rowSize || nextRow < 0) {
                continue;
            }

            if (nextCol >= colSize || nextCol < 0) {
                continue;
            }

            if (image[nextRow][nextCol] != oldColor) {
                continue;
            }

            if (visit.find({nextRow, nextCol}) != visit.end()) {
                continue;
            }

            visit.insert({nextRow, nextCol});
            dfs(image, nextRow, nextCol, oldColor, newColor);
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        rowSize = image.size();
        colSize = image[0].size();

        dfs(image, sr, sc, image[sr][sc], newColor);

        return image;
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
