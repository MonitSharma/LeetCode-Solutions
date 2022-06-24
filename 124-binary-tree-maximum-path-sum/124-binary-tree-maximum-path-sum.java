class Solution {
    int maxSum = Integer.MIN_VALUE;
    public int maxPathSum(TreeNode root) {
        if (root == null) return 0;
        helper(root);
        return maxSum;
    }
    int helper(TreeNode root) {
        if (root == null) return 0;
        int leftPath = Math.max(helper(root.left), 0);
        int rightPath = Math.max(helper(root.right), 0);

        maxSum = Math.max(maxSum, root.val + leftPath + rightPath);
        return root.val + Math.max(leftPath, rightPath);
    }
}