#include <iostream>

int main() {
    int N;
    std::cin >> N;

    int a;
    std::cin >> a;
    int b;
    std::cin >> b;

    int mx1 = a;
    int mx2 = b;
    for (int i = 2; i < N; ++i) {
        a = b;
        std::cin >> b;

        if (std::abs(mx1 - mx2) > std::abs(a - b)) {
            mx1 = a;
            mx2 = b;
        }
    }

    std::cout << mx1 << " " << mx2;
}