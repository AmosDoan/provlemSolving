//
// Created by Amos on 2020/04/08.
//
#include <iostream>
#include <unordered_map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        unordered_map<int, ListNode*> m;

        int i = 1;
        for (ListNode* current = head; current != nullptr; current = current->next) {
            m[i++] = current;
        }

        return m[(i + 1) / 2];
    }
};

int main() {
    Solution *s;

    auto *a = new ListNode(1);
    auto *b = new ListNode(2);
    auto *c = new ListNode(3);
    auto *d = new ListNode(4);
    auto *e = new ListNode(5);
    auto *f = new ListNode(6);

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = f;

    auto t = s->middleNode(a);
    cout << t->val << '\n';

    return 0;
}