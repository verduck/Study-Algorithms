#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

bool check(const queue<string>& q, const string& s) {
    return !q.empty() && q.front() == s;
}

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "Yes";
    queue<string> qcard1(deque<string>(cards1.begin(), cards1.end()));
    queue<string> qcard2(deque<string>(cards2.begin(), cards2.end()));

    for (const string& s : goal) {
        if (check(qcard1, s)) {
            qcard1.pop();
        } else if (check(qcard2, s)) {
            qcard2.pop();
        } else {
            answer = "No";
            break;
        }
    }

    return answer;
}

int main() {
    vector<string> cards1 = { "i", "drink", "water" };
    vector<string> cards2 = { "want", "to" };
    vector<string> goal = { "i", "want", "to", "drink", "water" };

    string result = solution(cards1, cards2, goal);
    
    cout << result << '\n';
    return 0;
}