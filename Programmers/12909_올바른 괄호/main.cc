#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool solution(string s) {
    bool answer = true;
    stack<char> st;

    for (const char ch : s) {
        if (ch == '(') {
            st.push(ch);
        } else if (ch == ')') {
            if (st.empty()) {
                return false;
            }
            st.pop();
        }
    }

    answer = st.empty();
    
    return answer;
}

int main() {
    string s = "()()";
    bool result = solution(s);
    cout << boolalpha << result << '\n';
    return 0;
}