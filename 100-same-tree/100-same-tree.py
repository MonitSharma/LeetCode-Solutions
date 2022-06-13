from itertools import zip_longest

class Solution:
    def isSameTree(self, p, q):
        """
        :type p: TreeNode
        :type q: TreeNode
        :rtype: bool
        """
        for p_val, q_val in zip_longest(preorder(p), preorder(q)):
            if p_val != q_val:
                return False
        return True
    
def preorder(tree):
        yield tree and tree.val
        if tree:
            for node in preorder(tree.left):
                yield node
            for node in preorder(tree.right):
                yield node