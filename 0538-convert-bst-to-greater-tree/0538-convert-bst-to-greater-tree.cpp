class Solution {
public:
    int sum = 0;

    void solve(TreeNode* root) {
        if (root == NULL)
            return;

        // Right
        solve(root->right);

        // Root
        sum += root->val;
        root->val = sum;

        // Left
        solve(root->left);
    }

    TreeNode* convertBST(TreeNode* root) {
        solve(root);
        return root;
    }
};