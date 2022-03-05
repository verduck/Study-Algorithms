#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    vector<int> nums;
    stringstream ss(s);
    while (getline(ss, answer, ' ')) {
        nums.push_back(stoi(answer));
    }
    
    const auto [min_it, max_it] = minmax_element(nums.begin(), nums.end());
    ss.str(string());
    ss.clear();
    ss << *min_it << ' ' << *max_it;
    answer = ss.str();
    return answer;
}

int main() {
    string s = "1 2 3 4";
    string answer = solution(s);
    cout << answer << '\n';
    return 0;
}