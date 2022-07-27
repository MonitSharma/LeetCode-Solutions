class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode *head = nullptr, *curr = root;
        while (head != root) {
            if (curr->right == head) curr->right = nullptr;
            if (curr->left == head) curr->left = nullptr;
            if (curr->right) curr = curr->right;
            else if (curr->left) curr = curr->left;
            else curr->right = head, head = curr, curr = root;
        }
    }
};