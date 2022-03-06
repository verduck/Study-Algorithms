#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string n_to_string(int n, int k) {
    string s;
    vector<char> v = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };

    if (n == 0) {
        return "0";
    }

    while (n) {
        s += v[n % k];
        n /= k;
    }
    reverse(s.begin(), s.end());

    return s;
}

string solution(int n, int t, int m, int p) {
    string answer = "";

    int i = 0;
    int turn = 0;
    while (answer.size() < t) {
        string s = n_to_string(i++, n);
        for (int j = 0; j < s.size(); j++) {
            if (answer.size() == t) {
                break;
            }
            if (turn == p - 1) {
                answer += s[j];
            }

            turn = (turn + 1) % m;
        }
    }
    return answer;
}

int main() {
    int n = 2;
    int t = 4;
    int m = 2;
    int p = 1;
    string result = solution(n, t, m, p);
    cout << result << '\n';
    return 0;
}