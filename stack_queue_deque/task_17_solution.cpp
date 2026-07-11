#include <iostream>
#include <stack>

int main() {
    int N;
    std::cin >> N;

    int last2 = -1;
    for (int i = 0; i < N; ++i) {
        int temp;
        std::cin >> temp;

        if (temp % 2 == 0) {
            last2 = temp;
        }
    }

    std::cout << last2;

    // std::stack<int> st;

    // for (int i = 0; i < N; ++i) {
    //     int temp;
    //     std::cin >> temp;
    //     st.push(temp);
    // }

    // bool flag = false;
    // while (!st.empty()) {
    //     if (st.top() % 2 == 0) {
    //         std::cout << st.top();
    //         flag = true;
    //         break;
    //     }

    //     st.pop();
    // }

    // if (!flag) { std::cout << -1; }
}