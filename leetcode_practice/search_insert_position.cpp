#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;

        if (nums[left] > target) { return 0; }
        if (nums[right] < target) { return nums.size(); }

        while (left < right) {
            int middle = left + (right - left) / 2;
            if (nums[middle] == target) { return middle; }
            if (nums[middle] < target) {
                left = middle + 1;
            } else {
                right = middle;
            }
        }

        return left;
    }
};

int main() {
    vector<int> a{2, 3, 5, 7, 8, 10};
    Solution s;
    std::cout << s.searchInsert(a, 9);
}