#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer(2, 0);
    vector<int> dpq;
    for (const string& s : operations) {
        char c = s[0];
        int n = stoi(s.substr(2));
        if (c == 'I') {
            dpq.push_back(n);
        } else if (c == 'D' && !dpq.empty()) {
            if (n == 1) {
                make_heap(dpq.begin(), dpq.end());
            } else if (n == -1) {
                make_heap(dpq.begin(), dpq.end(), greater<>());
            }
            pop_heap(dpq.begin(), dpq.end());
            dpq.pop_back();
        }
    }

    if (!dpq.empty()) {
        auto p = minmax_element(dpq.begin(), dpq.end());
        answer[0] = *p.second;
        answer[1] = *p.first;
    }
    return answer;
}

int main() {
    vector<string> operations = { "I 16", "I -5643", "D -1", "D 1", "D 1", "I 123", "D -1" };
    vector<int> result = solution(operations);
    for (int i : result) {
        cout << i << ' ';
    }
    cout << '\n';
    return 0;
}