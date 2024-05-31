#include <iostream>
#include <vector>

using namespace std;

int merge(vector<int>& number, 
          vector<int>& res, 
          int left, int mid, int right)
{
    int swap {0};
    int idx_left = left;
    int idx_right = mid + 1;
    int idx_sort = left;

    while(idx_left <= mid && idx_right <= right)
    {
        if(number[idx_left] < number[idx_right])
            res[idx_sort++] = number[idx_left++];
        else
        {
            res[idx_sort++] = number[idx_right++];
            swap += (mid + 1 - idx_left);
        }
    }

    while(idx_left <= mid)
        res[idx_sort++] = number[idx_left++];

    while(idx_right <= right)
        res[idx_sort++] = number[idx_right++];

    for(int i {0}; i < idx_sort; i++)
        number[i] = res[i];

    return swap;
}

int merge_sort(vector<int>& number,
               vector<int>& res,
               int left, int right)
{
    int count {0};
    int mid = (left + right) / 2;

    if(number.size() < 2)
        return 0;

    if(left < right)
    {
        count = merge_sort(number, res, left, mid);
        count += merge_sort(number, res, mid + 1, right);
        count += merge(number, res, left, mid, right);
    }

    return count;
}

int main() {
    int n;
    vector<int> number;
    vector<int> sort_result;

    cin >> n;

    sort_result.clear();
    sort_result.resize(n, 0);

    for(int i {0}; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        number.push_back(tmp);
    }

    cout << merge_sort(number, sort_result, 0, n - 1) << endl;

#ifdef DEBUG 
    cout << endl;

    for(auto& it : sort_result)
        cout << "Res : " << it << endl;
#endif

    return 0;
}
