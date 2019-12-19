//
// Created by Amos on 2019/12/19.
//
#include <cstdio>

int main() {
    char a[100];

    while (scanf("%[^\n]\n", a) == 1) {
        printf("%s\n", a);
    }

    return 0;
}
