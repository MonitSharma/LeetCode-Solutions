class Solution {
    public int longestValidParentheses(String S) {
        Stack<Integer> stack = new Stack<>();
        stack.push(-1);
        int ans = 0;
        for (int i = 0; i < S.length(); i++)
            if (S.charAt(i) == '(') stack.push(i);
            else {
                stack.pop();
                if (stack.isEmpty()) stack.push(i);
                else ans = Math.max(ans, i - stack.peek());
            }
        return ans;
    }
}