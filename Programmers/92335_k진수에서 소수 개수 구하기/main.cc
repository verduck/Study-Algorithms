#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

vector<string> split(string s, char delimiter) {
    vector<string> result;
    stringstream ss(s);
    string temp;

    while (getline(ss, temp, delimiter)) {
        result.push_back(temp);
    }

    return result;
}

string n_to_string(int n, int k) {
    string s;

    while (n) {
        s += (n % k) + '0';
        n /= k;
    }
    reverse(s.begin(), s.end());

    return s;
}

bool isPrimeNum(long n) {
    if (n <= 1) {
        return false;
    }

    for (long i = 2; i * i <= n; i++) {
        if (!(n % i)) {
            return false;
        }
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;

    string kstring = n_to_string(n, k);

    vector<string> v = split(kstring, '0');

    for (const string& s : v) {
        if (!s.empty()) {
            long m = stol(s);
            if (isPrimeNum(m)) {
                answer++;
            }
        }
    }

    return answer;
}

int main() {
    int n = 110011;
    int k = 10;
    int result = solution(n, k);
    cout << result << "\n";
    return 0;
}