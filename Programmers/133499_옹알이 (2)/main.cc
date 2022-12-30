#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

bool check(const string& s) {
    unordered_set<string> bases = { "aya", "ye", "woo", "ma" };
    string prev;
    string temp;

    for (int i = 0; i < s.size(); i++) {
        temp += s[i];
        if (bases.find(temp) != bases.end()) {
            if (prev != temp) {
                prev = temp;
                temp = "";
            } else {
                return false;
            }
        }

        if (temp.size() >= 3) {
            return false;
        }
    }

    if (temp == "") {
        return true;
    } else {
        return bases.find(temp) != bases.end();
    }
}

int solution(vector<string> babbling) {
    int answer = 0;
    
    for (const string& s : babbling) {
        if (check(s)) {
            answer++;
        }
    }

    return answer;
}

int main() {
    vector<string> babbling = { "ayaye", "uuu", "yeye", "yemawoo", "ayaayaa" };
    int result = solution(babbling);
    cout << result << '\n';
    return 0;
}