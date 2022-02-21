#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

int solution(string word) {
    int answer = 0;
    const unordered_map<char, int> alphabets = {
        { 'A', 0 },
        { 'E', 1 },
        { 'I', 2 },
        { 'O', 3 },
        { 'U', 4 },
    };
    const int NUMBER_OF_ALPHABETS = alphabets.size();
    int end_of_words = 0;

    for (int i = 1; i <= NUMBER_OF_ALPHABETS; i++) {
        end_of_words += pow(NUMBER_OF_ALPHABETS, i);
    }

    for (int i = 0; i < word.size(); i++) {
        int n = end_of_words / pow(NUMBER_OF_ALPHABETS, i + 1);
        n *= alphabets.at(word[i]);
        answer += ++n;
    }
    return answer;
}

int main() {
    string word = "AAAAE";
    int result = solution(word);
    cout << result << '\n';
    return 0;
}