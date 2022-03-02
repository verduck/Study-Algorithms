#include <iostream>
#include <string>

using namespace std;

bool solution(string s) {
    bool answer = true;

    if (s.size() != 4 && s.size() != 6) {
        return false;
    }

    for (char ch : s) {
        if (isalpha(ch)) {
            answer = false;
            break;
        }
    }

    return answer;
}

int main() {
    string s = "a234";
    bool result = solution(s);
    cout << boolalpha << result << '\n';
    return 0;
}