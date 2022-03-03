#include <iostream>
#include <string>

using namespace std;

string solution(string s) {
    string answer;
    if (s.size() % 2) {
        answer = s.substr(s.size() / 2, 1);
    } else {
        answer = s.substr(s.size() / 2 - 1, 2);
    }
    return answer;
}

int main() {
    string s = "qwer";
    string answer = solution(s);
    cout << answer << '\n';
    return 0;
}