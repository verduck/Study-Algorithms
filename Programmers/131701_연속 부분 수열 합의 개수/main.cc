#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    unordered_set<int> us;

    for (int i = 0; i < elements.size(); i++) {
        for (int j = 0; j < elements.size(); j++) {
            int n = elements[j];
            for (int k = j + 1; k < j + 1 + i; k++) {
                n += elements[k % elements.size()];
            }
            us.insert(n);
        }
    }
    answer = us.size();

    return answer;
}

int main() {
    vector<int> order = { 7,9,1,1,4 };
    int result = solution(order);
    cout << result << '\n';
    return 0;
}