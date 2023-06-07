#include <iostream>
#include <string>
#include <vector>

using namespace std;

char convert(char ch, const string& skip, int index) {
    for (int i = 0; i < index; i++) {
        ch++;
        ch = (ch - 97) % 26 + 97;
        if (skip.find(ch) != string::npos) {
            i--;
        }
    }

    return ch;
}

string solution(string s, string skip, int index) {
    string answer = "";

    for (const char ch : s) {
        answer += convert(ch, skip, index);
    }

    return answer;
}

int main() {
    string s = "ybcde";
    string skip = "az";
    int index = 1;

    string result = solution(s, skip, index);
    
    cout << result << '\n';

    return 0;
}