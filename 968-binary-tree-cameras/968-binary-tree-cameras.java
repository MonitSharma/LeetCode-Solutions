class Solution {
    private int ans = 0;
    public int minCameraCover(TreeNode root) {
        return dfs(root) > 2 ? ans + 1 : ans;
    }
    public int dfs(TreeNode node) {
        if (node == null) return 0;
        int val = dfs(node.left) + dfs(node.right);
        if (val == 0) return 3;
        if (val < 3) return 0;
        ans++;
        return 1;
    }
}