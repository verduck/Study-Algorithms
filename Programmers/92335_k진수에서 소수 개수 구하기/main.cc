#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> split(string s, char delimiter) {
    vector<string> answer;
    stringstream ss(s);
    string temp;

    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }

    return answer;
}

string n_to_string(int n, int m) {
    string result;
    vector<char> v{ '0','1','2','3','4','5','6','7','8','9' };

    if (m == 0) {
        return string(1, v[0]);
    }

    while (m != 0) {
        result = v[m % n] + result;
        m /= n;
    }

    return result;
}

bool is_prime_number(long n) {
    if (n <= 1) {
        return false;
    }

    for (long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int solution(int n, int k) {
    int answer = -1;
    string str;
    if (k != 10) {
        str = n_to_string(k, n);
    }
    else {
        str = to_string(n);
    }
    vector<string> nums = split(str, '0');

    for (const string& s : nums) {
        if (!s.empty()) {
            long m = stol(s);
            if (is_prime_number(m)) {
                answer++;
            }
        }
    }

    answer++;
    return answer;
}

int main() {
    int n = 437674;
    int k = 3;
    int result = solution(n, k);
    cout << result << "\n";
    return 0;
}