#include <iostream>
#include <vector>

std::vector<int> merge_sorted_arrays(std::vector<int>& v1, std::vector<int>& v2) {
    std::vector<int> res;

    // Оптимизация: выделяем память один раз, избегаем лишних копирований внутри push_back
    // Либо можно сразу выделить нужный объем памяти и обращаться к res по индексу, вместо push_back()
    res.reserve(v1.size() + v2.size());

    int i = 0;
    int j = 0;
    while (i < v1.size() && j < v2.size()) {
        if (v1[i] < v2[j]) {
            res.push_back(v1[i]);
            ++i;
        } else {
            res.push_back(v2[j]);
            ++j;
        }
    }

    res.insert(res.end(), v1.begin()+i, v1.end());
    res.insert(res.end(), v2.begin()+j, v2.end());

    return res;
}

int main() {
    std::vector<int> a{1, 2, 3, 4, 5};
    std::vector<int> b{3, 4, 5, 6};

    auto r = merge_sorted_arrays(a, b);
    for (int i = 0; i < r.size(); ++i) {
        std::cout << r[i] << (i == r.size()-1 ? "" : " ");
    }
}