#include <iostream>
#include <vector>

int binarySearch(const std::vector<int>& data, const int target) {
    int left = 0;
    int right = data.size() - 1;
    int middle = (left + right) / 2;
    
    if (data.empty() || data[left] > target || data[right] < target) { return -1; }

    while (left <= right) {
        if (data[middle] == target) {
            return middle;
        } else if (data[middle] < target) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }

        middle = (left + right) / 2;
    }

    return -1;
}

int binarySearchRecursion(const std::vector<int>& data, const int left, const int right, const int target) {
    if (left > right) { return -1; }
    if (data.empty() || data[left] > target || data[right] < target) { return -1; }

    int middle = (left + right) / 2;
    if (data[middle] == target) { return middle; }
    if (data[middle] < target) { return binarySearchRecursion(data, middle + 1, right, target); }
    if (data[middle] > target) { return binarySearchRecursion(data, left, middle - 1, target); }

    return -1;
}

int leftBinarySearch(const std::vector<int>& data, const int target) {
    int left = 0;
    int right = data.size() - 1;
    int middle = (left + right) / 2;

    if (data.empty() || data[left] > target || data[right] < target) { return -1; }

    while (left + 1 < right) {
        if (data[middle] < target) {
            left = middle;
        } else {
            right = middle;
        }

        middle = (left + right) / 2;
    }

    if (data[left] == target) { return left; }
    if (data[right] == target) { return right; }

    return -1;
}

int rightBinarySearch(const std::vector<int>& data, const int target) {
    int left = 0;
    int right = data.size() - 1;
    int middle = (left + right) / 2;

    if (data.empty() || data[left] > target || data[right] < target) { return -1; }

    while (left + 1 < right) {
        if (data[middle] > target) {
            right = middle;
        } else {
            left = middle;
        }

        middle = (right + left) / 2;
    }

    if (data[right] == target) { return right; }
    if (data[left] == target) { return left; }
    return -1;
}

int main() {
    std::vector<int> a{1, 2, 3, 4, 5};
    std::cout << binarySearchRecursion(a, 0, a.size() - 1, 1);
}