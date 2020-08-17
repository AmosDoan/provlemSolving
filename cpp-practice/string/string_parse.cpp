//
// Created by Amos on 2020/08/17.
//
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string str = "abc test test2";

    stringstream ss(str);
    string id;
    getline(ss, id, ' ');

    cout << id << '\n';

    string log;
    getline(ss, log, ' ');
    cout << log << '\n';

    cout << str.substr(id.size() + 1) << '\n';

    return 0;
}
