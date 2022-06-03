var searchBST = function (root, val) {

    // We have reached a leaf node
    // This mean's we never found the
    // node we was looking for.
    if (!root) {
        return null;
    }

    // We found the node we're looking for
    // Return it.
    if (root.val === val) {
        return root;
    }

    // The 2 parts below only make sense if you understand
    // Binary Search Trees. It helps if you understand divide and conquer algorithms.
    // Like Binary search.

    // So we know the value we're looking for
    // if greater than the current node, thus
    // the node we're looking for is somewhere on the right tree
    if (val > root.val) {
        return searchBST(root.right, val);
    }

    // So the value we're searching for is less than the current node
    // which means the node we're looking for exists somewhere on
    // the left side.
    if (val < root.val) {
        return searchBST(root.left, val);
    }
};
