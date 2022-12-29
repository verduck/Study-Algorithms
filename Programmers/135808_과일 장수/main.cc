#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int solution(int k, int m, vector<int> score) {
    int answer = 0;

    sort(score.begin(), score.end(), ::greater());
    int size = score.size() / m;

    for (int i = 0; i < size; i++) {
        auto it = score.begin() + i * m + m - 1;
        answer += *it * m;
    }
    
    return answer;
}

int main() {
    int k = 4;
    int m = 3;
    vector<int> score = { 4, 1, 2, 2, 4, 4, 4, 4, 1, 2, 4, 2 };

    int result = solution(k, m, score);
    cout << result << '\n';
    return 0;
}