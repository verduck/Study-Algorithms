#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n) {
    string answer = "";
    vector<char> v = { '4', '1', '2' };

    while (n) {
        int i = n % 3;
        answer += v[i];
        n /= 3;
        if (!i) {
            n--;
        }
    }

    reverse(answer.begin(), answer.end());
    return answer;
}

int main() {
    int n = 10;
    string result = solution(n);
    cout << result << '\n';
    return 0;
}