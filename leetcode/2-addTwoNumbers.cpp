#include <iostream>

using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *result = new ListNode(0);
        ListNode *ptr = result;

        bool carry_over = false;
        while (l1 != nullptr && l2 != nullptr) {
            int val1 = l1->val;
            int val2 = l2->val;
            int result_val = val1 + val2;

            if (carry_over) {
                result_val++;
            }

            if (result_val >= 10) {
                result_val = result_val % 10;
                carry_over = true;
            } else {
                carry_over = false;
            }

            ListNode *node = new ListNode(result_val);
            ptr->next = node;
            ptr = ptr->next;

            l1 = l1->next;
            l2 = l2->next;
        }

        return new ListNode(3);
    }
};

int main() {
    ListNode *v1= new ListNode(2);
    v1->next = new ListNode(4);
    v1->next->next = new ListNode(3);

    ListNode *v2= new ListNode(7);
    v2->next = new ListNode(0);
    v2->next->next = new ListNode(8);

    Solution sol;
    ListNode* result = sol.addTwoNumbers(v1, v2);

    while(result != nullptr) {
        cout << result->val << ' ';
        result = result->next;
    }

    return 0;
}