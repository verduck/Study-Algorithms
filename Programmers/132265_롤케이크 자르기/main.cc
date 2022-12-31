#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    unordered_map<int, int> me;
    unordered_map<int, int> bro;

    for (int i : topping) {
        me[i]++;
    }

    for (int i : topping) {
        me[i]--;
        if (me[i] == 0) {
            me.erase(i);
        }
        bro[i]++;
        if (me.size() == bro.size()) {
            answer++;
        }
    }

    return answer;
}

int main() {
    vector<int> topping = { 1, 2, 1, 3, 1, 4, 1, 2 };
    int result = solution(topping);
    cout << result << '\n';
    return 0;
}