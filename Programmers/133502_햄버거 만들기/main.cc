#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    const vector<int> hamburger = { 1, 2, 3, 1 };
    vector<int> v;
    
    for (int i : ingredient) {
        v.push_back(i);
        if (v.size() >= 4) {
            vector<int> temp(v.end() - 4, v.end());
            if (temp == hamburger) {
                answer++;
                v.erase(v.end() - 4, v.end());
            }
        }
    }

    return answer;
}

int main() {
    vector<int> ingredient = { 2, 1, 1, 2, 3, 1, 2, 3, 1 };
    int result = solution(ingredient);
    cout << result << '\n';
    return 0;
}