class Solution:
    def buildTree(self, P: List[int], I: List[int]) -> TreeNode:
        M = {I[i]: i for i in range(len(I))}
        return self.splitTree(P, M, 0, 0, len(P)-1)

    def splitTree(self, P: List[int], M: dict, pix: int, ileft: int, iright: int) -> TreeNode:
        rval = P[pix]
        root, imid = TreeNode(rval), M[rval]
        if imid > ileft:
            root.left = self.splitTree(P, M, pix+1, ileft, imid-1)
        if imid < iright:
            root.right = self.splitTree(P, M, pix+imid-ileft+1, imid+1, iright)
        return root