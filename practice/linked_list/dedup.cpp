//
// Created by Amos on 2020/04/12.
//
#include <iostream>

using namespace std;

struct Node {
    int val;
    Node *next;
    Node(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    void *dedup(Node *head) {
        uniqueness = 0;

        Node *current = head;
        uniqueness |= (1 << current->val);

        for (Node *current = head; current->next != nullptr; current = current->next) {
            int target_val = current->next->val;

            if (uniqueness & (1 << target_val)) {
                Node *target = current->next;
                current->next = target->next;
                delete target;
            } else {
                uniqueness |= (1 << target_val);
            }
        }
    }
private:
    unsigned int uniqueness;
};

void traverseList(Node *head) {
    for (Node *current = head; current != nullptr; current = current->next) {
            cout << current->val << '\n';
    }
}

int main() {
    auto *a = new Node(1);
    auto *b = new Node(2);
    auto *c = new Node(1);
    auto *d = new Node(4);
    a->next = b;
    b->next = c;
    c->next = d;

    Solution *s = new Solution();
    s->dedup(a);
    delete s;

    traverseList(a);
}
