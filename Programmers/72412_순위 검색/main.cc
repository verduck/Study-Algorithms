#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <algorithm>

using namespace std;

size_t replace_all(string& inout, string_view what, string_view with) {
    size_t count{};
    for (string::size_type pos{};
        inout.npos != (pos = inout.find(what.data(), pos, what.length()));
        pos += with.length(), ++count) {
            inout.replace(pos, what.length(), with.data(), with.length());
    }
    return count;
}

vector<string> split(const string& s, char delimiter) {
    vector<string> result;
    stringstream ss(s);
    string part;

    while (getline(ss, part, delimiter)) {
        result.push_back(part);
    }

    return result;
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    unordered_map<string, vector<int>> table;

    for (const string& s : info) {
        vector<string> v = split(s, ' ');
        int score = stoi(v.back());
        v.pop_back();
        for (int i = 0; i < (1 << v.size()); i++) {
            string t;
            for (int j = 0; j < v.size(); j++) {
                if (i & (1 << j)) {
                    t += "- ";
                } else {
                    t += v[j] + " ";
                }
            }
            t.pop_back();
            table[t].push_back(score);
        }
    }

    for (auto it = table.begin(); it != table.end(); it++) {
        sort(it->second.begin(), it->second.end());
    }

    for (string s : query) {
        replace_all(s, " and ", " ");
        string info = s.substr(0, s.rfind(' '));
        int score = stoi(s.substr(s.rfind(' ') + 1));

        vector<int> v = table[info];
        auto it = lower_bound(v.begin(), v.end(), score);
        answer.push_back(distance(it, v.end()));
    }
    return answer;
}

int main() {
    vector<string> info = { "java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50" };
    vector<string> query = { "java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150" };
    vector<int> result = solution(info, query);
    for (int i : result) {
        cout << i << ' ';
    }
    cout << '\n';
    return 0;
}