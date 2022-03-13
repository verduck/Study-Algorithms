#include <iostream>
#include <vector>
#include <stack>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    stack<pair<int, int>> st;

    for (int i = 0; i < progresses.size(); i++) {
        int day = ceil((100 - progresses[i]) / static_cast<double>(speeds[i]));
        if (st.empty()) {
            st.push({ day, 1 });
        } else {
            if (st.top().first < day) {
                answer.push_back(st.top().second);
                st.pop();
                st.push({ day, 1 });
            } else {
                st.top().second++;
            }
        }
    }

    answer.push_back(st.top().second);

    return answer;
}

int main() {
    vector<int> progresses = { 93, 30, 55 };
    vector<int> speeds = { 1, 30, 5 };
    vector<int> answer = solution(progresses, speeds);
    for (int i : answer) {
        cout << i << ' ';
    }
    cout << '\n';
    return 0;
}