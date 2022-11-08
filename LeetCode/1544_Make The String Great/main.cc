#include <iostream>
#include <string>
#include <stack>
#include <cmath>

using namespace std;

class Solution {
public:
    string makeGood(string s) {
        string result;
        stack<char> st;

        for (int i = 0; i < s.size(); i++) {
            if (st.empty()) {
                st.push(s[i]);
            } else {
                char prev = st.top();
                if (abs(prev - s[i]) == 32) {
                    st.pop();
                } else {
                    st.push(s[i]);
                }
            }
        }

        while (!st.empty()) {
            result = st.top() + result;
            st.pop();
        }

        return result;
    }
};

void init();

int main() {
    string s = "leEeetcode";

    init();

    Solution solution;
    string result = solution.makeGood(s);

    cout << result << '\n';
}

void init() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}