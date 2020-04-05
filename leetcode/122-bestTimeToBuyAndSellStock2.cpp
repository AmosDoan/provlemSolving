//
// Created by Amos on 2020/04/05.
//
#include <iostream>
#include <vector>

using namespace std;

/* Top Down (ExcessTime Limit when consecutive zeros TC)
class Solution {
private:
    int solve(int current, vector<int>& prices) {
        if (current <= 0) {
            return 0;
        }

        int &ret = cache[current];
        if (ret != -1) {
            return ret;
        }

        for (int i = 0; i < current; i ++) {
            int latest = prices[current] - prices[i];
            latest += solve(i - 1, prices);

            if (latest > ret) {
                ret = latest;
            }
        }

        ret = max(solve(current - 1, prices), ret);
        return max(ret, 0);
    }

public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) {
            return 0;
        }

        cache.resize(prices.size(), -1);
        cache[0] = 0;
        return solve(prices.size() - 1, prices);
    }

    vector<int> cache;
};
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) {
            return 0;
        }

        cache.resize(prices.size(), -1);
        cache[0] = 0;

        int ret = 0;
        for (int i = 1; i < prices.size(); i++) {
            int current = prices[i];
            int temp_max = 0;

            if (current == 0) {
                cache[i] = cache[i - 1];
                ret = max(temp_max, ret);
                continue;
            }

            for (int j = 0; j < i; j++) {
                int temp = current - prices[j];
                if (j > 0) {
                    temp += cache[j - 1];
                }

                temp = max(temp , 0);
                temp_max = max(temp, temp_max);
                temp_max = max(temp_max, cache[i - 1]);
            }
            cache[i] = temp_max;
            ret = max(temp_max, ret);
        }

        return ret;
    }

    vector<int> cache;
};

int main() {
    Solution *s;
    vector<int> p;

    s = new Solution();
    p = {7, 1, 5, 3, 6, 4};
    cout << s->maxProfit(p) << '\n';
    delete s;

    s = new Solution();
    p = {1, 2, 3, 4, 5};
    cout << s->maxProfit(p) << '\n';
    delete s;

    s = new Solution();
    p = {7, 6, 4, 3, 1};
    cout << s->maxProfit(p) << '\n';
    delete s;

    s = new Solution();
    p = {3, 2, 6, 5, 0, 3};
    cout << s->maxProfit(p) << '\n';
    delete s;

    return 0;
}
