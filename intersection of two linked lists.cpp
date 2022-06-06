class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a = headA, *b = headB;
        while (a != b) {
            a = !a ? headB : a->next;
            b = !b ? headA : b->next;
        }
        return a;
    }
};
