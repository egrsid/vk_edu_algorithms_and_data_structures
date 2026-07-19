#include <iostream>
#include <vector>

int binarySearch(const std::vector<int>& data, const int target) {
    if (data.empty()) { return 0; }

    int left = 0;
    int right = data.size() - 1;
    int middle = (right + left) / 2;

    if (data[left] > target) { return 0; }
    if (data[right] < target) { return data.size(); }

    while (left <= right) {
        if (data[middle] == target) {
            return middle;
        } else if (data[middle] < target) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }

        middle = (right + left) / 2;
    }

    if (data[middle] > target) { return middle - 1; }
    else { return middle + 1; }
}

// идеальное решение
int searchInsertPosition(const std::vector<int>& data, const int target) {
    if (data.empty()) {
        return 0;
    }

    int left = 0;
    int right = data.size(); // Используем размер вектора как правую невключенную границу

    while (left < right) {
        int middle = left + (right - left) / 2; // Защита от переполнения

        if (data[middle] >= target) {
            // Если элемент >= target, значит ответ лежит в middle или левее
            right = middle;
        } else {
            // Если элемент < target, значит ответ гарантированно правее middle
            left = middle + 1;
        }
    }

    // После окончания цикла left укажет ровно на нужную позицию
    return left;
}

int main(){
    int N;
    std::cin >> N;
    
    std::vector<int> data(N);
    for (int i = 0 ; i < N; ++i) {
        std::cin >> data[i];
    }

    int target;
    std::cin >> target;

    std::cout << binarySearch(data, target);
}