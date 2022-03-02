#include <iostream>
#include <string>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    for (char ch : s) {
        if (ch != ' ') {
            int m = 97;
            if (isupper(ch)) {
                m = 65;
            }
            ch = (static_cast<int>(ch) - m + n) % 26 + m;
        }
        answer += ch;
    }
    return answer;
}

int main() {
    string s = "AaZz";
    int n = 25;
    string result = solution(s, n);
    cout << result << '\n';
    return 0;
}