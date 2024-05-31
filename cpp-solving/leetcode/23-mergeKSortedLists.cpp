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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        map<int, int> m;

        for (auto &list : lists) {
            ListNode* curr = list;

            while (curr) {
                m[curr->val]++;
                curr = curr->next;
            }
        }

        ListNode *result = new ListNode(0);
        ListNode *curr = result;
        for (auto &elem: m) {
            cout << elem.first << " : " << elem.second << '\n';
            for (int i = 0; i < elem.second; i++) {
                ListNode *tmp = new ListNode(elem.first);
                curr->next = tmp;
                curr = curr->next;
            }
        }

        return result->next;
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
