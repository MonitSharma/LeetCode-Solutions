# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapNodes(self, head: ListNode, k: int) -> ListNode:
       
        left_node = head
        for i in range(1, k):
            left_node = left_node.next
        
       
        right_node = head
        current = left_node
        while current.next:
            current = current.next
            right_node = right_node.next
        
     
        left_node.val, right_node.val = right_node.val, left_node.val
        
        return head