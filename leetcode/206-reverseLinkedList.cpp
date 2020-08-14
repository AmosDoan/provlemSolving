#include <iostream>
#include <vector>
#include <queue>

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
    ListNode* reverseList(ListNode* head) {
        queue<int> q;
        ListNode* current = head;

        while (current) {
            cout << current->val << '\n';
            q.push(current->val);
            current = current->next;
        }

        ListNode* tmp = nullptr;
        ListNode* ret;
        while (!q.empty()) {
            int val = q.front();
            q.pop();

            ret = new ListNode(val, tmp);
            tmp = ret;
        }

        return ret;
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
