#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    for (const string& skill_tree : skill_trees) {
        int index = 0;
        bool success = true;
        for (const char ch : skill_tree) {
            int f = skill.find(ch);
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