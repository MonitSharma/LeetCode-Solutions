/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
  public ListNode[] splitListToParts(ListNode root, int k) {
    ListNode[] ans = new ListNode[k];
    final int length = getLength(root);
    final int subLength = length / k;
    int remainder = length % k;

    ListNode prev = null;
    ListNode head = root;

    for (int i = 0; i < k; ++i, --remainder) {
      ans[i] = head;
      for (int j = 0; j < subLength + (remainder > 0 ? 1 : 0); ++j) {
        prev = head;
        head = head.next;
      }
      if (prev != null)
        prev.next = null;
    }

    return ans;
  }

  private int getLength(ListNode root) {
    int length = 0;
    for (ListNode curr = root; curr != null; curr = curr.next)
      ++length;
    return length;
  }
}