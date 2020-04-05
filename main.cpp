#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    cout << "Hello, World!" << '\n';

    vector<string> v = {"im", "it"};
    sort(v.begin(), v.end());

    for (auto elem : v) {
        cout << elem << '\n';
    }

    return 0;
}
