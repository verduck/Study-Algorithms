#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

double solution(vector<int> arr) {
    double answer = accumulate(arr.begin(), arr.end(), 0) / static_cast<double>(arr.size());
    return answer;
}

int main() {
    vector<int> arr = { 1, 2, 3, 4 };
    double result = solution(arr);

    cout << result << '\n';
    return 0;
}