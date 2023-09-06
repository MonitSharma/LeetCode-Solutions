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
  vector<ListNode*> splitListToParts(ListNode* root, int k) {
    vector<ListNode*> ans(k);
    const int length = getLength(root);
    const int subLength = length / k;
    int remainder = length % k;

    ListNode* prev = nullptr;
    ListNode* head = root;

    for (int i = 0; i < k; ++i, --remainder) {
      ans[i] = head;
      for (int j = 0; j < subLength + (remainder > 0); ++j) {
        prev = head;
        head = head->next;
      }
      if (prev != nullptr)
        prev->next = nullptr;
    }

    return ans;
  }

 private:
  int getLength(ListNode* root) {
    int length = 0;
    for (ListNode* curr = root; curr; curr = curr->next)
      ++length;
    return length;
  }
};