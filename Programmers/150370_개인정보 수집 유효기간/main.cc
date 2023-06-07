#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> split(const string& s, char delim) {
    vector<string> result;
    stringstream ss(s);
    string temp;

    while (getline(ss, temp, delim)) {
        result.push_back(temp);
    }

    return result;
}

long date2days(const string& date) {
    vector<string> d = split(date, '.');

    int year = stoi(d[0]);
    int month = stoi(d[1]);
    int day = stoi(d[2]);

    return year * 12 * 28 + month * 28 + day;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    vector<int> t('Z' - 'A' + 1, 0);
    long today_days = date2days(today);

    for (const string& s : terms) {
        t[s[0] - 'A'] = stoi(s.substr(1)) * 28;
    }

    for (int i = 0; i < privacies.size(); i++) {
        const string& privacy = privacies[i];
        long days = date2days(privacy.substr(0, 10));
        int type = privacy[11] - 'A';

        if (days + t[type] <= today_days) {
            answer.push_back(i + 1);
        }
    }

    return answer;
}

int main() {
    string today = "2020.01.01";
    vector<string> terms = { "Z 3", "D 5" };
    vector<string> privacies = { "2019.01.01 D", "2019.11.15 Z", "2019.08.02 D", "2019.07.01 D", "2018.12.28 Z" };

    vector<int> result = solution(today, terms, privacies);

    for (const int& i : result) {
        cout << i << "\n";
    }
    return 0;
}