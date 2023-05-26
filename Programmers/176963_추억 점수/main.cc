#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    unordered_map<string, int> yearning_info;

    for (int i = 0; i < name.size(); i++) {
        yearning_info[name[i]] = yearning[i];
    }

    for (const vector<string>& v : photo) {
        int n = 0;

        for (const string& s : v) {
            n += yearning_info[s];
        }
        
        answer.push_back(n);
    }

    return answer;
}

int main() {
    vector<string> name = { "kali", "mari", "don" };
    vector<int> yearning = { 11, 1, 55 };
    vector<vector<string>> photo = { { "kali", "mari", "don" }, { "pony", "tom", "teddy" }, { "con", "mona", "don" } };
    vector<int> result = solution(name, yearning, photo);
    
    for (int i : result) {
        cout << i << '\n';
    }

    return 0;
}