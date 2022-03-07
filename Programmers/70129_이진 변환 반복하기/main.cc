#include <iostream>
#include <string>
#include <vector>

using namespace std;

string n_to_binary_string(int n) {
    string s;

    while (n) {
        s += n % 2 + '0';
        n /= 2;
    }

    return s;
}

vector<int> solution(string s) {
    vector<int> answer(2, 0);

    while (s != "1") {
        for (auto it = s.begin(); it != s.end();) {
            if (*it == '0') {
                it = s.erase(it);
                answer[1]++;
            } else {
                it++;
            }
        }
        s = n_to_binary_string(s.size());
        answer[0]++;
    }

    return answer;
}

int main() {
    string s = "110010101001";
    vector<int> result = solution(s);
    
    for (int i : result) {
        cout << i << ' ';
    }
    cout << '\n';
    return 0;
}