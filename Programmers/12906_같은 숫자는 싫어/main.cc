#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer = arr;

    auto last = unique(answer.begin(), answer.end());
    answer.erase(last, answer.end());
    
    return answer;
}

int main() {
    vector<int> arr = { 1, 1, 3, 3, 0, 1, 1 };
    vector<int> result = solution(arr);
    for (int i : result) {
        cout << i << ' ';
    }
    cout << '\n';
    return 0;
}