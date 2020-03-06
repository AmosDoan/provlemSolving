//
// Created by Amos on 2020/03/06.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int s = 0;
        int size = height.size();

        for (int i = 0; i < size; i++) {
            int current = height[i];
            bool max_find = false;

            for (int j = 0; j < i; j++) {
                if (!max_find && height[j] >= current) {
                    max_find = true;
                    s = max(s, (i - j) * current);
                }

                if (height[j] < current) {
                    s = max(s, (i - j) * height[j]);
                }
            }
        }

        return s;
    }
};

int main() {
    Solution *s;
    vector<int> list;

    s = new Solution();
    list = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << s->maxArea(list) << '\n';
    delete s;

    s = new Solution();
    list = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    cout << s->maxArea(list) << '\n';
    delete s;

    s = new Solution();
    list = {4, 9};
    cout << s->maxArea(list) << '\n';
    delete s;

    s = new Solution();
    list = {1, 1, 1, 10, 10, 1, 1, 1, 1};
    cout << s->maxArea(list) << '\n';
    delete s;

    s = new Solution();
    list = {1, 2, 4, 3};
    cout << s->maxArea(list) << '\n';
    delete s;

    return 0;
}
