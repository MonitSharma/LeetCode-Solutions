# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def recursive_downward_traversal(self, node, k) : 
        # if you are at a null, or you are out of k, bounce out 
        if node is None or k < 0 : 
            return 
        # if k is 0 though
        if k == 0 : 
            # add to your results then bounce 
            self.node_val_list.append(node.val)
            return
        # otherwise, check your left and right and go with one less k for being here 
        # then bounce 
        self.recursive_downward_traversal(node.left, k-1)
        self.recursive_downward_traversal(node.right, k-1)
        return

    def recursive_helper(self, root, target, k) : 
        # if your root is None, return -1 
        if root is None : 
            return -1 
        # if root is target, do the downward traversal and return 0 
        if root is target : 
            self.recursive_downward_traversal(root, k)
            return 0 
        # otherwise, do discovery left 
        discovery_left = self.recursive_helper(root.left, target, k)
        # if you found it on your left 
        if discovery_left != -1 : 
            # if your result + 1 is k, add this to your listing 
            if discovery_left + 1 == k : 
                self.node_val_list.append(root.val)
            else : 
                # otherwise, recur downward on right with - 2 to account for coming up to here and down over to there 
                self.recursive_downward_traversal(root.right, k-discovery_left-2)
            # return 1 + discovery value at end (steps down you are at just in case of other locations needing this)
            return 1 + discovery_left
        # otherwise, do discovery right on fail on left 
        discovery_right = self.recursive_helper(root.right, target, k) 
        # if you got something 
        if discovery_right != -1 : 
            # check if this is to be added or recurred through 
            if discovery_right + 1 == k : 
                self.node_val_list.append(root.val)
            else : 
                self.recursive_downward_traversal(root.left, k - discovery_right - 2)
            # return for next level up recurrence 
            return 1 + discovery_right
        # if you didn't return on left, or on right, you need to return -1, means it was never found. 
        return -1 


    def distanceK(self, root: TreeNode, target: TreeNode, k: int) -> List[int]:
        # edge case on root and target 
        if root is None or target is None : 
            return []
        else : 
            # otherwise, set node list 
            self.node_val_list = []
            # catch your overall result 
            result = self.recursive_helper(root, target, k)
            # if it is -1, no target in tree, empty list
            if result == -1 : 
                return []
            else : 
                # otherwise, return built list 
                return self.node_val_list