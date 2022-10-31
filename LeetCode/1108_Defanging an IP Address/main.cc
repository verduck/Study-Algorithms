#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string defangIPaddr(string address) {
        string answer;

        for (char ch: address) {
            if (ch == '.') {
                answer += "[.]";
            } else {
                answer += ch;
            }
        }

        return answer;
    }
};

void init();

int main() {
    string address = "1.1.1.1";

    init();

    Solution solution;
    string result = solution.defangIPaddr(address);

    cout << result << '\n';
}

void init() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}