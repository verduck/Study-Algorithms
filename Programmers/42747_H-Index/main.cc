#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end());

    for (int i = 0; i < citations.size(); i++) {
        if (citations[i] >= citations.size() - i) {
            answer = citations.size() - i;
            break;
        }
    }

    return answer;
}

int main() {
    vector<int> citations = { 3, 0, 6, 1, 5 };
    int answer = solution(citations);
    cout << answer << '\n';
    return 0;
}