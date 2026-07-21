#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1) { return x; }

        int left = 0;
        int right = x;

        while (left + 1 < right) {
            long long middle = left + (right - left) / 2;
            if (middle * middle <= x) {
                left = middle;
            } else {
                right = middle;
            }
        }

        return left;
    }
};

int main() {
    int x = 4;
    Solution s;
    std::cout << s.mySqrt(x);
}