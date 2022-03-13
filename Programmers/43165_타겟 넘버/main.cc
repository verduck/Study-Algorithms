#include <iostream>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;

    for (int i = 0; i < (1 << numbers.size()); i++) {
        vector<int> signed_numbers = numbers;
        for (int j = 0; j < numbers.size(); j++) {
            if (i & (1 << j)) {
                signed_numbers[j] *= -1;
            }
        }
        int n = accumulate(signed_numbers.begin(), signed_numbers.end(), 0);
        if (n == target) {
            answer++;
        }
    }
    return answer;
}

int main() { 
    vector<int> numbers = { 1, 1, 1, 1, 1 };
    int target = 3;
    int result = solution(numbers, target);
    cout << result << '\n';
    return 0;
}