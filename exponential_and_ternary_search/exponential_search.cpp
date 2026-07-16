#include <iostream>
#include <vector>

std::vector<int> exponentialSearch(const std::vector<int>& vect, const int target) {
    if (vect.empty() || vect[0] > target || vect[vect.size()-1] < target) { return {}; }

    int border = 1;
    int lastElIdx = vect.size()-1;

    while (border < lastElIdx && vect[border] < target) {
        border *= 2;
    }

    return {border/2, std::min(border, lastElIdx)};
}

int main() {
    std::vector<int> a = {3, 4, 7, 9, 11, 12, 18, 24, 63, 72, 81, 99, 100, 101};
    auto res = exponentialSearch(a, 18);
    if (!res.empty()) {
        std::cout << res[0] << " " << res[1];
    } else {
        std::cout << -1;
    }
}