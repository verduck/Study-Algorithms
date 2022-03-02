#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "";
    stringstream ss;
    vector<string>::iterator it = find(seoul.begin(), seoul.end(), "Kim");
    ss << "김서방은 " << distance(seoul.begin(), it) << "에 있다";
    answer = ss.str();
    return answer;
}

int main() {
    vector<string> seoul = { "Jane", "Kim" };
    string result = solution(seoul);
    cout << result << '\n';
    return 0;
}