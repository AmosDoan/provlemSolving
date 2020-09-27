#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int traverse(int n) {
        int &ret = cache[n];
        if (ret != -1) {
            return ret;
        }

        ret = (tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3));
        return ret;
    }

    vector<int> cache;

public:
    int tribonacci(int n) {
        cache.resize(n + 10, -1);
        cache[0] = 0;
        cache[1] = 1;
        cache[2] = 1;
        return traverse(n);
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
