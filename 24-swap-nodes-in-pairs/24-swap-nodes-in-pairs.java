public class Solution {
    public ListNode swapPairs(ListNode head) {
        ListNode fakeHead = new ListNode(-1);
        fakeHead.next = head;
        ListNode node = fakeHead;
        while (node!=null & node.next != null && node.next.next!= null){
            ListNode first = node;
            ListNode second = node.next;
            ListNode third = node.next.next;
            first.next = third;
            second.next = third.next;
            third.next = second;
            node = second;
        }
        return fakeHead.next;
    }
}