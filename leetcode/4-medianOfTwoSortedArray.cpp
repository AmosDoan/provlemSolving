//
// Created by Amos on 2020/03/31.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    double solve(vector<int> v, int start, int end) {
        if (start < end) {
            int middle = (start + end) / 2;
            double left = solve(v, start, middle);
            double right = solve(v, middle + 1, end);
            return (left + right) / 2.0F;
        }
        return (double)v[start];
    }

public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> num;
        num.reserve(nums1.size() + nums2.size());
        num.insert(num.end(), nums1.begin(), nums1.end());
        num.insert(num.end(), nums2.begin(), nums2.end());

        double ret = solve(num, 0, num.size() - 1);
        return ret;
    }
};

int main() {
    Solution *s;
    vector<int> num1;
    vector<int> num2;

    s = new Solution();
    num1 = {1, 3};
    num2 = {2};
    cout << s->findMedianSortedArrays(num1, num2) << '\n';
    delete s;

    s = new Solution();
    num1 = {1, 2};
    num2 = {3, 4};
    cout << s->findMedianSortedArrays(num1, num2) << '\n';
    delete s;

    s = new Solution();
    num1 = {1, 2, 7, 10};
    num2 = {5, 7};
    cout << s->findMedianSortedArrays(num1, num2) << '\n';
    delete s;

    return 0;
}
