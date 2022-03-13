#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string s) {
    int answer = 0;
    stack<char> st;

    for (char c : s) {
        if (st.empty()) {
            st.push(c);
        } else {
            if (st.top() == c) {
                st.pop();
            } else {
                st.push(c);
            }
        }
    }

    answer = st.empty();

    return answer;
}

int main() {
    string s = "baabaa";
    int result = solution(s);
    cout << result << '\n';
    return 0;
}