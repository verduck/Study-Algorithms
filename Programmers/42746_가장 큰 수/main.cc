#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> strings;

    transform(numbers.begin(), numbers.end(), inserter(strings, strings.begin()), [](int i) -> string {
        return to_string(i);
    });

    sort(strings.begin(), strings.end(), [](const string& left, const string& right) -> bool {
        string lr = left + right;
        string rl = right + left;
        return lr > rl;
    });

    answer = accumulate(strings.begin(), strings.end(), string());

    if (answer[0] == '0') {
        answer = "0";
    }

    return answer;
}

int main() {
    vector<int> numbers = { 3, 0, 6, 1, 5 };
    string answer = solution(numbers);
    cout << answer << '\n';
    return 0;
}