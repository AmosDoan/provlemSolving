//
// Created by Amos on 2019/12/24.
//

#include <cstdio>

int findYear(int target_e, int target_s, int target_m) {
    int e = 1, s = 1, m = 1;
    int year = 1;
    while(true) {
        if (e == target_e && s == target_s && m == target_m) {
            break;
        }

        e++;
        s++;
        m++;

        if (e == 16) {
            e = 1;
        }

        if (s == 29) {
            s = 1;
        }

        if (m == 20) {
            m = 1;
        }
        year++;
    }
    return year;
}

int main() {
    int E, S, M;

    scanf("%d %d %d", &E, &S, &M);
    printf("%d\n", findYear(E, S, M));
    return 0;
}