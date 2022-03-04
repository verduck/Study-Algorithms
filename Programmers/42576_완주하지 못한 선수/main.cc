#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    vector<string> diff;
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    set_difference(participant.begin(), participant.end(), completion.begin(), completion.end(), inserter(diff, diff.begin()));
    answer = diff[0];
    return answer;
}

int main() {
    vector<string> participant = { "leo", "kiki", "eden" };
    vector<string> completion = { "eden", "kiki" };
    string answer = solution(participant, completion);
    cout << answer << '\n';
    return 0;
}