#include <iostream>

using namespace std;

int main()
{
    int nr_sample;
    cin >> nr_sample;

    for(int i {0}; i < nr_sample; i++)
    {
        unsigned int input_number;
        unsigned int output_number;
        cin >> input_number;

        char *ptr_number = (char *)&input_number;
        char *ptr_out = (char *)&output_number;

        for(int j {sizeof(int)/sizeof(char) - 1}, k {0}; j >= 0; j--)
        {
            ptr_out[j] = ptr_number[k];
            k++;
        }

        cout << output_number << endl;
    }

    return 0;
}
