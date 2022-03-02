#include <iostream>
#include <string>

using namespace std;

int solution(string s) {
    int answer = stoi(s);
    return answer;
}

int main() {
    string s = "-1234";
    int result = solution(s);
    cout << result << '\n';
    return 0;
}