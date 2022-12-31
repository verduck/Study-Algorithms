#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

void init_map(unordered_map<string, int>& m, const vector<string>& want, const vector<int>& number) {
    for (int i = 0; i < want.size(); i++) {
        m[want[i]] = number[i];
    }
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    unordered_map<string, int> m;

    for (int i = 0; i <= discount.size() - 10; i++) {
        init_map(m, want, number);
        for (int j = i; j < i + 10; j++) {
            if (m.find(discount[j]) != m.end()) {
                m[discount[j]]--;
            }
        }

        bool flag = true;
        for (auto it = m.begin(); it != m.end(); it++) {
            if (it->second > 0) {
                flag = false;
                break;
            }
        }

        if (flag) {
            answer++;
        }
    }

    return answer;
}

int main() {
    vector<string> want = { "banana", "apple", "rice", "pork", "pot" };
    vector<int> number = { 3, 2, 2, 2, 1 };
    vector<string> discount = { "chicken", "apple", "apple", "banana", "rice", "apple", "pork", "banana", "pork", "rice", "pot", "banana", "apple", "banana" };
    int result = solution(want, number, discount);
    cout << result << '\n';
    return 0;
}