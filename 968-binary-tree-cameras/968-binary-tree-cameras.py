class Solution:
    ans = 0
    def minCameraCover(self, root: TreeNode) -> int:
        def dfs(node: TreeNode) -> int:
            if not node: return 0
            val = dfs(node.left) + dfs(node.right)
            if val == 0: return 3
            if val < 3: return 0
            self.ans += 1
            return 1
        return self.ans + 1 if dfs(root) > 2 else self.ans