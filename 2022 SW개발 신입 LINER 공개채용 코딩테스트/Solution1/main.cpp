#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <algorithm>

using namespace std;

int solution1(vector<string> logs) {
    int answer = 0;
    regex re("team_name : [a-zA-Z]* application_name : [a-zA-Z]* error_level : [a-zA-Z]* message : [a-zA-Z]*");
    for (const string& log : logs) {
        if (!regex_match(log, re)) {
            answer++;
        }
    }

    return answer;
}

int solution2(vector<string> logs) {
    int answer = 0;
    

    for (const string& log : logs) {
        if (log.size() <= 100) {
            string temp = log;

            for (int i = 0; i < 4; i++) {
                size_t delimiter_pos = temp.find(" : ");
                string key = temp.substr(0, delimiter_pos);
                temp = temp.substr(delimiter_pos + 3);

                if (key != "team_name" && key != "application_name" && key != "error_level" && key != "message") {
                    cout << log << '\n';
                    answer++;
                    break;
                }

                delimiter_pos = temp.find(' ');
                string value = temp.substr(0, delimiter_pos);
                temp = temp.substr(delimiter_pos + 1);
                int n = count_if(value.begin(), value.end(), [](char c) -> bool {
                    return !isalpha(c);
                });
                if (n > 0) {
                    cout << log << '\n';
                    answer++;
                    break;
                }
            }
        } else {
            answer++;
        }
    }
    return answer;
}

int main() {
    vector<string> logs = { "team_name : MyTeam application_name : YourApp error_level : info messag : IndexOutOfRange",
        "no such file or directory",
        "team_name : recommend application_name : recommend error_level : info message : RecommendSucces11",
        "team_name : recommend application_name : recommend error_level : info message : Success!",
        "   team_name : db application_name : dbtest error_level : info message : test",
        "team_name     : db application_name : dbtest error_level : info message : test",
        "team_name : TeamTest application_name : TestApplication error_level : info message : ThereIsNoError"
    };
    int result = solution1(logs);
    cout << result << '\n';
	return 0;
}