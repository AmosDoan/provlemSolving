//
// Created by Amos on 2020/04/15.
//
#include <iostream>
#include <vector>

using namespace std;

int N, S;
vector<int> numbers;

int solve() {
    vector<int> sum;
    sum.push_back(numbers[0]);

   for (int i = 1; i < numbers.size(); i++) {
       int temp_sum = numbers[i] + sum[i - 1];
       sum.push_back(temp_sum);
   }

   /*
   for (auto s : sum) {
       cout << s << ' ';
   }
   cout << '\n';
   */

   int ret = 0;
   for (int i = 0; i < sum.size(); i++) {
       if (sum[i] == S) {
           ret++;
       }

       for (int j = i + 1; j < sum.size(); j++) {
           int partial_sum = sum[j] - sum[i];
           if (partial_sum == S) {
               ret++;
           }
       }
   }
   return ret;
}

int main() {
    cin >> N >> S;

    for (int i = 0; i < N; i++) {
        int c = 0;
        cin >> c;
        numbers.push_back(c);
    }

    cout << solve() << '\n';

    return 0;
}
