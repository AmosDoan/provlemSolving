//
// Created by Amos on 2020/04/10.
//
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        min = INT_MAX;
    }

    void push(int x) {
        st.push(x);
        q.push_back(x);

        if (x < min) {
            min = x;
        }
    }

    void pop() {
        int target = st.top();

        for (auto it = q.begin(); it != q.end(); ++it) {
            if (*it == target) {
                q.erase(it);
                break;
            }
        }

        if (q.empty()) {
            min = INT_MAX;
        } else {
            sort(q.begin(), q.end());
            min = *q.begin();
        }

        st.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return min;
    }

private:
    stack<int> st;
    vector<int> q;
    int min;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main() {
    /*
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << minStack.getMin() << '\n';
    minStack.pop();
    cout << minStack.top() << '\n';
    cout << minStack.getMin() << '\n';
    */

    /*
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-1);
    cout << minStack.getMin() << '\n';
    cout << minStack.top() << '\n';
    minStack.pop();
    cout << minStack.getMin() << '\n';
    */

    /*
    MinStack minStack;
    minStack.push(2);
    minStack.push(0);
    minStack.push(3);
    minStack.push(0);
    cout << minStack.getMin() << '\n';
    minStack.pop();
    cout << minStack.getMin() << '\n';
    minStack.pop();
    cout << minStack.getMin() << '\n';
    minStack.pop();
    cout << minStack.getMin() << '\n';
    */
    /*
    MinStack minStack;
    minStack.push(INT_MAX);
    minStack.push(INT_MAX - 1);
    minStack.pop();
    cout << minStack.getMin() << '\n';
     */

    MinStack minStack;
    minStack.push(2147483646);
    minStack.push(2147483646);
    minStack.push(2147483647);
    cout << minStack.top() << '\n';
    minStack.pop();
    cout << minStack.getMin() << '\n';
    minStack.pop();
    cout << minStack.getMin() << '\n';
    minStack.pop();
    minStack.push(2147483647);
    cout << minStack.top() << '\n';
    cout << minStack.getMin() << '\n';

    return 0;
}