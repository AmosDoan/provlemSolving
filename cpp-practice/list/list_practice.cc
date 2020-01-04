#include <iostream>
#include <list>

using namespace std;

template <typename T>
class List
{
    public :
        typedef typename list<T>::iterator iterator;

        List()
        {
        }

        ~List()
        {
        }

        void add_list(T data)
        {
            data_.push_back(data);
        }

        void add_position_list(const iterator &it, T data)
        {
            data_.insert(it, data);
        }

        void delete_position_list(const iterator &it)
        {
            data_.erase(it);
        }

        void delete_list(pair<int, int> data)
        {
            data_.remove(data);
        }

        iterator begin()
        {
            return data_.begin();
        }

        iterator end()
        {
            return data_.end();
        }

    private :
        list<T> data_;
};

int main(int argc, char **argv)
{
    List<pair<int, int>> octagon;
    List<pair <int, int>>::iterator position;

    octagon.add_list(make_pair(50, 200));        // A
    octagon.add_list(make_pair(20, 80));         // B
    octagon.add_list(make_pair(75, 10));         // C
    octagon.add_list(make_pair(130, 80));        // D
    octagon.add_list(make_pair(100, 200));       // E

    for(List<pair<int, int>>::iterator it = octagon.begin(); 
       it != octagon.end(); ++it) 
    {
        cout << " (" << (*it).first << "," <<
            (*it).second << ")" << endl;
        if((*it).first == 100 && (*it).second == 200)
            position = it;
    }

    cout << "============= Insertion Start! =================" <<endl;

    octagon.add_position_list(position, make_pair(180, 150));

    for(List<pair<int, int>>::iterator it = octagon.begin();
        it != octagon.end(); ++it)
        cout << " (" << (*it).first << "," <<
            (*it).second << ")" << endl;

    cout << "============= Modifyinh Start! =================" <<endl;
    for(List<pair<int, int>>::iterator it = octagon.begin();
        it != octagon.end(); ++it)
    {
        if((*it).first == 130 && (*it).second == 80)
        {
            (*it).first = 200;
            (*it).second = 100;
        }
        cout << " (" << (*it).first << "," <<
            (*it).second << ")" << endl;
    }
    
    cout << "============= Deletion Start! =================" <<endl;
    octagon.delete_list(make_pair(75, 10));

    for(List<pair<int, int>>::iterator it = octagon.begin();
        it != octagon.end(); ++it)
        cout << " (" << (*it).first << "," <<
            (*it).second << ")" << endl;

    return 0;
}
