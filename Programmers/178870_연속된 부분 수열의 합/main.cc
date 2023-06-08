#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer(2);
    answer[0] = 0;
    answer[1] = sequence.size() - 1;
    int left = 0;
    int right = 0;
    int sum = 0;

    while (right < sequence.size()) {
        if (sum <= k) {
            if (sum == k) {
                if (answer[1] - answer[0] > right - 1 - left) {
                    answer[0] = left;
                    answer[1] = right - 1;
                }
            }
            sum += sequence[right++];
        } else if (sum > k) {
            sum -= sequence[left++];
        }
    }

    while (left < right) {
        sum -= sequence[left++];
        if (sum == k) {
            if (answer[1] - answer[0] > right - 1- left) {
                answer[0] = left;
                answer[1] = right - 1;
            }
        }
    }

    return answer;
}

int main() {
    vector<int> sequence = { 1, 1, 1, 2, 3, 4, 5 };
    int k = 5;
    
    vector<int> result = solution(sequence, k);

    for (int i : result) {
        cout << i << '\n';
    }

    return 0;
}