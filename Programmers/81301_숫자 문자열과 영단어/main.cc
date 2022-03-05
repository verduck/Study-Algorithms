#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(string s) {
    int answer = 0;
    unordered_map<string ,char> text_digit = {
        { "zero", 0 },
        { "one", 1 },
        { "two", 2 },
        { "three", 3 },
        { "four", 4 },
        { "five", 5 },
        { "six", 6 },
        { "seven" , 7 },
        { "eight", 8 },
        { "nine", 9 } 
    };
    string temp;

    for (char ch : s) {
        if(isdigit(ch)) {
            answer *= 10;
            answer += ch - '0';
        } else {
            temp += ch;
            auto it = text_digit.find(temp);
            if (it != text_digit.end()) {
                answer *= 10;
                answer += it->second;
                temp = "";
            }
        }
    }
    
    return answer;
}

int main() {
    string s = "one4seveneight";
    int answer = solution(s);
    cout << answer << '\n';
    return 0;
}