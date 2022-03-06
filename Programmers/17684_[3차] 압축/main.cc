#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    unordered_map<string, int> dict;
    int index = 27;

    for (char c = 'A'; c <= 'Z'; c++) {
        dict[string(1, c)] = c - 'A' + 1;
    }

    for (int i = 0; i < msg.size(); i++) {
        int j = 0;

        while(i + j <= msg.size() && dict.find(msg.substr(i, ++j)) != dict.end());
        string w = msg.substr(i, --j);
        char c = msg[i + j];
        answer.push_back(dict[w]);
        w += c;
        dict[w] = index++;
        i += j - 1;
    }
    
    return answer;
}

int main() {
    string msg = "KAKAO";
    vector<int> answer = solution(msg);
    for (int i : answer) {
        cout << i << ' ';
    }
    cout << '\n';
    return 0;
}