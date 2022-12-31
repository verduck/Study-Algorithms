#include <iostream>
#include <string>
#include <vector>
#include <deque>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    deque<int> belt;

    for (int i = 0; i < order.size(); i++) {
        belt.push_back(i + 1);
    }
    belt.push_back(0);

    int i = 0;
    while (true) {
        if (belt.front() == 0) {
            break;
        }
        if (belt.front() == order[i]) {
            belt.pop_front();
            i++;
            answer++;
        } else if (belt.back() == order[i]) {
            belt.pop_back();
            i++;
            answer++;
        } else {
            belt.push_back(belt.front());
            belt.pop_front();
        }
    }

    for (auto it = belt.end() - 1; i < order.size() && it != belt.begin(); it--) {
        if (*it == order[i]) {
            answer++;
            i++;
        } else {
            break;
        }
    }

    return answer;
}

int main() {
    vector<int> order = { 4, 3, 1, 2, 5 };
    int result = solution(order);
    cout << result << '\n';
    return 0;
}