#include <iostream>
#include <vector>

int ternarySearch(const std::vector<int>& vect, const int target) {
    if (vect.empty()) { return -1; }

    int left = 0;
    int right = vect.size() - 1;
    
    if (vect[left] > target || vect[right] < target) { return -1; }

    while (left <= right) {
        int m1 = left + (right - left) / 3;
        int m2 = right - (right - left) / 3;

        if (vect[m1] == target) { return m1; }
        if (vect[m2] == target) { return m2; }
        if (target < vect[m1]) { 
            right = m1 - 1;
        } else if (vect[m1] < target && target < vect[m2]) {
            left = m1 + 1;
            right = m2 - 1;
        } else {
            left = m2 + 1;
        }
    }

    return -1;
}

int ternarySearchRecursion(const std::vector<int>& vect, const int target, const int left, const int right) {
    if (left > right) { return -1; }

    int m1 = left + (right - left) / 3;
    int m2 = right - (right - left) / 3;

    if (vect[m1] == target) { return m1; }
    if (vect[m2] == target) { return m2; }
    if (target < vect[m1]) { return ternarySearchRecursion(vect, target, left, m1-1); }
    if (vect[m1] < target && target < vect[m2]) { return ternarySearchRecursion(vect, target, m1+1, m2-1); }
    return ternarySearchRecursion(vect, target, m2+1, right);
}

int startTernarySearchRecursion(const std::vector<int>& vect, const int target) {
    if (vect.empty()) { return -1; }

    int left = 0;
    int right = vect.size() - 1;

    if (vect[left] > target || vect[right] < target) { return -1; }

    return ternarySearchRecursion(vect, target, left, right);
}

int main() {
    std::vector<int> a = {1, 2, 3, 4, 5, 6, 7};
    std::cout << ternarySearch
    (a, 8);
}