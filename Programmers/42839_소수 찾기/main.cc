#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

bool is_prime_number(int n) {
    if (n < 2) {
        return false;
    }

    for (int i = 2; i * i <= n; i++) {
        if (!(n % i)) {
            return false;
        }
    }

    return true;
}

void dfs(const string& numbers, string s, vector<bool>& visited, set<int>& prime_numbers) {
    if (s.size() > numbers.size()) {
        return;
    }

    if (!s.empty()) {
        int n = stoi(s);
        if (is_prime_number(n)) {
            prime_numbers.insert(n);
        }
    }

    for (int i = 0; i < numbers.size(); i++) {
        if (!visited[i]) {
            visited[i] = true;
            dfs(numbers, s + numbers[i], visited, prime_numbers);
            visited[i] = false;
        }
    }
}

int solution(string numbers) {
    int answer = 0;
    set<int> prime_numbers;
    vector<bool> visited(numbers.size(), false);

    dfs(numbers, string(), visited, prime_numbers);
    answer = prime_numbers.size();

    return answer;
}

int main() {
    string numbers = "17";
    int answer = solution(numbers);
    cout << answer << '\n';
    return 0;
}