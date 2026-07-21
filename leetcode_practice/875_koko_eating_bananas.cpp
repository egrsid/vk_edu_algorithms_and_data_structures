#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());

        while (left + 1 < right) {
            long long middle = left + (right - left) / 2;

            long long hrCount = 0;
            for (int pile: piles) {
                hrCount += (pile + middle - 1) / middle;
                if (hrCount > h) { break; }
            }

            if (hrCount > h) {
                left = middle;
            } else {
                right = middle;
            }
        }

        return right;
    }
};



int main() {
    vector<int> a{805306368,805306368,805306368};
    Solution s;
    std::cout << s.minEatingSpeed(a, 1000000000);
}