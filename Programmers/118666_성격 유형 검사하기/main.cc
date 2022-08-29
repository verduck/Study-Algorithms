#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    unordered_map<char, int> result;
    vector<vector<char>> indicators = {
        { 'R', 'T' },
        { 'C', 'F' },
        { 'J', 'M' },
        { 'A', 'N' }
    };

    for (int i = 0; i < survey.size(); i++) {
        if (choices[i] < 4) {
            result[survey[i][0]] += 4 - choices[i];
        } else if (choices[i] > 4) {
            result[survey[i][1]] += choices[i] - 4;
        }
    }

    for (int i = 0; i < indicators.size(); i++) {
        char type1 = indicators[i][0];
        char type2 = indicators[i][1];
        if (result[type1] >= result[type2]) {
            answer += type1;
        } else {
            answer += type2;
        }
    }

    return answer;
}

int main() {
    vector<string> survey = { "AN", "CF", "MJ", "RT", "NA" };
    vector<int> choices = { 5, 3, 2, 7, 5 };
    string result = solution(survey, choices);
    cout << result << '\n';
    return 0;
}