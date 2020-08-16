#include <iostream>
#include <set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
    set<ListNode*> s;

public:
    bool hasCycle(ListNode *head) {

        ListNode *current = head;

        while (current) {

            if (s.find(current) != s.end()) {
                return true;
            }

            s.insert(current);
            current = current->next;
        }

        return false;
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
