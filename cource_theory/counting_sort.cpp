#include <iostream>
#include <vector>
#include <algorithm>

void countingSort(std::vector<int>& vect) {
    if (vect.size() <= 1) { return; }

    int mxRange = *std::max_element(vect.begin(), vect.end());
    std::vector<int> counts(mxRange + 1, 0);

    for (int i = 0; i < vect.size(); ++i) {
        counts[vect[i]] += 1;
    }

    int curIdx = 0;
    for (int i = 0; i < counts.size(); ++i) {
        for (int j = 0; j < counts[i]; ++j) {
            vect[curIdx] = i;
            ++curIdx;
        }
    }
}

int main() {
    std::vector<int> a{2, 13, 4, 7, 2, 3, 8};
    countingSort(a);
    for (int p: a) {
        std::cout << p << " ";
    }
}