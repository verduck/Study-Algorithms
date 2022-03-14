#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

vector<string> split(const string& s, char delimiter) {
    vector<string> result;
    stringstream ss(s);
    string part;

    while(getline(ss, part, delimiter)) {
        result.push_back(part);
    }

    return result;
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<vector<string>> records;
    unordered_map<string, string> nickname;

    for (const string& s : record) {
        vector<string> v = split(s, ' ');
        records.push_back(v);
        if (v[0] == "Enter" || v[0] == "Change") {
            nickname[v[1]] = v[2];
        }
    }

    for (const vector<string>& v : records) {
        if (v[0] == "Enter") {
            answer.push_back(nickname[v[1]] + "님이 들어왔습니다.");
        } else if (v[0] == "Leave") {
            answer.push_back(nickname[v[1]] + "님이 나갔습니다.");
        }
    }
    return answer;
}

int main() { 
    vector<string> record = {};
    vector<string> result = solution(record);
    for (const string& s : result) {
        cout << s << '\n';
    }
    return 0;
}