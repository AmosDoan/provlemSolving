//
// Created by Amos on 2020/02/29.
//
#include <iostream>
#include <vector>

using namespace std;

vector<string> date_name = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
vector<int> month_list = {31, 28, 31, 30, 31 ,30, 31, 31, 30, 31, 30, 31};

int main() {
    int month, date;

    cin >> month >> date;

    int month_diff = month - 1;
    int days = 0;

    for (int i = 0; i < month_diff; i++) {
        days += month_list[i];
    }

    days += date - 1;

    cout << date_name[(1 + days) % 7] << '\n';

    return 0;
}
