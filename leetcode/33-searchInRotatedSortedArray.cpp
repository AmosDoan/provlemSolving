//
// Created by Amos on 2020/04/19.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int binarySearch(vector<int>& nums, int start, int end, int target) {
        if (end < start) {
            return -1;
        }

        int mid = (start + end) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target && target <= nums[end]) {
            return binarySearch(nums, mid + 1, end, target);
        } else if (nums[mid] > target && target >= nums[start]) {
            return binarySearch(nums, start, mid - 1, target);
        }

        // left compare
        if (nums[mid] > target && nums[start] > target) {
            if (nums[end] < target) {
                return -1;
            }

            return binarySearch(nums, mid + 1, end, target);
        }

        if (nums[mid] < target && nums[end] < target) {
            if (nums[start] > target) {
                return -1;
            }
            return binarySearch(nums, start, mid - 1, target);
        }

        return -1;
    }

public:
    int search(vector<int>& nums, int target) {
        return binarySearch(nums, 0, nums.size() - 1, target);
    }
};

int main() {
    Solution *s;
    vector<int> v;

    /*
    s = new Solution();
    v = {4, 5, 6, 7, 0, 1, 2};
    cout << s->search(v, 0) << '\n';
    delete s;

    s = new Solution();
    v = {4, 5, 6, 7, 0, 1, 2};
    cout << s->search(v, 3) << '\n';
    delete s;

    s = new Solution();
    v = {4, 5, 6, 0, 1, 2};
    cout << s->search(v, 5) << '\n';
    delete s;

    s = new Solution();
    v = {5, 1, 3};
    cout << s->search(v, 5) << '\n';
    delete s;
    */

    s = new Solution();
    v = {4, 5, 6, 7, 8, 1, 2, 3};
    cout << s->search(v, 8) << '\n';
    delete s;


    return 0;
}
