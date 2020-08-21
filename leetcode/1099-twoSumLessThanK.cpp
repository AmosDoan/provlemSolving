#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int twoSumLessThanK(vector<int>& A, int K) {
        sort(A.begin(), A.end());

        int left = 0;
        int right = A.size() - 1;

        priority_queue<int, vector<int>> q;
        while (left < right) {
            int s = A[left] + A[right];

            if (s < K) {
                q.push(s);
                left++;
            }

            if (s >= K) {
                right--;
            }
        }

        if (q.empty()) {
            return -1;
        }

        return q.top();
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
