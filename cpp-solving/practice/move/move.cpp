#include <iostream>

using namespace std;

class A
{
    public : 
        A();
        //A(A&& a);
        A(const A& a);
        //A& operator=(A&& a);
        A& operator=(const A& a);
        ~A();

    private:
};

A::A()
{
    cout << "constructor !" << endl;
}

A::A(const A& a)
{
    cout << "copy! constructor !" << endl;
}

#if 0
A::A(A&& a)
{
    cout << "move constructor!" << endl;
}
#endif

A& A::operator=(const A& a)
{
    cout << "copy assignment!" << endl;
    return *this;
}

#if 0
A& A::operator=(A&& a)
{
    cout << "move assignment!" << endl;
    return *this;
}
#endif

A::~A()
{
    cout << "Destructor " << endl;
}

A test()
{
    cout << "test start!" << endl;
    A tmp;
    cout << "test end!" << endl;
    return tmp;
}

int main()
{
    A a;
    a = test();

    return 0;
}
