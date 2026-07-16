#include <iostream>
#include <vector>

void bubbleSort(std::vector<int>& vect) {
    if (vect.size() <= 1) { return; }

    bool sorted = false;
    while (!sorted) {
        sorted = true;
        for (int i = 0; i < vect.size()-1; ++i) {
            if (vect[i] > vect[i+1]) {
                std::swap(vect[i], vect[i+1]);
                sorted = false;
            }
        }
    }
}

int main() {
    std::vector<int> a = {5, 4, 2, 2, 13};
    bubbleSort(a);
    for (int i = 0; i < a.size(); ++i) {
        std::cout << a[i] << std::endl;
    }
}