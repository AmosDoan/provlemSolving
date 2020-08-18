#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string S) {
        unordered_map<char, int> lastPosition;
        for (int i = 0; i < S.size(); i++) {
            lastPosition[S[i]] = i;
        }

        int start = 0;
        int end = 0;
        vector<int> result;
        for (int i = 0; i < S.size(); i++) {
            char current = S[i];
            int last = lastPosition[current];

            if (last > end) {
                end = last;
            }

            if (i == end) {
                result.push_back(end + 1 - start);
                end = i + 1;
                start = i + 1;
            }

        }

        return result;
    }
};

int main() {
    Solution *s;

    s = new Solution();
    vector<int> ret = s->partitionLabels("ababcbacadefegdehijhklij");
    delete s;

    for (auto &elem : ret) {
        cout << elem << ' ';
    }
    cout << '\n';
}

static const auto _ = []() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();
