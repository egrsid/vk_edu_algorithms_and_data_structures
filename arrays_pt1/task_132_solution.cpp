#include <iostream>

int main() {
    int N;
    std::cin >> N;

    int* arr = new int[N]{};
    for (int i = 0; i < N; ++i) {
        std::cin >> arr[i];
    }

    int element;
    std::cin >> element;

    int size = 0;
    int first_useful_idx = 0;
    for (int i = 0; i < N; ++i) {
        if (arr[i] != element) {
            arr[first_useful_idx] = arr[i];
            ++first_useful_idx;
            ++size;
        }
    }

    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << (i == size - 1 ? "" : " ");
    }

    delete[] arr;
}