#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<vector<int>> patterns = {
      { 1, 2, 3, 4, 5 },
      { 2, 1, 2, 3, 2, 4, 2, 5 },
      { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 }  
    };
    vector<int> v(patterns.size(), 0);

    for (int i = 0; i < answers.size(); i++) {
        for (int j = 0; j < patterns.size(); j++) {
            if (answers[i] == patterns[j][i % patterns[j].size()]) {
                v[j]++;
            }
        }
    }

    int max_it = *max_element(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++) {
        if (v[i] == max_it) {
            answer.push_back(i + 1);
        }
    }

    return answer;
}

int main() {
    vector<int> answers = { 1, 3, 2, 4, 2 };
    vector<int> answer = solution(answers);
    for (int i : answer) {
        cout << i << ' ';
    }
    cout << '\n';
    return 0;
}