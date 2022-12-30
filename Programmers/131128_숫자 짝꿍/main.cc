#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    sort(X.begin(), X.end(), greater<>());
    sort(Y.begin(), Y.end(), greater<>());

    int i = 0;
    int j = 0;
    while (i < X.size() && j < Y.size()) {
        if (X[i] == Y[j]) {
            answer += X[i];
            i++; j++;
        } else if (X[i] > Y[j]) {
            i++;
        } else {
            j++;
        }
    }

    if (answer.empty()) {
        answer = "-1";
    } else if (answer[0] == '0') {
        answer = "0";
    }

    return answer;
}

int main() {
    string X = "100";
    string Y = "203045";
    string result = solution(X, Y);
    cout << result << '\n';
    return 0;
}