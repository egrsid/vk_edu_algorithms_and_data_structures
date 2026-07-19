#include <iostream>
#include <vector>
#include <algorithm>

void choiceSort(std::vector<int>& vect) {
    for (int i=0; i < vect.size()-1; ++i) {
        int mnIdx = i;
        for (int j=i+1; j < vect.size(); ++j) {
            if (vect[j] < vect[mnIdx]) {
                mnIdx = j;
            }
        }

        std::swap(vect[i], vect[mnIdx]);
    }
}

int main() {
    std::vector<int> a = {5, 4, 2, 2, 13};
    choiceSort(a);
    for (int i = 0; i < a.size(); ++i) {
        std::cout << a[i] << std::endl;
    }
}