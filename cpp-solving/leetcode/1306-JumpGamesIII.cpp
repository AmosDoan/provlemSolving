#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<int> visit;

    bool traverse(int current_idx, vector<int>& arr) {
        if (current_idx < 0 || current_idx >= arr.size()) {
            return false;
        }

        if (visit[current_idx] == 1) {
            return false;
        }

        if (arr[current_idx] == 0) {
            return true;
        }

        visit[current_idx] = 1;
        return traverse(current_idx + arr[current_idx], arr) || traverse(current_idx - arr[current_idx], arr);

    }
public:
    bool canReach(vector<int>& arr, int start) {
        visit.resize(arr.size(), 0);
        return traverse(start, arr);
    }
};

int main() {
    Solution *s;
    vector<int> v = {4,2,3,0,3,1,2};

    s = new Solution();
    cout << s->canReach(v, 5) << '\n';
    delete s;
}

static const auto _ = []() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();
