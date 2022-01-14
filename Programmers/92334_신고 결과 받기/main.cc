#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <set>

using namespace std;

vector<string> split(string s, char delimiter) {
    vector<string> answer;
    stringstream ss(s);
    string temp;

    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }

    return answer;
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    unordered_map<string, int> user_list;
    unordered_map<string, set<string>> logs;

    for (const string& s : id_list) {
        user_list.insert({ s, 0 });
    }

    for (const string& s : report) {
        vector<string> sp = split(s, ' ');
        logs[sp[1]].insert(sp[0]);
    }
    
    for (auto it = logs.begin(); it != logs.end(); it++) {
        set<string> report_list = it->second;
        if (report_list.size() >= k) {
            for (auto sit = report_list.begin(); sit != report_list.end(); sit++) {
                user_list[*sit]++;
            }
        }
    }
    
    for (const string& s : id_list) {
        answer.push_back(user_list[s]);
    }

    return answer;
}

int main() {
  vector<string> id_list = { "muzi", "frodo", "apeach", "neo" };
  vector<string> report = { "muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi" };
  int k = 2;
  vector<int> result = solution(id_list, report, k);

  for (int i : result) {
      cout << i << " ";
  }
  return 0;
}