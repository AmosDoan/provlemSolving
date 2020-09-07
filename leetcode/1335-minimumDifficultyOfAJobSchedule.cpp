#include <iostream>
#include <vector>

using namespace std;

class Solution {
    vector<int> jobDifficulty;
    vector<vector<int>> cache;

private:
    int traverse(int idx, int day) {
        int &ret = cache[idx][day];
        if (ret != -1) {
            return ret;
        }

        if (idx == jobDifficulty.size() && day == 0) {
            return ret = 0;
        }

        if (idx == jobDifficulty.size() || day == 0) {
            return ret = 987654321;
        }

        int max_difficulty = jobDifficulty[idx];
        int temp = INT_MAX;
        for (int i = idx; i < jobDifficulty.size(); i++) {
            if (jobDifficulty[i] > max_difficulty) {
                max_difficulty = jobDifficulty[i];
            }

            temp = min(traverse(i + 1, day - 1) + max_difficulty, temp);
        }

        return ret = temp;
    }

public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        this->jobDifficulty = jobDifficulty;
        cache.resize(jobDifficulty.size() + 1, vector<int>(d + 1, -1));
        return traverse(0, d);
    }
};

int main() {
    Solution *s;
    //vector<int> v{6, 5, 4, 3, 2, 1};
    //vector<int> v{2, 1};
    //vector<int> v{1, 1, 1};
    //vector<int> v{7, 1, 7, 1, 7, 1};
    vector<int> v{11, 111, 22, 222, 33, 333, 44, 444};

    s = new Solution();
    cout << s->minDifficulty(v, 6) << '\n';
    delete s;
}

static const auto _ = []() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();
