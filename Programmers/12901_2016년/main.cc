#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    vector<int> last_days = { 31, 29, 31, 30, 31,30, 31, 31, 30, 31, 30, 31 };
    vector<string> weeks = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
    int days = 0;

    for (int i = 0; i < a - 1; i++) {
        days += last_days[i];
    }

    days += b;

    answer = weeks[(4 + (days % 7)) % 7];

    return answer;
}

int main() {
    int a = 12;
    int b = 31;
    string answer = solution(a, b);
    cout << answer << '\n';
    return 0;
}