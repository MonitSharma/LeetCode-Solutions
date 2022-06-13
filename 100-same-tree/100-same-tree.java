class Solution {
    public boolean isSameTree(TreeNode p, TreeNode q) {
        if(p != null && q != null && q.val == p.val) {
            return isSameTree(p.left, q.left) && isSameTree(p.right, q.right);
        }
        return p == null && q == null;
    }
}