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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        set<ListNode *> s;

        ListNode *current = headA;

        while (current) {
            s.insert(current);
            current = current->next;
        }

        current = headB;

        while (current) {
            if (s.find(current) != s.end()) {
                return current;
            }

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
