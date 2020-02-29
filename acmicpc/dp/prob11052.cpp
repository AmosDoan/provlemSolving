//
// Created by Amos on 2020/02/29.
//

#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<int>> dp;
vector<int> p;


/**
 * 1차원 풀이법 (중복을 허용하여 선택해 최대값을 만드는 문제인 경우는 뒤에서 부터 접근해 보도록 하자)
 * https://m.blog.naver.com/PostView.nhn?blogId=occidere&logNo=220786663135&proxyReferer=https%3A%2F%2Fwww.google.com%2F
 */
/*
int solve() {

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            d[i] = max(d[i], d,[i - j] + a[j]);
        }
    }
}
*/

int solve() {
    for (int i = 1; i < N + 1; i++) {
        for (int j = 0; j < N + 1; j++) {
            dp[i][j] = dp[i - 1][j];

            if (i <= j) {
                int number_of_current = j / i;
                for (int k = number_of_current; k > 0; k--) {
                    int when_current_using = k * p[i - 1] + dp[i - 1][j - k * i];
                    dp[i][j] = max(dp[i][j], when_current_using);
                }
            }
        }
    }

    /*
    for (int i = 0; i < N + 1; i++) {
        for (int j = 0; j < N + 1; j++) {
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }
    */

    return dp[N][N];
}

int main() {
    cin >> N;

    for(int i = 0; i < N; i++) {
        int cost;
        cin >> cost;
        p.push_back(cost);
    }

    dp.resize(N + 1, vector<int>(N + 1, 0));

    cout << solve() << '\n';

    return 0;
}
