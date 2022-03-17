#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stack>

using namespace std;

string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    map<int, bool> table;
    map<int, bool>::iterator select;
    stack<int> removed;

    for (int i = 0; i < n; i++) {
        table.insert({ i, true });
    }

    select = table.find(k);

    for (const string& s : cmd) {
        char command = s[0];
        if (command == 'U') {
            int m = stoi(s.substr(2));
            for (int i = 0; i < m; i++) {
                select = prev(select);
            }
        } else if (command == 'D') {
            int m = stoi(s.substr(2));
            for (int i = 0; i < m; i++) {
                select = next(select);
            }
        } else if (command == 'C') {
            removed.push(select->first);
            select = table.erase(select);
            if (select == table.end()) {
                select--;
            }
        } else if (command == 'Z') {
            table.insert({ removed.top(), true });
            removed.pop();
        }
    }

    for (int i = 0; i < n; i++) {
        if (table[i]) {
            answer += "O";
        } else {
            answer += "X";
        }
    }
    return answer;
}

int main() {
    int n = 8;
    int k = 2;
    vector<string> cmd = { "D 2","C","U 3","C","D 4","C","U 2","Z","Z" };
    string result = solution(n, k, cmd);
    cout << result << '\n';
    return 0;
}
