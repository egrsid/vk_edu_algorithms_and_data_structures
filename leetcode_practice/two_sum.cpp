#include <algorithm>
#include <vector>
#include <unordered_map>

class Solution1 {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::vector<std::vector<int>> sorted_nums(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            sorted_nums[i] = {nums[i], i};
        }
        std::sort(sorted_nums.begin(), sorted_nums.end());
        
        int i = 0;
        int j = nums.size() - 1;
        while (i < j) {
            if (sorted_nums[i][0] + sorted_nums[j][0] == target) {
                return {sorted_nums[i][1], sorted_nums[j][1]};
            } else if (sorted_nums[i][0] + sorted_nums[j][0] > target) {
                --j;
            } else {
                ++i;
            }
        }

        return {};
    }
};

class Solution2 {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            m[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); ++i) {
            int diff = target - nums[i];
            if (m.find(diff) != m.end() && m[diff] != i) {
                return {m[nums[i]], m[diff]};
            }
        }

        return {};
    }
};

class Solution3 {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            int diff = target - nums[i];
            if (m.find(diff) != m.end()) {
                return {i, m[diff]};
            }

            m[nums[i]] = i;
        }

        return {};
    }
};

int main() {
    
}