#include <iostream>
#include <string>

using namespace std;

string solution(string s) {
    string answer = "";
    int n = 0;

    for (char ch : s) {
        if (ch == ' ') {
            n = 0;
            answer += ch;
            continue;
        }
        if (n % 2) {
            answer += tolower(ch);
        } else {
            answer += toupper(ch);
        }
        n++;
    }

    return answer;
}

int main() {
    string s = "try hello world";
    string result = solution(s);
    cout << result << '\n';
    return 0;
}