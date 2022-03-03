#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <numeric>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    vector<int> scores;
    int index = 0;
    int score = 0;
    for (char ch : dartResult) {
        if (isdigit(ch)) {
            score *= 10;
            score += ch - '0';
        } else if (isalpha(ch)) {
            if (ch == 'D') {
                score = pow(score, 2);
            } else if (ch == 'T') {
                score = pow(score, 3);
            }
            scores.push_back(score);
            index++;
            score = 0;
        } else if (ch == '*') {
            scores[index - 1] *= 2;
            if (index > 1) {
                scores[index - 2] *= 2;
            }
        } else if (ch == '#') {
            scores[index - 1] *= -1;
        }
    }

    answer = accumulate(scores.begin(), scores.end(), 0);

    return answer;
}

int main(void) {
    string dartResult = "1S2D*3T";
    int answer = solution(dartResult);
    cout << answer << '\n';
    return 0;
}