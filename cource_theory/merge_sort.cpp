#include <iostream>
#include <vector>

std::vector<int> merge(const std::vector<int>& leftPart, const std::vector<int>& rightPart) {
    std::vector<int> res(leftPart.size() + rightPart.size());
    int i = 0;
    int j = 0;
    int curPos = 0;

    while (i < leftPart.size() && j < rightPart.size()) {
        if (leftPart[i] <= rightPart[j]) {
            res[curPos] = leftPart[i];
            ++i;
        } else {
            res[curPos] = rightPart[j];
            ++j;
        }

        ++curPos;
    }

    while (i < leftPart.size()) {
        res[curPos] = leftPart[i];
        ++curPos;
        ++i;
    }
    while (j < rightPart.size()) {
        res[curPos] = rightPart[j];
        ++curPos;
        ++j;
    }

    return res;
}

std::vector<int> mergeSort(std::vector<int>& vect) {
    if (vect.size() <= 1) { return vect; }

    std::vector<int> leftPart(vect.begin(), vect.begin() + vect.size() / 2);
    std::vector<int> rightPart(vect.begin() + vect.size() / 2, vect.end());

    return merge(mergeSort(leftPart), mergeSort(rightPart));
}

int main() {
    std::vector<int> a{5, 4, 3, 2, 1};
    std::vector<int> sorted = mergeSort(a);
    for (int i = 0; i < sorted.size(); ++i) {
        std::cout << sorted[i];
    }
}