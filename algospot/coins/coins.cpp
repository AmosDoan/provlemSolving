#include <iostream>
#include <vector>
#include <algorithm>

#define DEBUG

using namespace std;

int dp_coin(vector<int>& coins, int total)
{
    vector<vector<unsigned int>> data;
    int nr_coins, nr_data, min_coin;

    nr_coins = coins.size();
    min_coin = coins[0];
    nr_data = total / min_coin;

    data.clear();
    data.resize(nr_coins, vector<unsigned int>(nr_data + 1, 0));

    // Minimum Coin
    for(int i {0}; i < nr_data + 1; i++)
        data[0][i] = 1;

    // Coins Calculate
    for(int i {1}; i < nr_coins; i++)
    {
        data[i][0] = 1;
        for(int j {1}; j < nr_data + 1; j++)
        {
            int price = j * min_coin;
            int cur_coin = coins[i];
            int tmp;

            for(tmp = price - cur_coin; 
                tmp >= 0; tmp = tmp - cur_coin)
            {
                if(!(tmp % min_coin))
                {
#ifdef DEBUG
                    cout << "[Debug] " 
                        << "price : " << price
                        << " cur_coin : " << cur_coin 
                        << " tmp :" << tmp <<
                        " min_coin : " << min_coin << endl;
#endif
                    int idx = tmp / min_coin;
                    data[i][j] += data[i - 1][idx];
                    if(data[i][j] > 1000000007)
                        data[i][j] %= 1000000007;
                }
            }

#ifdef DEBUG
            cout << "1. data[" << i - 1 << "][" << j << "] : "
                << data[i - 1][j] << endl;
            cout << "1. data[" << i << "][" << j << "] : "
                << data[i][j] << endl;
#endif
            data[i][j] += data[i - 1][j];
#ifdef DEBUG
            cout << "2. data[" << i - 1 << "][" << j << "] : "
                << data[i - 1][j] << endl;
            cout << "2. data[" << i << "][" << j << "] : "
                << data[i][j] << endl;
#endif
        }
    }

    if(data[nr_coins - 1][nr_data] > 1000000007)
        return (data[nr_coins - 1][nr_data] % 1000000007);
    else
        return data[nr_coins - 1][nr_data];
}

int main()
{
    int nr_sample;
    vector<int> coins;

    cin >> nr_sample;

    for(int i {0}; i < nr_sample; i++)
    {
        int nr_coins, total;
        cin >> total >> nr_coins;

        coins.clear();

        for(int j {0}; j < nr_coins; j++)
        {
            int tmp;
            cin >> tmp;
            coins.push_back(tmp);
        }

        sort(coins.begin(), coins.end());
        cout << dp_coin(coins, total) << endl;
    }

    return 0;
}
