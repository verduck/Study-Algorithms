#include <iostream>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

int solution(vector<int> arr) {
    int answer = arr[0];

    for (int i = 1; i < arr.size(); i++) {
        answer = lcm(answer, arr[i]);
    }

    return answer;
}
int main() {
    vector<int> arr = { 2,6,8,14 };
    int result = solution(arr);
    cout << result << '\n';
    return 0;
}