//
// Created by Amos on 2019/12/27.
//
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> buf;
vector<int> temp;
long long nr_swap = 0;

void mergeSort(int first, int second, int size) {
    int first_current = first;
    int second_current = second;
    int insert = first;
    int end = first + size;

    while (first_current < second && second_current < end) {
        if (buf[first_current] < buf[second_current]) {
            temp[insert] = buf[first_current];
            first_current++;
        } else {
            if (buf[first_current] != buf[second_current]) {
                nr_swap += second_current - insert;
            }
            temp[insert] = buf[second_current];
            second_current++;
        }
        insert++;
    }

    if (first_current >= second) {
        for (int i = second_current; i < end; i++) {
            temp[insert] = buf[i];
            insert++;
        }
    } else {
        for (int i = first_current; i < second; i++) {
            temp[insert] = buf[i];
            insert++;
        }
    }

    for (int i = first; i < end; i++) {
        buf[i] = temp[i];
    }
}

void solve(int start, int end) {
    if (start < end) {
        int middle = (end + start) / 2;
        solve(start, middle);
        solve(middle + 1, end);
        mergeSort(start, middle + 1, end - start + 1);
    }

}

int main() {
    cin >> N;

    buf.resize(N);
    temp.resize(N);

    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        buf[i] = a;
    }

    solve(0, N - 1);

    /*
    for (int i = 0; i < N; i++) {
        cout << buf[i] << ' ';
    }
    cout << '\n';
     */

    cout << nr_swap << '\n';
    return 0;
}
