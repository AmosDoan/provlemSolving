#include <iostream>
#include <vector>

#include <string.h>

using namespace std;

template <typename T>
class VectorStack
{
    public :
        typedef typename vector<T>::iterator iterator;

        VectorStack()
        {
        };

        ~VectorStack()
        {
        };

        void push(T data)
        {
            data_.push_back(data);
        }

        bool pop(T *data)
        {
            if(data_.empty())
                return false;

            memcpy(data, data_.back(), sizeof(T));
            data_.pop_back();
        }

        iterator begin()
        {
            return data_.begin();
        }

        iterator end()
        {
            return data_.end();
        }

        int getSize() const
        {
            return data_.size();
        }

    private :
        vector<T> data_;
        int size_;
};

int main(int argc, char **argv)
{
    VectorStack<int> my_vector;
    my_vector.push(10);
    my_vector.push(20);
    my_vector.push(30);
    my_vector.push(40);
    my_vector.push(50);

    for(VectorStack<int>::iterator it = my_vector.begin();
        it != my_vector.end(); ++it)
        cout << *it << endl;

    cout << "Stack Size : " << my_vector.getSize() << endl;

    

}
