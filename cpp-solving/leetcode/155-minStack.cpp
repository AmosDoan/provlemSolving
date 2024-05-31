//
// Created by Amos on 2020/04/10.
//
#include <iostream>
#include <stack>

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        minimum = INT_MAX;
    }

    void push(int x) {
        if (x < minimum) {
            minimum = x;
        }
        st.push({x, minimum});
    }

    void pop() {
        st.pop();

        if (st.empty()) {
            minimum = INT_MAX;
        } else {
            minimum = st.top().second;
        }
    }

    int top() {
        return st.top().first;
    }

    int getMin() {
        return st.top().second;
    }

private:
    stack<pair<int, int>> st;
    int minimum;
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