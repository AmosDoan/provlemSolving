//
// Created by Amos on 2020/02/25.
//

#include <iostream>
#include <sstream>

using namespace std;

// https://stackoverflow.com/questions/35506712/string-multiplication-in-c
/*
int main() {
    string s;

    // 반복이 아님..
    s.append("t", 2);
    s.append("t", 20);

    cout << s << '\n';
}
*/

string operator*(const string& str, int times) {
    stringstream stream;

    for (size_t i = 0; i < times; i++) {
        stream << str;
    }
    return stream.str();
}

int main() {
    string s;
    string test1 = "tt";
    string repeated = test1 * 4;

    s.append(repeated);

    cout << s << '\n';
}
