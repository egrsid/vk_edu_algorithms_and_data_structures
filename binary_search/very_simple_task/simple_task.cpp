#include <iostream>

int find_min_time(const int N, const int x, const int y) {
    int left = 0;
    int right = (N - 1) * std::max(x, y);
    int middle = left + (right - left) / 2;

    while (left + 1 < right) {
        int res = middle / x + middle / y;
        if (res < N - 1) {
            left = middle;
        } else {
            right = middle;
        }

        middle = left + (right - left) / 2;
    }

    return right + std::min(x, y);
}

int main() {
    int x = 4;
    int y = 5;
    int N = 20;

    std::cout << find_min_time(N, x, y);
}