#include <iostream>
#include <string>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    for (char c : number) {
        while (!answer.empty() && k > 0 && answer.back() < c) {
            answer.pop_back();
            k--;
        }
        answer += c;
    }

    while (answer.size() > number.size() - k) {
        answer.pop_back();
    }

    return answer;
}

int main() { 
    string number = "77777";
    int k = 1;
    string answer = solution(number, k);
    cout << answer << '\n';
    return 0;
}