//
// Created by Amos on 2020/04/28.
//
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class FirstUnique {
public:
    FirstUnique(vector<int>& nums) {
        q = nums;
        first_unique = -1;

        for (auto num : q) {
            map[num]++;
        }

        for (int i = 0; i < q.size(); i++) {
            if (map[q[i]] == 1) {
                first_unique = i;
                break;
            }
        }
    }

    int showFirstUnique() {
        if (first_unique == -1) {
            return -1;
        }
        return q[first_unique];
    }

    void add(int value) {
        q.push_back(value);
        map[value]++;

        if (first_unique != -1 && value == q[first_unique]) {
            for (int i = first_unique + 1; i < q.size(); i++) {
                if (map[q[i]] == 1) {
                    first_unique = i;
                    return;
                }
            }
            first_unique = -1;
        } else {
            if (first_unique == -1 && map[value] == 1) {
                first_unique = q.size() - 1;
            }
        }
    }

private:
    vector<int> q;
    unordered_map<int, int> map;
    int first_unique;
};

int main() {
    FirstUnique *s;
    vector<int> v;

    /*
    v = {2, 3, 5};
    s = new FirstUnique(v);
    cout << s->showFirstUnique() << '\n';
    s->add(5);
    cout << s->showFirstUnique() << '\n';
    s->add(2);
    cout << s->showFirstUnique() << '\n';
    s->add(3);
    cout << s->showFirstUnique() << '\n';
    delete s;
    */

    v = {7,7,7,7,7,7};
    s = new FirstUnique(v);
    cout << s->showFirstUnique() << '\n';
    s->add(7);
    s->add(3);
    s->add(3);
    s->add(7);
    s->add(17);
    cout << s->showFirstUnique() << '\n';
}

static const auto _ = []() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();
