#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
    ListNode* front;
public:
    bool isPalindrome(ListNode* head) {
        front = head;
        return compareFromBack(head);
    }

    bool compareFromBack(ListNode* head) {
        if (head != nullptr) {
            if (!compareFromBack(head->next)) {
                return false;
            }
            if (front->val != head->val) {
                return false;
            }
            front = front->next;
        }

        return true;
    }
};

void init();

int main() {
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(2, new ListNode(1))));

    init();

    Solution solution;
    bool result = solution.isPalindrome(head);
    cout << boolalpha << result << '\n';
}

void init() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}