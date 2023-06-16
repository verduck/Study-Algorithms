#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size(), 0);
    stack<int> st;

    for (int i = 0; i < numbers.size(); i++) {
        while (!st.empty() && numbers[st.top()] < numbers[i]) {
            answer[st.top()] = numbers[i];
            st.pop();
        }
        st.push(i);
    }

    while (!st.empty()) {
        answer[st.top()] = -1;
        st.pop();
    }
    
    return answer;
}

int main() {
    vector<int> numbers = { 9, 1, 5, 3, 6, 2 };

    vector<int> result = solution(numbers);

    for (int i : result) {
        cout << i << '\n';
    }

    return 0;
}