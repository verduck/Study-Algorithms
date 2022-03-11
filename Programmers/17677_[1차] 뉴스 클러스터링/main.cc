#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> create_element(const string& s) {
    vector<string> element;
    for (int i = 0; i < s.size() - 1; i++) {
        string sub = s.substr(i, 2);
        int alpha_num = count_if(sub.begin(), sub.end(), [](char c) -> bool {
            return isalpha(c);
        });
        if (alpha_num == 2) {
            element.push_back(sub);
        }
    }
    return element;
}

int solution(string str1, string str2) {
    int answer = 0;
    transform(str1.begin(), str1.end(), str1.begin(), ::toupper);
    transform(str2.begin(), str2.end(), str2.begin(), ::toupper);
    vector<string> element1 = create_element(str1);
    vector<string> element2 = create_element(str2);
    sort(element1.begin(), element1.end());
    sort(element2.begin(), element2.end());

    vector<string> uni;
    vector<string> inter;
    set_union(element1.begin(), element1.end(), element2.begin(), element2.end(), inserter(uni, uni.begin()));
    set_intersection(element1.begin(), element1.end(), element2.begin(), element2.end(), inserter(inter, inter.begin()));

    if (uni.size() == 0 && inter.size() == 0) {
        return 1 * 65536;
    }

    answer = static_cast<double>(inter.size()) / uni.size() * 65536;
    return answer;
}

int main(void) {
    string str1 = "FRANCE";
    string str2 = "french";
    int answer = solution(str1, str2);
    cout << answer << '\n';
    return 0;
}