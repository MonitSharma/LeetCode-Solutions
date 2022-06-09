class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        
        ListNode result = new ListNode();
        ListNode head = result;
        while(l1!=null && l2!=null){
            if(l1.val<l2.val){
               result.next = l1;
               l1 = l1.next;
            }else{
              result.next = l2;
              l2 = l2.next;
            }
            
            result = result.next;
        }       
        
        if(l1!=null){
            result.next=l1;
        }else{
            result.next=l2;
        }
        
        return head.next;
    }
}