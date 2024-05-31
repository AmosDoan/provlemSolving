#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int, vector<int>, greater<int>> heap;

        for (auto& stick : sticks) {
            heap.push(stick);
        }

        int ret = 0;
        while (heap.size() != 1) {
            int stick1 = heap.top();
            heap.pop();

            int stick2 = heap.top();
            heap.pop();

            ret += stick1 + stick2;
            heap.push(stick1 + stick2);
        }

        return ret;
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
