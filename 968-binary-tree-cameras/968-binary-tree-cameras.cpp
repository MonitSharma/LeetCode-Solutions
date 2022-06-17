class Solution {
public:
    int minCameraCover(TreeNode* root) {
        return dfs(root) > 2 ? ans + 1 : ans;
    }
    int dfs(TreeNode* node) {
        if (!node) return 0;
        int val = dfs(node->left) + dfs(node->right);
        if (val == 0) return 3;
        if (val < 3) return 0;
        ans++;
        return 1;
    }
private:
    int ans = 0;
};