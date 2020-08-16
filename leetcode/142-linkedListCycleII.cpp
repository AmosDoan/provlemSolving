#include <iostream>
#include <set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        set<ListNode *> s;
        ListNode* current = head;

        while (current) {

            if (s.find(current) != s.end()) {
                return current;
            }

            s.insert(current);
            current = current->next;
        }

        return nullptr;
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
