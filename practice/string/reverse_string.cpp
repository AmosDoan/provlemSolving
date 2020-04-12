//
// Created by Amos on 2020/04/12.
//
#include <iostream>

using namespace std;

void reverseString(char *str) {
    char *start = str;
    char *end = str + strlen(str) - 1;

    while (start < end) {
        char buf;

        buf = *start;
        *start = *end;
        *end = buf;

        start++;
        end--;
    }
}

int main() {
    char s[] = "abc";
    reverseString(s);
    cout << s << '\n';

    return 0;
}
