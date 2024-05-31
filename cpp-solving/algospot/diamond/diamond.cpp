#include <iostream>
#include <vector>

#define DEBUG

using namespace std;

inline int findMax(int a, int b)
{
    return (a > b) ? a : b;
}


int findDiamondMax(vector<vector<int>>& diamond, int step, int n)
{
    vector<vector<int>> output(step, vector<int>(n + 1, 0));

    output[0][0] = diamond[0][0];

    int mid = (step + 1) / 2;

    for(int i {1}; i < mid; i++)
    {
        for(int j {0}; j < i+1; j++)
        {

            if(j == 0)
                output[i][j] = diamond[i][j]
                            + output[i - 1][j];
            else if(j == i)
                output[i][j] = diamond[i][j]
                            + output[i - 1][j - 1];
            else
                output[i][j] = diamond[i][j]
                    + findMax(output[i - 1][j - 1], 
                              output[i - 1][j]);
        }
    }

    // Last Half
    int max = mid - 1;
    for(int i {mid}; i < step; i++)
    {
        for(int j {0}; j < max ; j++)
        {
            output[i][j] = diamond[i][j]
                + findMax(output[i - 1][j], 
                          output[i - 1][j + 1]);
        }
        max--;
    }

    return output[step - 1][0];
}

int main()
{
    int nr_sample;
    vector<vector<int>> diamond;

    cin >> nr_sample;

    for(int i {0}; i < nr_sample; i++)
    {
        int mid_size;
        int row;
        cin >> mid_size;

        int step = 2 * mid_size - 1;
        diamond.clear();
        diamond.resize(step, vector<int>(mid_size + 1, 0));
        
        for(int j {0}; j < mid_size; j++)
        {
            for(int t {0}; t < j + 1; t++)
            {
                cin >> diamond[j][t];
            }
        }

        row = mid_size;
        for(int j {mid_size - 1}; j > 0; j--)
        {
            for(int t {0}; t < j; t++)
            {
                cin >> diamond[row][t];
            }
            row++;
        }

        cout << findDiamondMax(diamond, step, mid_size);
        cout << endl;
    }

    return 0;
}
