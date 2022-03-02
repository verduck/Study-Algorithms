#include <iostream>
#include <string>

using namespace std;

string solution(int n) {
    string answer = "";
    for (int i = 0; i < n; i++) {
        if (i % 2) {
            answer += "박";
        } else {
            answer += "수";
        }
    }
    return answer;
}

int main() {
    int n = 4;
    string result = solution(n);
    cout << result << '\n';
    return 0;
}