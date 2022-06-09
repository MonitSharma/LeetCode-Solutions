class Solution {
    public boolean isValid(String s) {
        Stack<Character> stk=new Stack<>();
        for(char c:s.toCharArray())
        {
            if(c=='(' || c=='{' || c=='[')
            {
                stk.push(c);
            }else
            {
              
                if(stk.isEmpty()) return false;
                if(stk.peek()=='(' &&c!=')') return false;
                  if(stk.peek()=='[' &&c!=']') return false;
                  if(stk.peek()=='{' &&c!='}') return false;
                stk.pop();
            }
        }
        return stk.isEmpty();
    }
}