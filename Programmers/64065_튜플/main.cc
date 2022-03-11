#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

vector<int> split(string str, char delimiter) {
  vector<int> result;
  stringstream ss(str);
  string part;

  while (getline(ss, part, delimiter)) {
    result.push_back(stoi(part));
  }

  return result;
}

vector<int> solution(string s) {
    vector<int> answer;
    vector<vector<int>> elements;

    for (auto it = s.begin() + 1; it != s.end() - 1; it++) {
        if (*it == '{') {
            string temp;
            while(*(++it) != '}') {
                temp += *it;
            }
            vector<int> v = split(temp, ',');
            elements.push_back(v);
        }
    }

    sort(elements.begin(), elements.end(), [](const vector<int>& left, const vector<int>& right) -> bool {
        return left.size() < right.size();
    });

    for (const vector<int>& v : elements) {
        for (int i : v) {
            auto it = find(answer.begin(), answer.end(), i);
            if (it == answer.end()) {
                answer.push_back(i);
            }
        }
    }
    return answer;
}

int main() {
    string s = "";
    vector<int> result = solution(s);
    for (int i : result) {
        cout << i << ' ';
    }
    cout << '\n';
    return 0;
}