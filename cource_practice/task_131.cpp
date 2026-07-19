#include <iostream>

int main() {
    int N;
    std::cin >> N;

    int* arr = new int[N]{};
    int first_non_zero_idx = 0;
    int temp;
    for (int i = 0; i < N; ++i) {
        std::cin >> temp;
        if (temp != 0) {
            arr[first_non_zero_idx] = temp;
            ++first_non_zero_idx;
        }
    }

    for (int i = 0; i < N; ++i) {
        if (i != N-1) {
            std::cout << arr[i] << ' ';
        } else {
            std::cout << arr[i];
        }
    }

    delete[] arr;
}