#include <iostream>
#include <vector>

//#define DEBUG

using namespace std;

void insert_sort(vector<int>& number_list)
{
    for(int i {1}; i < number_list.size(); i++)
    {
        for(int j {i - 1}; j >= 0; j--)
        {
#ifdef DEBUG
            cout << " j : " << j << " i : " << i << endl;
            cout << " number_list[j] " << number_list[j] << " number_list[i] " << number_list[i] << endl;
#endif
            if(number_list[j] > number_list[j + 1])
            {
#ifdef DEBUG
                cout << "swap : " << number_list[j] << " " << number_list[j + 1] << endl;
#endif
                int tmp = number_list[j];
                number_list[j] = number_list[j + 1];
                number_list[j + 1] = tmp;
#ifdef DEBUG
                cout << "swap result : " << number_list[j] << " " << number_list[j + 1] << endl;
#endif
            }
        }
    }
}

int main()
{
    int nr_number;
    vector<int> number_list;

    cin >> nr_number;

    for(int i {0}; i < nr_number; i++)
    {
        int tmp;
        cin >> tmp;
        number_list.push_back(tmp);
    }

    insert_sort(number_list);

    for(auto& it : number_list)
        cout << it << " ";
    cout << endl;

    return 0;
}
