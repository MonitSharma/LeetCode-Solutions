class Solution 
{
    public ListNode mergeKLists(ListNode[] lists) 
    {
        ListNode aux=new ListNode(0);
        List<Integer>lisa=new ArrayList<Integer>();
        for(int i=0;i<lists.length;i++)
        {
            ListNode ptr=lists[i];
            while(ptr!=null)
            {
                lisa.add(ptr.val);
                ptr=ptr.next;
            }
        }
        Collections.sort(lisa);
        ListNode ptr=aux;
        for(int i=0;i<lisa.size();i++)
        {
            ListNode temp=new ListNode(lisa.get(i));
            temp.next=null;
            ptr.next=temp;
            ptr=ptr.next;
        }
        return aux.next;
    }
}
