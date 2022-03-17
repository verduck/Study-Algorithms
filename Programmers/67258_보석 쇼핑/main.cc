#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer(2, 0);
    unordered_set<string> gs(gems.begin(), gems.end());
    unordered_map<string, int> display;
    auto l = gems.begin(), r = gems.begin();
    answer[0] = distance(gems.begin(), gems.begin()) + 1;
    answer[1] = distance(gems.begin(), gems.end());
    display[*r]++;
    while (l <= r && r != gems.end()) {
        if (display.size() == gs.size()) {
            if (answer[1] - answer[0] > distance(l, r)) {
                answer[0] = distance(gems.begin(), l) + 1;
                answer[1] = distance(gems.begin(), r) + 1;
            }
            display[*l]--;
            if (display[*l] == 0) {
                display.erase(*l);
            }
            l++;
        } else {
            if (++r != gems.end()) {
                display[*r]++;
            }
        }
    }
    return answer;
}

int main() {
    vector<string> gems = { "DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA" };
    vector<int> result = solution(gems);
    for (int i : result) {
        cout << i << ' ';
    }
    cout << '\n';
    return 0;
}