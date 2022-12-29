#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    string s = "";
    for (int i = 1; i < food.size(); i++) {
        s += string(food[i] / 2, i + 48);
    }

    answer = s + "0";
    reverse(s.begin(), s.end());
    answer += s;

    return answer;
}

int main() {
    vector<int> food = { 1, 3, 4, 6 };
    string result = solution(food);
    cout << result << '\n';
    return 0;
}