#include <iostream>
#include <vector>

using namespace std;

inline void swap(int& a, int& b)
{
    int tmp = a;
    a = b;
    b = a;
}

int bubble_sort(vector<int>& number)
{
    int nr_swap {0};

    for(int i {0}; i < number.size() - 1; i++)
        for(int j {0}; j < number.size() - i - 1; j++)
        {
            if(number[j] > number[j + 1])
            {
                swap(number[j], number[j + 1]);
                nr_swap++;
            }

        }

    return nr_swap;
}
int main() {
    int n;
    vector<int> number;
    cin >> n;

    for(int i {0}; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        number.push_back(tmp);
    }

    cout << bubble_sort(number) << endl;

    return 0;
}
