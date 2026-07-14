#include <iostream>

int find_root(const int num) {
    if (num == 0) { return 0; }
    if (num == 1) { return 1; }

    int left = 0;
    int right = num;
    int middle = (right + left) / 2;

    while (left + 1 < right) {
        if (middle * middle <= num) {
            left = middle;
        } else {
            right = middle;
        }

        middle = (left + right) / 2;
    }

    return left;
}

int main() {
    int a = 144;
    int b = 14;

    std::cout << find_root(a) << std::endl << find_root(b);
}