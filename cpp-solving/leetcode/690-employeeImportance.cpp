#include <iostream>
#include <vector>

using namespace std;

// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        map<int, Employee*> m;
        queue<Employee*> q;

        for (auto& employee : employees) {
            m[employee->id] = employee;
        }

        int ret = 0;
        q.push(m[id]);
        while (!q.empty()) {
            Employee* current = q.front();
            q.pop();

            ret += current->importance;

            for (auto& sub : current->subordinates) {
                q.push(m[sub]);
            }
        }

        return ret;
    }
};

int main() {
    Solution *s;

    s = new Solution();


    delete s;
}

static const auto _ = []() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();
