//
// Created by Amos on 2020/03/29.
//
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode *ret = new ListNode(0);
        ret->next = head;

        ListNode *current = ret;
        while (current->next != nullptr) {
            ListNode *v1 = current->next;
            ListNode *v2 = v1->next;

            if (v2 == nullptr) {
                break;
            }

            v1->next = v2->next;
            v2->next = v1;
            current->next = v2;

            current = v1;
        }

        return ret->next;
    }
};

void printNodes(ListNode *head) {
    for (ListNode *current = head; current != nullptr; current = current->next) {
        cout << current->val << " ";
    }
    cout << '\n';
}

int main() {
    Solution *s;
    ListNode *ret;

    /*
    ListNode a1 = ListNode(1);
    ListNode a2 = ListNode(2);
    ListNode a3 = ListNode(3);
    ListNode a4 = ListNode(4);
    a1.next = &a2;
    a2.next = &a3;
    a3.next = &a4;

    s = new Solution();
    ret = s->swapPairs(&a1);
    printNodes(ret);
    delete s;
    */

    ListNode b1 = ListNode(1);
    ListNode b2 = ListNode(2);
    ListNode b3 = ListNode(3);
    b1.next = &b2;
    b2.next = &b3;

    s = new Solution();
    ret = s->swapPairs(&b1);
    printNodes(ret);
    delete s;

    return 0;
}

