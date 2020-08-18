#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {

    struct Point {
        int x;
        int y;
        float distance;
        Point(int x, int y, int distance) : x(x), y(y), distance(distance) {}
    };

    struct comparator {
        // min heap은 root p1과 새로들어온 p2가 swap 되어야할 조건을 의미
        bool operator() (Point& p1, Point& p2) {
            return p1.distance > p2.distance;
        }
    };

public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<Point, vector<Point>, comparator> q;

        for (auto &elem : points) {
            Point p(elem[0], elem[1], elem[0] * elem[0] + elem[1] * elem[1]);
            q.push(p);
        }

        vector<vector<int>> result;
        for (int i = 0; i < K; i++) {
            Point p = q.top();
            q.pop();

            vector<int> point;
            point.push_back(p.x);
            point.push_back(p.y);

            result.push_back(point);
        }

        return result;
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
