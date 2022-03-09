#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

bool check(const string& s) {
    stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else {
            if (!st.empty()) {
                char ch = st.top();
                if (ch == '(' && c == ')') {
                    st.pop();
                } else if (ch == '[' && c == ']') {
                    st.pop();
                } else if (ch == '{' && c == '}') {
                    st.pop();
                } else {
                    return false;
                }
            } else {
                return false;
            }
        }
    }

    return st.empty();
}

int solution(string s) {
    int answer = 0;

    for (int i = 0; i < s.size(); i++) {
        rotate(s.begin(), s.begin() + 1, s.end());
        if (check(s)) {
            answer++;
        }
    }

    return answer;
}

int main() {
    string s = "(";
    int result = solution(s);
    cout << result << '\n';
    return 0;
}