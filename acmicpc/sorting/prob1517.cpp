//
// Created by Amos on 2019/12/27.
//
#include <cstdio>
#include <vector>

using namespace std;

/*
 * N의 범위가 50000 (5 X 10^4)까지 이므로
 * 아래와 같이 실제 bubble sorting을 실행하면 O(N^2) => 25 X 10^8 이므로 1초가 넘어버린다.
 * 머지 소트를 이용해야 함
 */
int bubbleSort(vector<int> &v) {
    int res = 0;

    for (int i = v.size() - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (v[j] > v[j + 1]) {
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
                res++;
            }
        }
    }

    return res;
}

int main() {
    int N;
    vector<int> buf;

    scanf("%d\n", &N);

    buf.resize(N);

    for (int i = 0; i < N; i++) {
        int a;
        scanf("%d", &a);
        buf[i] = a;
    }

    printf("%d\n", bubbleSort(buf));

    return 0;
}
