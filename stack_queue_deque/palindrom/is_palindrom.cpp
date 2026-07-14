#include <iostream>
#include <stack>
#include <deque>
#include <string_view>

bool func1(std::string_view a) {
    std::stack<char> st;
    for (int i = 0; i < a.size(); ++i) {
        st.push(a[i]);
    }

    for (int i = 0; i < a.size(); ++i) {
        if (a[i] != st.top()) {
            return false;
        }

        st.pop();
    }

    return true;
}

bool func2(std::string_view a) {
    std::deque<char> dq;
    for (int i = 0; i < a.size(); ++i) {
        dq.push_back(a[i]);
    }

    while (dq.size() > 1) {
        if (dq.front() != dq.back()) {
            return false;
        }

        dq.pop_back();
        dq.pop_front();
    }

    return true;
}

bool func3(std::string_view a) {
    int i = 0;
    int j = a.size() - 1;
    
    while (i < j) {
        if (a[i] != a[j]) { return false; }
        ++i;
        --j;
    }

    return true;
}


int main() {
    std::string a = "123321";
    std::cout << std::boolalpha << func1(a) << ' ' << func2(a) << ' ' << func3(a);
}

