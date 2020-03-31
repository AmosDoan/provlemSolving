//
// Created by Amos on 2020/03/31.
//
#include <iostream>
#include <vector>

using namespace std;

// https://medium.com/@hazemu/finding-the-median-of-2-sorted-arrays-in-logarithmic-time-1d3f2ecbeb46 참고하자
class Solution {
private:
    double findMedian(vector<int> sorted) {
        int s = sorted.size();
        if (s % 2 == 0) {
            int right = s / 2;
            int left = s / 2 - 1;
            return (double)(sorted[left] + sorted[right]) / 2.0;
        } else {
            return (double)sorted[s / 2];
        }
    }

public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> buf;
        buf.reserve(nums1.size() + nums2.size());
        buf.insert(buf.end(), nums1.begin(), nums1.end());
        buf.insert(buf.end(), nums2.begin(), nums2.end());

        sort(buf.begin(), buf.end());
        return findMedian(buf);
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
