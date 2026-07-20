#include <iostream>
#include <vector>

int search_k_order_num(std::vector<int>& vect, const int k, const int left, const int right) {
    if (k < 1 || k > vect.size() || vect.empty()) { return -1; }
    if (left >= right) { return vect[left]; }

    int i = left;
    int j = right;
    int middle = left + (right - left) / 2;
    int a = vect[i], b = vect[middle], c = vect[j];
    int pivot = std::max(std::min(a, b), std::min(std::max(a, b), c));

    while (i <= j) {
        while (vect[i] < pivot) { ++i; }
        while (vect[j] > pivot) { --j; }

        if (i <= j) {
            std::swap(vect[i], vect[j]);
            ++i; --j;
        }
    }

    int idxToFind = k - 1;
    if (idxToFind <= j) { return search_k_order_num(vect, k, left, j); }
    if (idxToFind >= i) { return search_k_order_num(vect, k, i, right); }
    return vect[idxToFind];
}

int main() {
    std::vector<int> a{10, 20, 30, 40, 50};
    std::cout << search_k_order_num(a, 4, 0, a.size()-1);
}