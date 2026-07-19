#include <iostream>
#include <vector>

std::vector<int> exponentialSearch(const std::vector<int>& vect, const int target) {
    if (vect.empty() || vect[0] > target) { return {0, 1}; }

    int border = 1;
    int lastElIdx = vect.size() - 1;

    while (border < lastElIdx && vect[border] < target) {
        border *= 2;
    }

    return {border/2, std::min(border, lastElIdx)};
}

int main() {
    int N;
    std::cin >> N;
    std::vector<int> vect(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> vect[i];
    }
    int target;
    std::cin >> target;

    auto res = exponentialSearch(vect, target);
    if (!res.empty()) {
        std::cout << res[0] << " " << res[1];
    } else {
        std::cout << -1;
    }
}