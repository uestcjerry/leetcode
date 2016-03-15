#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode * addTwoNumbers(ListNode * l1, ListNode * l2);
};
ListNode * Solution::addTwoNumbers(ListNode * l1, ListNode * l2)
{
    ListNode *current = new ListNode(0);
    ListNode *result = current;

    for (int flag = 0; l1 != NULL || l2 != NULL; ) {
        current->val += (l1 != NULL ? l1->val : 0) + (l2 != NULL ? l2->val : 0);
        
        if (l1)
            l1 = l1->next;
        if (l2)
            l2 = l2->next;
        flag = current->val / 10;
        current->val = current->val % 10;

        if (l1 || l2 || flag > 0) {
            current->next = new ListNode(flag);
            current = current->next;
        }
    }
    return result;
}
