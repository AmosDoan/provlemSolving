#include <iostream>
#include <vector>

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

        if (l1 != nullptr) {
            carry_over = processLeft(&ptr, l1, carry_over);
        } else if (l2 != nullptr) {
            carry_over = processLeft(&ptr, l2, carry_over);
        }

        if (carry_over) {
            ListNode *node = new ListNode(1);
            ptr->next = node;
        }

        return result->next;
    }

private:
    bool processLeft(ListNode **ptr, ListNode *left, bool carry_over) {
        (*ptr)->next = left;
        while (left != nullptr) {
            if (carry_over) {
                left->val++;
            }

            if (left->val >= 10) {
                left->val = left->val % 10;
                carry_over = true;
            } else {
                carry_over = false;
            }

            (*ptr) = left;
            left = left->next;
        }

        return carry_over;
    }
};

void printResult(ListNode *result) {
    while(result != nullptr) {
        cout << result->val << ' ';
        result = result->next;
    }
    cout << '\n';
}

ListNode* createTestCase(vector<int> numbers) {
    ListNode *ptr = new ListNode(0);
    ListNode *result = ptr;
    for (auto number : numbers) {
        ListNode *node = new ListNode(number);
        ptr->next = node;
        ptr = ptr->next;
    }

    return result->next;
}

int main() {
    // Test Case 1.
    ListNode *v1= createTestCase(vector<int>{2, 4, 3});
    ListNode *v2= createTestCase(vector<int>{5, 6, 4});

    Solution sol;
    printResult(sol.addTwoNumbers(v1, v2));

    v1= createTestCase(vector<int>{9, 7, 0, 8});
    v2= createTestCase(vector<int>{1});
    printResult(sol.addTwoNumbers(v1, v2));

    v1= createTestCase(vector<int>{9, 9});
    v2= createTestCase(vector<int>{1});
    printResult(sol.addTwoNumbers(v1, v2));

    return 0;
}