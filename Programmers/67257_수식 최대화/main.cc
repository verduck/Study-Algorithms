#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long cal(long long n, long long m, char op) {
    if (op == '+') {
        return n + m;
    } else if (op == '-') {
        return n - m;
    } else if (op == '*') {
        return n * m;
    }
    
    return 0;
}

long long solution(string expression) {
    long long answer = 0;
    vector<char> op = { '*', '+', '-' };
    vector<long long> operands;
    vector<char> operators;
    string num_string;

    for (char c : expression) {
        if (isdigit(c)) {
            num_string += c;
        } else {
            operators.push_back(c);
            operands.push_back(stoll(num_string));
            num_string = "";
        }
    }
    operands.push_back(stoll(num_string));

    do {
        vector<long long> temp_operands = operands;
        vector<char> temp_operators = operators;

        for (int i = 0; i < op.size(); i++) {
            for (int j = 0; j < temp_operators.size(); j++) {
                if (temp_operators[j] == op[i]) {
                    temp_operands[j] = cal(temp_operands[j], temp_operands[j + 1], temp_operators[j]);
                    temp_operands.erase(temp_operands.begin() + j + 1);
                    temp_operators.erase(temp_operators.begin() + j--);
                }
            }
        }

        answer = max(answer, abs(temp_operands.front()));
    } while(next_permutation(op.begin(), op.end()));
    
    return answer;
}

int main() {
    string expression = "100-200*300-500+20";
    long long result = solution(expression);
    cout << result << '\n';
    return 0;
}