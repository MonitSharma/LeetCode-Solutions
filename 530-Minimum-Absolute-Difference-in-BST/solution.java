class Solution {
    public int getMinimumDifference(TreeNode root) {
        Stack<TreeNode> stack = new Stack<>();
        TreeNode curr = root;
        Integer prevVal = null;
        int minDiff = Integer.MAX_VALUE;
        
        while (!stack.isEmpty() || curr != null) {
            while (curr != null) {
                stack.push(curr);
                curr = curr.left;
            }
            
            curr = stack.pop();
            
            if (prevVal != null) {
                minDiff = Math.min(minDiff, Math.abs(curr.val - prevVal));
            }
            
            prevVal = curr.val;
            curr = curr.right;
        }
        
        return minDiff;
    }
}