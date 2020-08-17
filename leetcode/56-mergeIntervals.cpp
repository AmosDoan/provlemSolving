#include <iostream>
#include <vector>

using namespace std;

class Solution {
    static bool comp(vector<int> &p1, vector<int> &p2) {
        return p1[0] < p2[0];
    }

public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);

        int current = 0;
        vector<vector<int>> results;
        for (auto &elem : intervals) {
            if (results.empty()) {
                results.push_back(elem);
            } else if ((int) results[current][1] < (int)elem[0]) {
                current++;
                results.push_back(elem);
            } else {
                //merge
                int min_low = (int) elem[0] < (int) results[current][0] ? elem[0] : results[current][0];
                int max_high = (int) elem[1] > (int) results[current][1] ? elem[1] : results[current][1];
                results[current].clear();
                results[current].push_back(min_low);
                results[current].push_back(max_high);
            }
        }

        return results;
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
