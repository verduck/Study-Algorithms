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
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return addTwoListNode(l1, l2, 0);
    }

    ListNode* addTwoListNode(ListNode* l1, ListNode* l2, int carry) {
        if (l1 == nullptr && l2 == nullptr && carry == 0) {
            return nullptr;
        }
        int n = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
        return new ListNode(n % 10, addTwoListNode(l1 ? l1->next : l1, l2 ? l2->next : l2, n / 10));
    }
};

void init();

int main() {
    ListNode* l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
    ListNode* l2 = new ListNode(5, new ListNode(6, new ListNode(4)));

    init();

    Solution solution;
    ListNode* result = solution.addTwoNumbers(l1, l2);

    ListNode* temp = result;
    while (temp != nullptr) {
        cout << temp->val << ' ';
        temp = temp->next;
    }

    delete l1;
    delete l2;
    delete result;
}

void init() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}