#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int solution(string s) {
    int answer = s.size();
    for (int i = 1; i <= s.size(); i++) {
        string compressed;
        string prev = s.substr(0, i);
        int count = 1;
        for (int j = i; j < s.size(); j += i) {
            string temp = s.substr(j, i);
            if (temp == prev) {
                count++;
            } else {
                if (count > 1) {
                    compressed += to_string(count);
                }
                compressed += prev;
                count = 1;
                prev = temp;
            }
        }
        if (count > 1) {
            compressed += to_string(count);
        }
        compressed += prev;
        answer = min(answer, static_cast<int>(compressed.size()));
    }
    
    return answer;
}

int main() {
    string s = "aabbaccc";
    int result = solution(s);
    cout << result << '\n';
    return 0;
}