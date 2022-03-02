#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer = strings;

    sort(answer.begin(), answer.end(), [&](const string& left, const string& right) {
        if (left[n] == right[n]) {
            return left < right;
        }
        return left[n] < right[n];
    });
    return answer;
}

int main() {
    vector<string> strings = {"sun", "bed", "car"};
    int n = 1;
    vector<string> result = solution(strings, n);
    for (const string& s : result) {
        cout << s << ' ';
    }
    cout << '\n';
    return 0;
}