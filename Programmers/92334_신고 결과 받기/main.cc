#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <set>

using namespace std;

vector<string> split(string s, char delimiter) {
    vector<string> result;
    stringstream ss(s);
    string temp;

    while (getline(ss, temp, delimiter)) {
        result.push_back(temp);
    }

    return result;
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    unordered_map<string, int> user_list;
    unordered_map<string, set<string>> report_list;

    for (const string& s : report) {
        vector<string> users = split(s, ' ');
        report_list[users[1]].insert(users[0]);
    }

    for (auto mit = report_list.begin(); mit != report_list.end(); mit++) {
        set<string> s = mit->second;
        if (s.size() >= k) {
            for (auto sit = s.begin(); sit != s.end(); sit++) {
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