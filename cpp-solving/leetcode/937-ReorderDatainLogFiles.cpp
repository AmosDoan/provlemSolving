#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    bool static comp(pair<string, string>& s1, pair<string, string>& s2) {
        if (s1.second.compare(s2.second) == 0) {
            return s1.first.compare(s2.first) < 0;
        }

        return s1.second.compare(s2.second) < 0;
    }

public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> result;
        vector<pair<string, string>> letLogs;
        vector<string> digitLogs;

        for (int i = 0; i < logs.size(); i ++) {
            stringstream ss(logs[i]);
            string id;
            getline(ss, id, ' ');

            string log;
            getline(ss, log, ' ');

            if (log[0] >= '0' && log[0] <= '9') {
                digitLogs.push_back(logs[i]);
            } else {
                letLogs.emplace_back(id, logs[i].substr(id.size() + 1));
            }
        }

        sort(letLogs.begin(), letLogs.end(), comp);

        for (auto & log : letLogs) {
            result.push_back(log.first + ' ' + log.second);
        }

        for (auto & log : digitLogs) {
            result.push_back(log);
        }

        return result;
    }
};

int main() {
    Solution *s;

    vector<string> v = {"dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"};

    s = new Solution();
    vector<string> ret = s->reorderLogFiles(v);
    delete s;

    for (auto & elem : ret) {
        cout << elem << '\n';
    }
}

static const auto _ = []() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();
