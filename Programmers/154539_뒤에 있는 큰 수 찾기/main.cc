#include <iostream>
#include <string>
#include <vector>

using namespace std;

int find_first_large_number_index(const vector<int>& numbers, int start_index, int n) {
    for (int i = start_index; i < numbers.size(); i++) {
        if (numbers[i] > n) {
            return numbers[i];
        }
    }

    return -1;
}

vector<int> solution(vector<int> numbers) {
    vector<int> answer;

    for (int i = 0; i < numbers.size(); i++) {
        answer.push_back(find_first_large_number_index(numbers, i, numbers[i]));
    }
    return answer;
}

int main() {
    vector<int> numbers = { 9, 1, 5, 3, 6, 2 };

    vector<int> result = solution(numbers);

    for (int i : result) {
        cout << i << '\n';
    }

    return 0;
}