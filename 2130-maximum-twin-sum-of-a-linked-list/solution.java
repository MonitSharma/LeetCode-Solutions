class Solution {
  public int pairSum(ListNode head) {
    int ans = 0;
    ListNode slow = head;
    ListNode fast = head;

    // Let slow point to the start of the second half
    while (fast != null && fast.next != null) {
      slow = slow.next;
      fast = fast.next.next;
    }

    // Tail points to the end with reversed second half
    ListNode tail = reverseList(slow);

    while (tail != null) {
      ans = Math.max(ans, head.val + tail.val);
      head = head.next;
      tail = tail.next;
    }

    return ans;
  }

  private ListNode reverseList(ListNode head) {
    ListNode prev = null;
    while (head != null) {
      ListNode next = head.next;
      head.next = prev;
      prev = head;
      head = next;
    }
    return prev;
  }
}
