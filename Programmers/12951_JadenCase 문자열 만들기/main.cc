#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    bool is_first = true;
    for (int i = 0; i < s.size(); i++) {
        if (is_first) {
            answer += toupper(s[i]); 
        } else {
            answer += tolower(s[i]);
        }

        is_first = false;
        if (s[i] == ' ') {
            is_first = true;
        }
    }
    return answer;
}

int main() {
    string s = "3PeoPle unFollowed me";
    string result = solution(s);
    cout << result << '\n';
    return 0;
}