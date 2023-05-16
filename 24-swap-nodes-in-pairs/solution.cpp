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
  ListNode* swapPairs(ListNode* head) {
    const int length = getLength(head);
    ListNode dummy(0, head);
    ListNode* prev = &dummy;
    ListNode* curr = head;

    for (int i = 0; i < length / 2; ++i) {
      ListNode* next = curr->next;
      curr->next = next->next;
      next->next = prev->next;
      prev->next = next;
      prev = curr;
      curr = curr->next;
    }

    return dummy.next;
  }

 private:
  int getLength(ListNode* head) {
    int length = 0;
    for (ListNode* curr = head; curr; curr = curr->next)
      ++length;
    return length;
  }
};