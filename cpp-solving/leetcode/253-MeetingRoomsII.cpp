#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    static bool comp(vector<int> &time1, vector<int> &time2) {
        if (time1[0] == time2[0]) {
            return time1[1] > time2[1] ? true : false;
        }

        return time1[0] < time2[0] ? true : false;
    }

public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);

        vector<int> last;
        for (auto &interval : intervals) {
            if (last.empty()) {
                last.push_back(interval[1]);
                continue;
            }

            bool isRequireRoom = false;
            for (int i = 0; i < last.size(); i++) {
                if (last[i] <= interval[0]) {
                    last[i] = interval[1];
                    isRequireRoom = true;
                    break;
                }
            }

            if (!isRequireRoom) {
                last.push_back(interval[1]);
            }
        }

        return last.size();
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
