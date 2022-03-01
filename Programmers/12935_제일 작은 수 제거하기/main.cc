#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    arr.erase(min_element(arr.begin(), arr.end()));
    if (arr.empty()) {
        answer = { -1 };
    } else {
        answer = arr;
    }
    return answer;
}

int main() {
    vector<int> arr = { 4, 3, 2, 1 };
    vector<int> result = solution(arr);

    for (int i : result) {
        cout << i << ' ';
    }
    cout << '\n';
    return 0;
}