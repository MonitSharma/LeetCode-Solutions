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
    public ListNode swapNodes(ListNode head, int k) {
        ListNode leftNode = head, rightNode = head;
        
        for (int i = 1; i < k; i++) {
            leftNode = leftNode.next;
        }
        
        ListNode current = leftNode;
        while (current.next != null) {
            current = current.next;
            rightNode = rightNode.next;
        }
        
        int temp = leftNode.val;
        leftNode.val = rightNode.val;
        rightNode.val = temp;
        
        return head;
    }
}