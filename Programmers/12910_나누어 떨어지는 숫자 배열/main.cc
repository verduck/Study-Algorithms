#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    for (int i : arr) {
        if (!(i % divisor)) {
            answer.push_back(i);
        }
    }
    if (answer.empty()) {
        answer = { -1 };
    } else {
        sort(answer.begin(), answer.end());
    }
    return answer;
}

int main() {
    vector<int> arr = { 5, 9, 7, 10 };
    int divisor = 5;
    vector<int> result = solution(arr, divisor);
    for (int i : result) {
        cout << i << ' ';
    }
    cout << '\n';
    return 0;
}