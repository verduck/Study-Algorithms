#include <iostream>
#include <string>

using namespace std;

bool solution(string s) {
    bool answer = true;
    int p = 0;
    int y = 0;

    for (char ch : s) {
        if (ch == 'P' || ch == 'p') {
            p++;
        } else if (ch == 'Y' || ch == 'y') {
            y++;
        }
    }

    answer = p == y;

    return answer;
}

int main() {
    string s = "Zbcdefg";
    bool result = solution(s);
    cout << boolalpha << result << '\n';
    return 0;
}