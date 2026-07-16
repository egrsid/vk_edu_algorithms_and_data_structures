#include <iostream>
#include <vector>
#include <algorithm>

void shellSort(std::vector<int>& vect) {
    if (vect.size() <= 1) { return; }

    int N = vect.size();
    for (int gap = N/2; gap > 0; gap /= 2) {
        for (int i = gap; i < N; ++i) {
            int j = i;
            while (j >= gap && vect[j] < vect[j-gap]) {
                std::swap(vect[j], vect[j-gap]);
                j -= gap;
            }
        }
    }
}

void shellSortWithoutSwap(std::vector<int>& vect) {
    int N = vect.size();
    for (int gap = N/2; gap > 0; gap /= 2) {
        for (int i = gap; i < N; ++i) {
            int temp = vect[i];
            int j;

            for (j = i; j >= gap && vect[j-gap] > temp; j -= gap) {
                vect[j] = vect[j-gap];
            }

            vect[j] = temp;
        }
    }
}

int main() {
    std::vector<int> a = {5, 4, 2, 2, 13};
    shellSortWithoutSwap(a);
    for (int i = 0; i < a.size(); ++i) {
        std::cout << a[i] << std::endl;
    }
}