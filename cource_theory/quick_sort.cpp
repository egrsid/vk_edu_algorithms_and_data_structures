#include <iostream>
#include <vector>

void quickSort(std::vector<int>& vect, const int left, const int right) {
    if (vect.size() <= 1 || left >= right) { return; }

    int i = left;
    int j = right;
    int middle = left + (right - left) / 2;
    // медиана из 3 чисел: самое левое, самое правое и центральное
    int pivot = std::max(std::min(vect[i], vect[j]), std::min(std::max(vect[i], vect[j]), vect[middle]));

    while (i <= j) {
        while (vect[i] < pivot) { ++i; }
        while (vect[j] > pivot) { --j; }

        if (i <= j) {
            std::swap(vect[i], vect[j]);
            ++i; 
            --j;
        }
    }

    if (j > 0) {
        quickSort(vect, left, j+1);
    }
    if (i < vect.size()) {
        quickSort(vect, i, right);
    }
}

int main() {
    std::vector<int> a{5, 4, 3, 2, 1};
    quickSort(a, 0, a.size()-1);

    for (int num : a) {
        std::cout << num << " ";
    }
}