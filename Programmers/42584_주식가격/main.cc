#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), 0);
    stack<pair<int, int>> st;

    for (int i = 0; i < prices.size(); i++) {
        while (!st.empty() && prices[i] < st.top().second) {
            pair<int, int> p = st.top();
            answer[p.first] = i - p.first;
            st.pop();
        }
        st.push({ i, prices[i] });
    }

    while (!st.empty()) {
        pair<int, int> p = st.top();
        answer[p.first] = prices.size() - 1 - p.first;
        st.pop();
    }
    return answer;
}

int main() {
    vector<int> prices = { 1, 2, 3, 2, 3 };
    vector<int> answer = solution(prices);
    for (int i : answer) {
        cout << i << ' ';
    }
    cout << '\n';
    return 0;
}