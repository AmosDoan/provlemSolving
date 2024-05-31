#include <iostream>
#include <list>

#include <cstring>

using namespace std;

template <typename T>
class Stack 
{
    public :
        typedef typename list<T>::iterator iterator;

        Stack() : lifo_ {true}
        {
            stack_list_.clear();
        };

        ~Stack()
        {
        };

        void setDirect(bool lifo)
        {
            this->lifo_ = lifo;
        }

        bool pop(T* data)
        {
            if(stack_list_.empty())
            {
                return false;
            }

            if(lifo_)
            {
                cout << "pop! from back" << endl;
                memcpy(data, &stack_list_.back(), sizeof(T));
                stack_list_.pop_back();
                return true;
            }
            else
            {
                memcpy(data, &stack_list_.front(), sizeof(T));
                stack_list_.pop_front();
                return true;
            }

            return false;
        }

        void push(T data)
        {
            stack_list_.push_back(data);
        }

        int getCount() const 
        {
            return stack_list_.size();
        }

        iterator begin()
        {
            return stack_list_.begin();
        }

        iterator end()
        {
            return stack_list_.end();
        }
#if 0
        typename list<T>::iterator begin()
        {
            return stack_list_.begin();
        }

        typename list<T>::iterator end()
        {
            return stack_list_.end();
        }
#endif

    private :
        list<T> stack_list_;
        bool lifo_; // True라면 LIFO Flase라면 FIFO
};

int main(int argc, char **argv)
{
    Stack<int> int_stack;
    int ret;

    int_stack.push(2);
    int_stack.push(3);
    int_stack.push(4);
    int_stack.push(5);

    cout << "Size of Element in Stack : " << int_stack.getCount()
    << endl;

    for(Stack<int>::iterator it = int_stack.begin(); 
       it != int_stack.end(); ++it)
        cout << "Traverse Stack : " << *it << endl;

    while(int_stack.pop(&ret))
    {
        cout << "Pop Element : " << ret << endl;
    }

    cout << "End!" << endl;

    return 0;
}
