class Solution {
    public int goodNodes(TreeNode root) {
        return helper(root, root.val);
        
    }

    public int helper(TreeNode node, int curMax){
        if(node == null) return 0;
        int cur = 0;
        if(node.val>=curMax){
            cur++;
            curMax = Math.max(curMax, node.val);
        }
        cur += helper(node.left, curMax);
        cur += helper(node.right, curMax);
        return cur;
    }
}
// @lc code=end