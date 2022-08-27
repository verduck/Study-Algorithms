#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (const char& ch : s) {
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            } else {
                if (st.empty()) {
                    return false;
                }
                char t = st.top();
                st.pop();
                if (ch == ')' && t != '(') {
                    return false;
                } else if (ch == '}' && t != '{') {
                    return false;
                } else if (ch == ']' && t != '[') {
                    return false;
                }
            }
        }

        return st.empty();
    }
};

void init();

int main() {
    string s = "]";

    init();

    Solution solution;
    cout << boolalpha << solution.isValid(s) << '\n';
}

void init() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}