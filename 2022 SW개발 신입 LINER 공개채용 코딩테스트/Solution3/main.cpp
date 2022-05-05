#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<string> split(const string& s, char delimiter) {
    vector<string> result;
    stringstream ss(s);
    string part;

    while (getline(ss, part, delimiter)) {
        result.push_back(part);
    }

    return result;
}

vector<int> solution(int num_teams, vector<string> remote_tasks, vector<string> office_tasks, vector<string> employees) {
    vector<int> answer;
    unordered_map<int, unordered_map<int, bool>> teams;
    for (int i = 0; i < employees.size(); i++) {
        vector<string> info = split(employees[i], ' ');
        int team = stoi(info[0]);
        bool flag = true;
        for (int j = 1; j < info.size(); j++) {
            if (find(office_tasks.begin(), office_tasks.end(), info[j]) != office_tasks.end()) {
                flag = false;
                break;
            }
        }
        teams[team][i + 1] = flag;
    }

    for (auto it = teams.begin(); it != teams.end(); it++) {
        bool flag = true;
        int n = employees.size();
        for (auto eit = it->second.begin(); eit != it->second.end(); eit++) {
            if (eit->second) {
                n = min(n, eit->first);
                answer.push_back(eit->first);
            } else {
                flag = false;
            }
        }
        if (flag) {
            answer.erase(remove(answer.begin(), answer.end(), n), answer.end());
        }
    }

    sort(answer.begin(), answer.end());
    return answer;
}

int main() {
    int num_teams = 3;
    vector<string> remote_tasks = { "development","marketing","hometask" };
    vector<string> office_tasks = { "recruitment","education","officetask" };
    vector<string> employees = { "1 development hometask","1 recruitment marketing","2 hometask","2 development marketing hometask","3 marketing","3 officetask","3 development" };
    vector<int> result = solution(num_teams, remote_tasks, office_tasks, employees);
    for (int i : result) {
        cout << i << ' ';
    }
    cout << '\n';
	return 0;
}