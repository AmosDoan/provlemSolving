#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct node
{
    string name;
    int number;

    bool operator<(const struct node& rhs) const
    {
        cout << "======================== " << endl;
        cout << "this->number : " << this->number << endl;
        cout << "rhs->number : " << rhs.number << endl;
        cout << "======================== " << endl;
        return (this->number < rhs.number);
    }
};

int main(int argc, char **argv)
{
    int idx = 1;
    priority_queue<struct node> min_heap{};
    struct node a {"Dohan", 0};
    struct node b {"Jonathan", 1};
    struct node c {"Sundongkkun", 2};
    struct node d {"JungOh", 3};

    min_heap.push(a);
    min_heap.push(b);
    min_heap.push(c);
    min_heap.push(d);

    while(!min_heap.empty())
    {
        struct node tmp;
        tmp = min_heap.top();
        min_heap.pop();

        cout << "Idx : " << idx++ << endl;
        cout << "Name : " << tmp.name << endl;
        cout << "Num : " << tmp.number << endl;
        cout << "=================" << endl << endl;
    }

    return 0;
}
