//
// Created by Amos on 2020/04/07.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countElements(vector<int>& arr) {
        int numbers[1001] = { 0 };

        for (auto c : arr) {
            numbers[c]++;
        }

        int ret = 0;
        for (int i = 0; i < 1000; i++) {
            if (numbers[i] != 0) {
                int next = numbers[i + 1];
                if (next != 0) {
                    ret += numbers[i];
                }
            }
        }

        return ret;
    }
};

int main() {
    Solution *s;
    vector<int> v;

    s = new Solution();
    v = {1, 1, 3, 3, 5, 5, 7, 7};
    cout << s->countElements(v) << '\n';
    delete s;

    s = new Solution();
    v = {1, 2, 3};
    cout << s->countElements(v) << '\n';
    delete s;

    s = new Solution();
    v = {1, 3, 2, 3, 5, 0};
    cout << s->countElements(v) << '\n';
    delete s;

    s = new Solution();
    v = {1, 1, 2, 2};
    cout << s->countElements(v) << '\n';
    delete s;


    return 0;
}
