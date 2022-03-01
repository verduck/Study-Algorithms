#include <iostream>
#include <string>

using namespace std;

string solution(int num) {
    string answer = num % 2 ? "Odd" : "Even";
    return answer;
}

int main() {
    int num = 3;
    string result = solution(num);

    cout << result << '\n';
    return 0;
}