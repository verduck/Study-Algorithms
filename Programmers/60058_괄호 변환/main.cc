#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool check(const string& s) {
    int st = 0;

    for (char c : s) {
        if (c == '(') {
            st++;
        } else {
            if (!st) {
                return false;
            } else {
                st--;
            }
        }
    }

    return true;
}

string solution(string p) {
    string answer = "";
    int open = 0;
    int close = 0;

    string u, v;

    if (p.empty()) {
        return p;
    }

    for (int i = 0; i < p.size(); i++) {
        if (p[i] == '(') {
            open++;
        } else if (p[i] == ')') {
            close++;
        }
        if (open == close) {
            u = p.substr(0, i + 1);
            v = p.substr(i + 1, p.size());
            break;
        }
    }

    if (check(u)) {
        return u + solution(v);
    }

    answer = "(" + solution(v) + ")";
    transform(u.begin(), u.end(), u.begin(), [](char c) -> char {
        if (c == '(') {
            return ')';
        } else {
            return '(';
        }
    });
    answer += u.substr(1, u.size() - 2);
    return answer;
}

int main() {
    string p = "()))((()";
    string result = solution(p);
    cout << result << '\n';
    return 0;
}