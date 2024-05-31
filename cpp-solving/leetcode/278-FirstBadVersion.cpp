#include <iostream>
#include <vector>

using namespace std;

vector<bool > versions;

bool isBadVersion(int version) {
    return !versions[version];
}

class Solution {
public:
    int firstBadVersion(int n) {
        int ret = 0;

        int start = 1, end = n;
        while (true) {
            if (start > end) {
                break;
            }

            unsigned long mid = (start + end) / 2;
            if (isBadVersion(mid)) {
                ret = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return ret;
    }
};

int main() {
    Solution *s;

    s = new Solution();
    versions = {/* index 0 is unused value */true, true, true, true, false, false, false};
    cout << s->firstBadVersion(6) << '\n';
    delete s;

    s = new Solution();
    versions = {/* index 0 is unused value */true, true, true, true, false, false};
    cout << s->firstBadVersion(5) << '\n';
    delete s;
}

static const auto _ = []() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();
