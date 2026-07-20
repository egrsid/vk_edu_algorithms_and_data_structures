#include <iostream>
#include <vector>

// МЕДЛЕННАЯ ВЕРСИЯ
// std::vector<int> merge(const std::vector<int>& leftPart, const std::vector<int>& rightPart, const int digit) {
//     std::vector<int> res(leftPart.size() + rightPart.size());
//     int i = 0;
//     int j = 0;

//     int curIdx = 0;
//     while (i < leftPart.size() && j < rightPart.size()) {
//         if ((leftPart[i] / digit) % 10 <= (rightPart[j] / digit) % 10) {
//             res[curIdx] = leftPart[i];
//             ++i;
//         } else {
//             res[curIdx] = rightPart[j];
//             ++j;
//         }

//         ++curIdx;
//     }

//     while (i < leftPart.size()) {
//         res[curIdx] = leftPart[i];
//         ++i; ++curIdx;
//     }
//     while (j < rightPart.size()) {
//         res[curIdx] = rightPart[j];
//         ++j; ++curIdx;
//     }

//     return res;
// }

// std::vector<int> mergeSort(std::vector<int>& vect, const int digit) {
//     if (vect.size() <= 1) { return vect; }

//     std::vector<int> leftPart(vect.begin(), vect.begin() + vect.size() / 2);
//     std::vector<int> rightPart(vect.begin() + vect.size() / 2, vect.end());

//     return merge(mergeSort(leftPart, digit), mergeSort(rightPart, digit), digit);
// }

// void radixSort(std::vector<int>& vect) {
//     int mx = *std::max_element(vect.begin(), vect.end());
//     int mxDigits = (mx == 0) ? 1 : std::log10(std::abs(mx)) + 1;

//     for (int i = 1; i < std::pow(10, mxDigits); i *= 10) {
//         vect = mergeSort(vect, i);
//     }
// }

// ОПТИМИЗИРОВАННЫЙ ВАРИАНТ

void countingSortForRadix(std::vector<int>& vect, long long exp) {
    if (vect.empty()) { return; }

    int N = vect.size();
    std::vector<int> counts(10);
    std::vector<int> res(N);

    // считаем количество каждой цифры в целом во всем массиве (как в обычном counting sort)
    for (int i = 0; i < N; ++i) {
        int digit = (vect[i] / exp) % 10;
        ++counts[digit];
    }

    // ставим на каждую позицию по индексу числа то, на каком месте исключая оно 
    // долджно оказаться в отсортированном на этом шаге массиве
    for (int i = 1; i < 10; ++i) {
        counts[i] += counts[i-1];
    }

    for (long long i = N-1; i >= 0; --i) {
        int digit = (vect[i] / exp) % 10;
        res[counts[digit]-1] = vect[i];
        --counts[digit];
    }

    std::copy(res.begin(), res.end(), vect.begin());
}

void radixSort(std::vector<int>& vect) {
    if (vect.size() <= 1) { return; }

    int mxEl = *std::max_element(vect.begin(), vect.end());
    for (int exp = 1; mxEl / exp > 0; exp *= 10) {
        countingSortForRadix(vect, exp);
    }
}


int main() {
    std::vector<int> a{5, 4, 3, 2, 1};
    radixSort(a);
    for (int p: a) {
        std::cout << p << " ";
    }
}
