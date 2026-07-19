#include <iostream>
#include <vector>

void insertSort(std::vector<int>& vect) {
    if (vect.size() <= 1) { return; }
    
    for (int i = 1; i < vect.size(); ++i) {
        for (int j = i; j > 0; --j) {
            if (vect[j-1] > vect[j]) {
                std::swap(vect[j-1], vect[j]);
            } else {
                break;
            }
        }
    }
}

void insertSortWithoutSwap(std::vector<int>& vect) {
    for (int i = 1; i < vect.size(); ++i) {
        int temp = vect[i];
        int j = i;

        while (j > 0 && vect[j-1] > temp) {
            vect[j] = vect[j-1];
            --j;
        }
        vect[j] = temp;
    }
}

int main() {
    std::vector<int> a = {5, 4, 2, 2, 13};
    insertSort(a);
    for (int i = 0; i < a.size(); ++i) {
        std::cout << a[i] << std::endl;
    }
}