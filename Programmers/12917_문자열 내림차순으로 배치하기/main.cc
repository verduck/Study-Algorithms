#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = s;
    sort(answer.begin(), answer.end(), greater<>());
    return answer;
}

int main() {
    string s = "Zbcdefg";
    string result = solution(s);
    cout << result << '\n';
    return 0;
}