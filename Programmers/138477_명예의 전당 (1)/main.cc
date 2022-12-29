#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    priority_queue<int, vector<int>, greater<>> hall_of_fame;

    for (int s : score) {
        if (hall_of_fame.size() >= k) {
            if (hall_of_fame.top() < s) {
                hall_of_fame.pop();
                hall_of_fame.push(s);
            }
        } else {
            hall_of_fame.push(s);
        }
        answer.push_back(hall_of_fame.top());
    }
    return answer;
}

int main() {
    int k =  3;
    vector<int> score = { 10, 100, 20, 150, 1, 100, 200 };

    vector<int> result = solution(k, score);
    for (int i : result) {
        cout << i << ' ';
    }
    return 0;
}