//
// Created by Amos on 2020/04/19.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int solve(vector<int>& nums, int start, int end, int target) {
        int middle = (start + end) / 2;
        if (nums[start] > nums[end]) {
            int left = solve(nums, start, middle, target);
            if (left != -1) {
                return left;
            }
            return solve(nums, middle + 1, end, target);
        } else {
            return binarySearch(nums, start, end, target);
        }
    }

    int binarySearch(vector<int>& nums, int start, int end, int target) {
        if (end < start) {
            return -1;
        }
        int mid = (start + end) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            return binarySearch(nums, mid + 1, end, target);
        } else if (nums[mid] > target) {
            return binarySearch(nums, start, mid - 1, target);
        }

        return -1;
    }

public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) {
            return -1;
        }

        if (nums.size() == 1) {
            return nums[0] == target ? 0 : -1;
        }

        return solve(nums, 0, nums.size() - 1, target);
    }
};

int main() {
    Solution *s;
    vector<int> v;

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

    s = new Solution();
    v = {4, 5, 6, 7, 8, 1, 2, 3};
    cout << s->search(v, 8) << '\n';
    delete s;


    return 0;
}

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
