#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string result;
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;

        while (i >= 0 || j >= 0 || carry == 1) {
            int n = i >= 0 ? a[i--] - '0' : 0;
            int m = j >= 0 ? b[j--] - '0' : 0;

            result.insert(0, to_string((n + m + carry) % 2));
            carry = (n + m + carry) / 2;
        }

        return result;
    }
};

void init();

int main() {
    string a = "11";
    string b = "1";

    init();

    Solution solution;
    string result = solution.addBinary(a, b);

    cout << result << '\n';
}

void init() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}