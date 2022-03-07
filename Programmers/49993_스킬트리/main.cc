#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;

    for (const string& s : skill_trees) {
        int index = 0;
        bool success = true;
        for (char c : s) {
            int f = skill.find(c);
            if (f != string::npos) {
                if (f <= index) {
                    index++;
                } else {
                    success = false;
                    break;
                }
            }
        }
        if (success) {
            answer++;
        }
    }
    return answer;
}

int main() {
    string skill = "CBD";
    vector<string> skill_trees = { "BACDE", "CBADF", "AECB", "BDA" };
    int result = solution(skill, skill_trees);
    cout << result << '\n';
    return 0;
}