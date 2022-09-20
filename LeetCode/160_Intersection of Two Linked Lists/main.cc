#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* ptr1 = headA;
        ListNode* ptr2 = headB;

        while (ptr1 != ptr2) {
            if (ptr1 == nullptr) {
                ptr1 = headB;
            } else {
                ptr1 = ptr1->next;
            }

            if (ptr2 == nullptr) {
                ptr2 = headA;
            } else {
                ptr2 = ptr2->next;
            }
        }

        return ptr1;
    }
};

void init();

int main() {
    ListNode* headA = new ListNode(1);
    ListNode* headB = new ListNode(3);
    ListNode* inter = new ListNode(2);
    inter->next = new ListNode(4);
    headA->next = new ListNode(9);
    headA->next->next = new ListNode(1);
    headA->next->next->next = inter;
    headB->next = inter;

    init();

    Solution solution;
    ListNode* result = solution.getIntersectionNode(headA, headB);

    while (result != nullptr) {
        cout << result->val << ' ';
        result = result->next;
    }
    cout << '\n';
}

void init() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}