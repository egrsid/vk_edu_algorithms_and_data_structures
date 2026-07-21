#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    int search(vector<int>& nums, int target) {
        auto itIdx = lower_bound(nums.begin(), nums.end(), target);
        if (itIdx != nums.end() && *itIdx == target) {
            return itIdx - nums.begin();
        }
        return -1;
    }
};

int main() {
    vector<int> a{-1};
    Solution s;

    int res = s.search(a, 2);
    std::cout << res;
}