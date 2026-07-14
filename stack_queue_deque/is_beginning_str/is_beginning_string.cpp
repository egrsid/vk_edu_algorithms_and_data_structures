#include <iostream>
#include <queue>
#include <string>

bool starts_with1(const std::string& a, const std::string& b) {
    std::queue<char> st;
    for (int i = 0; i < a.size(); ++i) {
        st.push(a[i]);
    }

    for (int i = 0; i < b.size(); ++i) {
        if (b[i] == st.front()) {
            st.pop();
        }
    }

    return st.empty();
}

bool starts_with2(const std::string& a, const std::string& b) {
    int i = 0;
    int j = 0;

    while (i < a.size() && j < b.size()) {
        if (a[i] == b[j]) {
            ++i;
        }
        ++j;
    }

    return i == a.size();
}

int main() {
    std::string a = "123";
    std::string b = "1kjvnkjdfvldkcndknl2vlfnv3kjwenkjens";
    std::cout << std::boolalpha << starts_with1(a, b) << " " << starts_with2(a, b);
}