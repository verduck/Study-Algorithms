#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    int n = p.size();

    for (int i = 0; i <= t.size() - n; i++) {
        string s = t.substr(i, n);
        if (s <= p) {
            answer++;
        }
    }
    return answer;
}

int main() {
    string t = "10203";
    string p = "15";
    int result = solution(t, p);
    cout << result << '\n';
    return 0;
}