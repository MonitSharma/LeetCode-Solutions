/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* leftNode = head;
        ListNode* rightNode = head;
        
        for (int i = 1; i < k; i++) {
            leftNode = leftNode->next;
        }
        
        ListNode* current = leftNode;
        while (current->next != nullptr) {
            current = current->next;
            rightNode = rightNode->next;
        }
        
        int temp = leftNode->val;
        leftNode->val = rightNode->val;
        rightNode->val = temp;
        
        return head;
    }
};