//
// Created by Amos on 2020/03/12.
//
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        ListNode* current = new ListNode(0);
        ListNode* ret = current;
        while (l1 != nullptr || l2 != nullptr) {

            if (l1 == nullptr) {
                current->next = l2;
                break;
            }

            if (l2 == nullptr) {
                current->next = l1;
                break;
            }

            if (l1->val <= l2->val) {
                current->next = new ListNode(l1->val);
                l1 = l1->next;
            } else {
                current->next = new ListNode(l2->val);
                l2 = l2->next;
            }


            current = current->next;
        }

        return ret->next;
    }
};

void printList(ListNode * start) {
    ListNode* current = start;
    while (current != nullptr) {
        cout << current->val << '\n';
        current = current->next;
    }
    cout << '\n';
}

int main() {
    Solution *s;

    s = new Solution();

    auto *a = new ListNode(1);
    auto *b = new ListNode(2);
    auto *c = new ListNode(4);
    a->next = b;
    b->next = c;

    auto *d = new ListNode(1);
    auto *e = new ListNode(3);
    auto *f = new ListNode(4);
    d->next = e;
    e->next = f;

    printList(s->mergeTwoLists(a, d));

    a = new ListNode(5);
    b = new ListNode(6);
    a->next = b;

    c = new ListNode(7);
    d = new ListNode(8);
    e = new ListNode(9);
    c->next = d;
    d->next = e;

    printList(s->mergeTwoLists(a, c));

    a = new ListNode(3);
    b = new ListNode(5);
    c = new ListNode(10);
    a->next = b;
    b->next = c;

    d = new ListNode(1);
    e = new ListNode(2);
    f = new ListNode(4);
    d->next = e;
    e->next = f;

    printList(s->mergeTwoLists(a, d));

    return 0;
}
