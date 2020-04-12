//
// Created by Amos on 2020/04/12.
//
#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    Solution () {
    }

    void enqueue(int val) {
        queue.push(val);
    }

    int dequeue() {
        while (queue.size() != 1) {
            int number = queue.top();
            queue.pop();
            temp.push(number);
        }

        int ret = queue.top();
        queue.pop();

        while (!temp.empty()) {
            int number = temp.top();
            temp.pop();
            queue.push(number);
        }

        return ret;
    }

private:
    stack<int> queue;
    stack<int> temp;
};


int main() {
    Solution *s = new Solution();

    s->enqueue(2);
    s->enqueue(3);
    s->enqueue(4);
    s->enqueue(5);

    cout << s->dequeue() << '\n';
    cout << s->dequeue() << '\n';
    cout << s->dequeue() << '\n';
    cout << s->dequeue() << '\n';

    return 0;
}
