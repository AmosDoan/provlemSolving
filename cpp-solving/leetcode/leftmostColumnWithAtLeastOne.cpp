//
// Created by Amos on 2020/04/21.
//
#include <iostream>
#include <vector>

using namespace std;

class BinaryMatrix {
public:
    BinaryMatrix(vector<vector<int>> v) {
        this->v = v;
    }

    int get(int x, int y) {
        return v[x][y];
    }

    // n * m -> y * x
    vector<int> dimensions() {
        int y_size = v.size();
        int x_size = v[0].size();
        return {y_size, x_size};
    }

private:
    vector<vector<int>> v;
};

// 2. (Optimal Approach) Imagine there is a pointer p(x, y) starting from top right corner. p can only move left or down.
// If the value at p is 0, move down. If the value at p is 1, move left. Try to figure out the correctness and time complexity of this algorithm.
class Solution {
private:
    int findLeftMost(int start, int end, BinaryMatrix &binaryMatrix, int currentRow, int currentOne) {
        if (start > end) {
            return currentOne;
        }

        int middle = (start + end) / 2;

        int current = binaryMatrix.get(currentRow, middle);

        if (current == 1) {
            currentOne = middle;
            return findLeftMost(start, middle - 1, binaryMatrix, currentRow, currentOne);
        } else {
            return findLeftMost(middle + 1, end, binaryMatrix, currentRow, currentOne);
        }
    }

public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> dimension = binaryMatrix.dimensions();

        int row = dimension[0];
        int col = dimension[1];

        int index = col;
        for (int i = 0; i < row; i++) {
            int temp = findLeftMost(0, col - 1, binaryMatrix, i, -1);
            if (temp != -1 && temp < index) {
                index = temp;
            }
        }

        return index == col ? -1 : index;
    }
};


int main() {
    Solution *s;
    vector<vector<int>> v;
    BinaryMatrix *binaryMatrix;

    v = {{0, 0}, {1, 1}};
    binaryMatrix = new BinaryMatrix(v);
    s = new Solution();
    cout << s->leftMostColumnWithOne(*binaryMatrix) << '\n';
    delete s;

    v = {{0, 0}, {0, 0}};
    binaryMatrix = new BinaryMatrix(v);
    s = new Solution();
    cout << s->leftMostColumnWithOne(*binaryMatrix) << '\n';
    delete s;

    v = {{0, 0}, {0, 1}};
    binaryMatrix = new BinaryMatrix(v);
    s = new Solution();
    cout << s->leftMostColumnWithOne(*binaryMatrix) << '\n';
    delete s;

    v = {{0, 0, 0, 1}, {0, 0, 1, 1}, {0, 1, 1, 1}};
    binaryMatrix = new BinaryMatrix(v);
    s = new Solution();
    cout << s->leftMostColumnWithOne(*binaryMatrix) << '\n';
    delete s;

    v = {{0, 0, 0, 1}, {0, 0, 0, 1}, {0, 0, 0, 0}};
    binaryMatrix = new BinaryMatrix(v);
    s = new Solution();
    cout << s->leftMostColumnWithOne(*binaryMatrix) << '\n';
    delete s;

    return 0;
}