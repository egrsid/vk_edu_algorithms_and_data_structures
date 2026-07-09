#include <iostream>

int main() {
    int N;
    std::cin >> N;

    int mx;
    std::cin >> mx;
    int temp;
    for (int i = 1; i < N; ++i) {
        std::cin >> temp;
        if (temp > mx) {
            mx = temp;
        }
    }

    std::cout << mx;

}