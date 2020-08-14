#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* current = new ListNode(0, head);
        head = current;

        while (current->next) {
            ListNode* next = current->next;
            int next_val = next->val;

            if (next_val == val) {
                current->next = next->next;
                continue;
            }

            if (current->next == nullptr) {
                break;
            }
            current = current->next;
        }

        return head->next;
    }
};

int main() {
    Solution *s;
    ListNode *a = new ListNode(6);
    ListNode *b = new ListNode(5, a);
    ListNode *c = new ListNode(4, b);
    ListNode *d = new ListNode(3, c);
    ListNode *e = new ListNode(2, d);
    ListNode *f = new ListNode(1, e);

    s = new Solution();
    ListNode * result = s->removeElements(f, 6);
    delete s;

    ListNode *current = result;
    while (current) {
        cout << current->val << ' ';
        current = current->next;
    }
    cout << '\n';

}

static const auto _ = []() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();
