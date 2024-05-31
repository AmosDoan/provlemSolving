#include <iostream>
#include <vector>

using namespace std;

void select_sort(vector<int>& number_list)
{
    for(int i{0}; i < number_list.size(); i++)
    {
        for(int j{i + 1}; j < number_list.size(); j++)
        {
            if(number_list[i] > number_list[j])
            {
                int tmp = number_list[i];
                number_list[i] = number_list[j];
                number_list[j] = tmp;
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

    select_sort(number_list);

    for(auto& it : number_list)
        cout << it << " ";
    cout << endl;

    return 0;
}
