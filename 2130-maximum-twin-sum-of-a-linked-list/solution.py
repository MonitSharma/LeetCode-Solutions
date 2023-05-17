class Solution:
  def pairSum(self, head: Optional[ListNode]) -> int:
    def reverseList(head: ListNode) -> ListNode:
      prev = None
      while head:
        next = head.next
        head.next = prev
        prev = head
        head = next
      return prev

    ans = 0
    slow = head
    fast = head

    # Let slow point to the start of the second half
    while fast and fast.next:
      slow = slow.next
      fast = fast.next.next

    # Tail points to the end with reversed second half
    tail = reverseList(slow)

    while tail:
      ans = max(ans, head.val + tail.val)
      head = head.next
      tail = tail.next

    return ans
