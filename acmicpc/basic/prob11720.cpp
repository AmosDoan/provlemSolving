//
// Created by Amos on 2019/12/19.
//
#include <iostream>

using namespace std;

int main() {
    int N;

    cin >> N;

    int sum = 0;
    while(N--) {
        int n;
        scanf("%1d", &n);
        sum += n;
    }
    cout << sum;
    return 0;
}
