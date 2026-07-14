#include <iostream>

int find_min_side(const int n, const int h, const int w) {
    int left = std::max(w, h);
    int right = n * left;
    int middle = (right + left) / 2;

    while (left + 1 < right) {
        int res = (middle / h) * (middle / w);
        if (res < n) {
            left = middle;
        } else {
            right = middle;
        }

        middle = (left + right) / 2;
    }

    return right;
}

int main() {
    int n = 9;
    int h = 3;
    int w = 4;

    std::cout << find_min_side(n, h, w);
}