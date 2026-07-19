#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int lowerBound(vector<int>& nums, int target) {
        long long left = 0;
        long long right = nums.size()-1;

        if (nums[left] > target || nums[right] < target) { return -1; }
        
        while (left + 1 < right) {
            long long middle = left + (right - left) / 2;
            if (nums[middle] >= target) {
                right = middle;
            } else {
                left = middle;
            }
        }

        if (nums[left] == target) { return left; }
        if (nums[right] == target) { return right; }
        return -1;
    }

    int upperBound(vector<int>& nums, int target) {
        long long left = 0;
        long long right = nums.size()-1;

        if (nums[left] > target || nums[right] < target) { return -1; }
        
        while (left + 1 < right) {
            long long middle = left + (right - left) / 2;
            if (nums[middle] > target) {
                right = middle;
            } else {
                left = middle;
            }
        }
        
        if (nums[right] == target) { return right; }
        if (nums[left] == target) { return left; }
        return -1;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) { return {-1, -1}; }

        int lb = lowerBound(nums, target);
        if (lb == -1) { return {-1, -1}; }
        int ub = upperBound(nums, target);
        
        return {lb, ub};
    }
};

int main() {

}