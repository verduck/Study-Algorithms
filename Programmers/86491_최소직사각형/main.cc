#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int max_weight = 0;
    int max_height = 0;
    for (const vector<int>& v : sizes) {
        if (v[0] > v[1]) {
            max_weight = max(max_weight, v[0]);
            max_height = max(max_height, v[1]);
        } else {
            max_weight = max(max_weight, v[1]);
            max_height = max(max_height, v[0]);
        }
    }

    answer = max_weight * max_height;
    return answer;
}

int main() {
    vector<vector<int>> sizes = { { 60, 50 }, { 30, 70 }, { 60, 30 }, { 80, 40 } };
    int answer = solution(sizes);
    cout << answer << '\n';
    return 0;
}