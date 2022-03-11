#include <algorithm>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    sort(phone_book.begin(), phone_book.end());
    for (int i = 0; i < phone_book.size() - 1; i++) {
      string s1 = phone_book[i];
      string s2 = phone_book[i + 1].substr(0, s1.size());
      if (s1 == s2) {
        return false;
      }
    }
    
    return answer;
}

int main() {
    vector<string> phone_book = { "119", "97674223", "1195524421" };
    bool answer = solution(phone_book);
    cout << boolalpha << answer << '\n';
    return 0;
}