bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (p == NULL && q == NULL) {
        return true;
    } else if ((p == NULL && q != NULL) || (p != NULL && q == NULL)) {
        return false;
    }
    if (p->val == q->val) {
        if (isSameTree(p->left , q->left) && isSameTree(p->right, q->right)) {
            return true;
        }
    }
    return false;
}