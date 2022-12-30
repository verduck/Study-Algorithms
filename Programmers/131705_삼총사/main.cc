#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> number) {
    int answer = 0;
    vector<bool> mask(number.size(), false);
    for (int i = 0; i < 3; i++) {
        mask[i] = true;
    }

    do {
        int n = 0;
        for (int i = 0; i < number.size(); i++) {
            if (mask[i]) {
                n += number[i];
            }
        }

        if (n == 0) {
            answer++;
        }
    } while (prev_permutation(mask.begin(), mask.end()));

    return answer;
}

int main() {
    vector<int> number = { -3, -2, -1, 0, 1, 2, 3 };
    int result = solution(number);
    cout << result << '\n';
    return 0;
}